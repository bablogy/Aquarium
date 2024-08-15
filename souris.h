/************************************/
/*   		    youssef baba            */
/*   		    mesnawi@me.com          */
/*	https://twitter.com/babristor   */
/************************************/


#include <dos.h>

#define SNB_BOUTONS 3
#define SGAUCHE 0
#define SDROITE 1
#define SMILLIEU 2

typedef int gpixel;

static int sinstal=0; /* boolean : dit si la souris est actuellement installee
(sinon les procedures ne font rien ou rendent 0) */

typedef int /*boolean*/ st_boutons[SNB_BOUTONS];
/* dans l'ordre, sur PC : bouton gauche,droite,centre */

/* COUCHE 0, dependant de la machine *******************************/

/*procedures directement utilisables par l'utilisateur*/
/*----------------------------------------------------*/

void sinit(int *nb_bts)
// initialise la souris, retourne le nb de boutons (en géné 2 ou 3)
{
union REGS rin, rout;
rin.h.ah = 0x00;
rin.h.al = 0x00;
int86(0x33, &rin, &rout);
if (rout.x.ax!=0) *nb_bts=rout.x.bx; else *nb_bts=0;
sinstal=(*nb_bts>0);
}

void smontre_curs(void)
// montre le curseur de la souris
{
union REGS rin;
if (sinstal)
{
rin.x.ax=1;
int86(0x33, &rin, &rin);
}
}

void scache_curs(void)
// avant tout tracé, il faut cacher le curseur (et le remontrer ensuite)
{
union REGS rin;
if (sinstal)
{
rin.x.ax=2;
int86(0x33, &rin, &rin);
}
}

/*procedures de bas niveau, en coord souris*/
/*-----------------------------------------*/

void sbread(st_boutons b,gpixel *x,gpixel *y)
//rend la position de la souris et l'état des boutons
{
int i;
union REGS rin, rout;
rin.x.ax=3;
int86(0x33,&rin,&rout);
for (i=0;i<SNB_BOUTONS;i++) b[i]=((rout.x.bx &(1 << i))!=0);
x=rout.x.cx;
y=rout.x.dx;

}

void sbposit_curs(gpixel x,gpixel y)
/*il vaut mieux que le curseur soit cache*/
{
union REGS rin,rout;
rin.x.ax=4;
rin.x.cx=x;
rin.x.dx=y;
int86(0x33,&rin,&rout);
}

void sbbornes(gpixel xmin,gpixel xmax,gpixel ymin,gpixel ymax)
//limite la partie de l'écran dans laquelle la souris peut se déplacer
{
union REGS rin,rout;
rin.x.ax=7;
rin.x.cx=xmin;
rin.x.dx=xmax;
int86(0x33,&rin,&rout);
rin.x.ax=8;
rin.x.cx=ymin;
rin.x.dx=ymax;
int86(0x33,&rin,&rout);
}

/*specifique PC */
/*en TP3, utiliser INTEGER au lieu de WORD*/
struct st_curseur
{
unsigned short fond[16]; /* 0 met en noir, 1 laisse pareil */
unsigned short sur[16]; /* 0 laisse pareil, 1 inverse */
unsigned short x,y; /* centre du curseur (entre 0 et 15) */
};
/* definition du cureur, 16*16 pixels graphiques */

/* je l'utilise en particulier pour scroix */
void scurs_graph(struct st_curseur *c)
{
struct REGPACK rin;
if (sinstal)
{
rin.r_es=FP_SEG(c);
rin.r_dx=FP_OFF(c);
rin.r_bx=c->x;
rin.r_cx=c->y;
rin.r_ax=9;
intr(0x33,&rin);
}
}

void scurs_text_ligne(int deb,int fin)
//pour le mode texte, normalement inutile
{
union REGS rin,rout;
if (sinstal)
{
rin.x.dx=fin;
rin.x.cx=deb;
rin.x.bx=1;
rin.x.ax=10;
int86(0x33,&rin,&rout);
}
}

void scurs_text_char(int fond,int curs)
//pour le mode texte, normalement inutile
{
union REGS rin,rout;
if (sinstal)
{
rin.x.dx=curs;
rin.x.cx=fond;
rin.x.bx=0;
rin.x.ax=10;
int86(0x33,&rin,&rout);
}
}

void sattend_lache(void)
/*attend uniquement que tous les boutons soient laches*/
{
gpixel ix,iy;
st_boutons ib;
if (sinstal)
{
ib[0]=0;ib[1]=0;ib[2]=0;
do sbread(ib,&ix,&iy); while(ib[0] || ib[1] || ib[2]);
}
}

void sattend(st_boutons b,gpixel *x,gpixel *y)
/*verifie que les boutons de la souris sont laches. Puis a l'appui
d'un bouton, memorise l'etat de la souris*/
{
gpixel ix,iy;
st_boutons ib;
if (sinstal)
{
ib[1]=0;ib[2]=0;ib[0]=0;
do sbread(ib,&ix,&iy); while(ib[0] || ib[1] || ib[2]);
do sbread(b,x,y); while((!b[0]) && (!b[1]) && (!b[2]));
/* on peut a la rigueur attendre le relachement du bouton (mais sans
prendre en compte une modification de position, c'est inutile si on
ne fait que des sattend
do sread(ib,&ix,&iy); while(ib[0] || ib[1] || ib[2]);
/

}
else
{
b[1]=0;b[2]=0;b[0]=0;*x=0;*y=0;
}
}

void scroix(void) /*met un curseur croix*/
{
struct st_curseur cur;
if (sinstal)
{
cur.fond[0]=0xFFFF;
cur.fond[1]=0xFC7F;
cur.fond[2]=0xFC7F;
cur.fond[3]=0xFC7F;
cur.fond[4]=0xFC7F;
cur.fond[5]=0xFC7F;
cur.fond[6]=0x00;
cur.fond[7]=0x00;
cur.fond[8]=0x00;
cur.fond[9]=0xFC7F;
cur.fond[10]=0xFC7F;
cur.fond[11]=0xFC7F;
cur.fond[12]=0xFC7F;
cur.fond[13]=0xFC7F;
cur.fond[14]=0xFFFF;
cur.fond[15]=0xFFFF;

cur.sur[0]=0x00;
cur.sur[1]=0x00;
cur.sur[2]=0x0100;
cur.sur[3]=0x0100;
cur.sur[4]=0x0100;
cur.sur[5]=0x0100;
cur.sur[6]=0x0100;
cur.sur[7]=0x7FFE;
cur.sur[8]=0x0100;
cur.sur[9]=0x0100;
cur.sur[10]=0x0100;
cur.sur[11]=0x0100;
cur.sur[12]=0x0100;
cur.sur[13]=0x00;
cur.sur[14]=0x00;
cur.sur[15]=0x00;

cur.x=7;
cur.y=7;
scurs_graph(&cur);
}
}
