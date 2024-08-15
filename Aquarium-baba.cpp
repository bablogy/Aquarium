
/************************************/
/*   		    youssef baba            */
/*   		    mesnawi@me.com          */
/*	https://twitter.com/babristor   */
/************************************/

#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include<conio.h>
#include "souris.h"
////////////////////////////////////////////////////////////////////////
int hauteur=0;
int nb=0;
int nr=0;
char * msg;
//////////////////////////////////////////////////////////////////////////
	   /***** initialisation du mode ghraphique *****/
//////////////////////////////////////////////////////////////////////////
void inite()
{ int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:/tc/bgi");
}
/////////////////////////////////////////////////////////////////////////
	 /******            le poisson logo          *******/
/////////////////////////////////////////////////////////////////////////
void logo(int x=getmaxx()/2,int y=getmaxy()/2)
{  int xp, yp, v,vv,c=6,d=14,e=11;
   xp=x-200;  yp=y-100;
	  /*-------------------------------------------------*/
   setcolor(c); setfillstyle(1,7);    // grand cercle de la queue
   fillellipse(xp-75,yp+18,7,7);
	  /*--------------------------------------------------*/
   setcolor(c); setfillstyle(1,1);      // petit cercle de la queue
   v=2; fillellipse(xp-75,yp+18,v,v);
	 /*----------------------------------------------------*/
   setcolor(c); setfillstyle(1,8);       // queue
	 /*----------------------------------------------------*/
   arc(xp-81,yp+1,190,300,10);
   arc(xp-81,yp+35,80,154,10);
   arc(xp-101,yp+18,-45,47,16);
	 /*----------------------------------------------------*/
   setfillstyle(1,8);    // couleur du queue
   floodfill(xp-83,yp+13,c);
	 /*---------------------------------------------------*/
   arc(xp, yp,180,280,30);
   line(xp-69,yp+32,xp+5,yp+32); line(xp-36,yp+12,xp-30,yp);
   line(xp-36,yp+12,xp-38,yp-2); line(xp-46,yp+12,xp-38,yp-2);
   line(xp-46,yp+12,xp-50,yp+2); line(xp-67,yp+2 ,xp-50,yp+2);
	/*----------------------------------------------------*/
   setfillstyle(1,c);  /* petit cercle de la bouche   */
   fillellipse(xp+5,yp+31,0,0);
       /*---------------------------------------------------*/
   circle(xp-67,yp+27,5);     /* cercle de bat  */
   circle(xp-67,yp+8,5);      /* cercle de haut */
   setfillstyle(1,11);
   floodfill(xp-67,yp+26,c); floodfill(xp-67,yp+8,c);
   setfillstyle(1, d); floodfill(xp-60,yp+30,c);
      /*------------------ l'oeil -----------------------*/
   setcolor(c);setfillstyle(1,7);fillellipse(xp-17,yp+26,6,6);
   setcolor(9);setfillstyle(1,0);fillellipse(xp-17,yp+26,3,3);
   setcolor(0); setfillstyle(1,0);
      /*---------------- cercle de bat noir ---------- */
    vv=2;
   fillellipse(xp-67,yp+27,vv,vv);
    /*---------------- cercle de haut noir ----------*/
   fillellipse(xp-67,yp+8,vv,vv);
      /*--------------- les arcs du corps------------*/
   setcolor(e); arc(xp-36,yp+26,80,140,16);
   arc(xp-54,yp+7,230,300,10);  arc(xp-52, yp+33,80,140,10);
   arc(xp-39, yp+11,230,310,16); arc(xp-20,yp+27,100,220,6);
	 /*---------------------------------------*/
   setcolor(c); setfillstyle(1,0);
   line(xp-36,yp+36,xp-30,yp+31);  line(xp-36,yp+36,xp-18,yp+31);
   line(xp-43,yp+36,xp-18,yp+31);  line(xp-43,yp+36,xp-32,yp+31);
   line(xp-40,yp+36,xp-40,yp+31);
      /*------------------------------------------*/
   putpixel(xp-30,yp+33,c);  putpixel(xp-31,yp+33,c);
   putpixel(xp-32,yp+33,c);  putpixel(xp-33,yp+33,c);
   putpixel(xp-34,yp+33,c);  putpixel(xp-35,yp+33,c);
   putpixel(xp-35,yp+34,c);  putpixel(xp-36,yp+34,c);
   putpixel(xp-37,yp+34,c);  putpixel(xp-38,yp+33,c);
   putpixel(xp-39,yp+33,c);  setcolor(0);
   outtextxy(x-260,y-84,"ENSA"); setcolor(1); setlinestyle(0,4,3);
   rectangle(0,0,getmaxx(),getmaxy());
 }
///////////////////////////////////////////////////////////////////////////
		/****** classe planctan ************/
///////////////////////////////////////////////////////////////////////////
class Plancton
 { private:
   int age;
   public:
   Plancton(){age=0;}
   void draw_plancton();
 };
void Plancton::draw_plancton()
{ int Xe,Ye,c,dx,maxXe,maxYe,nbr=0,test;
  setlinestyle(0,0,0);
  maxXe=600;maxYe=390;
  for (Xe=200;Xe<=maxXe;Xe++) putpixel(Xe,maxYe,7);
  if(nbr<3000){
  c=6;Xe=maxXe/2;Ye=300;nbr++; putpixel(Xe,Ye,1);
  do{
  dx=random(3)-1;
  if ((test=getpixel(Xe+dx,Ye+1))==0){
  putpixel(Xe,Ye,0);Xe=Xe+dx;Ye++;putpixel(Xe,Ye,c);}}
  while((!test)&&(Xe<maxXe)&&(Xe>0));
}
  /*********************************************************************/
  maxXe=600;maxYe=390;
  for (Xe=400;Xe<=maxXe;Xe++) putpixel(Xe,maxYe,7);
  if(nb<3000){
  c=-3+15*sin(nb);Xe=maxXe/2;Ye=120;nb++; putpixel(Xe,Ye,1);
  do{
  dx=random(10)-4;
  if ((test=getpixel(Xe+dx,Ye+1))==0){
  putpixel(Xe,Ye,0);Xe=Xe+dx; Ye++; putpixel(Xe,Ye,c);}}
  while((!test)&&(Xe<maxXe)&&(Xe>0));}
  /***********************************************************************/
  maxXe=600;maxYe=300;
  if(nr<1500){
  c=2;Xe=maxXe/2;Ye=220;nr++;putpixel(Xe,Ye,1);
  do{
  dx=random(7)-1;
  if ((test=getpixel(Xe+dx,Ye+1))==0){
  putpixel(Xe,Ye,0);Xe=Xe+dx;Ye++;putpixel(Xe,Ye,c);}}
  while((!test)&&(Xe<maxXe)&&(Xe>0));
	}
 }
 ////////////////////////////////////////////////////////////////////////
	     /******  classe Aquarium ******************/
 /////////////////////////////////////////////////////////////////////////
class Aquarium
 { int s,v;
   int hsv;
   char msg[50];
   public:
   void draw_aqua(int );
   void draw_boule();
   void clear_boule();
   void draw_decors();
 };
 /********************************************************************/
void Aquarium::draw_decors()
{  setcolor(0);
   setlinestyle(0,0, 0);
   rectangle(142,98,143,102);
   setfillstyle(6,-4);fillellipse(200,368,15,12);
   setfillstyle(9,6);fillellipse(268,379,17,10);
   setfillstyle(6,-2);fillellipse(240,367,35,20);
   setfillstyle(9,7);fillellipse(230,370,20,10);
   setfillstyle(6,8);fillellipse(208+15,378,20,10);
   setfillstyle(9,7);fillellipse(220,366,15,10);
   setfillstyle(6,7);fillellipse(203,378,15,11);
   setfillstyle(9,3);fillellipse(165+10,378,19,10);
   setfillstyle(6,8);fillellipse(178+10,375,10,14);
   setfillstyle(9,8);fillellipse(246,381,14,8);
}
/**************************************************************************/
void Aquarium::draw_aqua(int c_in)
{
   setbkcolor(c_in);
   _strdate(msg);
   setcolor(-4);
   outtextxy(5,30,msg);
   setcolor(7);
   setlinestyle(0,4, 3);
   rectangle(145,100,getmaxx()-32, getmaxy()-90);
   rectangle(90,getmaxy()-90,145,100);
   rectangle(140,100,145,getmaxy()-92);
     /*-----------------------------------------------*/
   setcolor(8);
   setlinestyle(0,4,3);
   setfillstyle(1,12);
   rectangle(125,420,285,450);
   rectangle(312,420,462,450);
   rectangle(490,420,560,450);
   floodfill(230,440,8);
   floodfill(382,440,8);
   floodfill(515,440,8);
   outtextxy(125,433," Etat de l'aquarium");
   outtextxy(318,433," Revenir au menu ");
   outtextxy(490,433," Quitter ");
 /*---------------------------------------------------------------------*/
   setcolor(0);
   setlinestyle(0,4, 3);
   setfillstyle(1,0);
   fillellipse(143,getmaxy()-95,5,2);
   setlinestyle(0,0,0);

}
/*************************************************************************/
void Aquarium::draw_boule()
{  int nbl=30;
  if(hauteur<(getmaxy()-200)){
   setcolor(11);
   setfillstyle(1,11);
   if(hauteur<(getmaxy()-220)){
   hsv=getmaxy()-hauteur-105;
   s=(int)(117+13*sin(hauteur*0.03));
   v=(int)(117-13*sin(hauteur*0.03));
   circle(s,hsv,2+hauteur/50);
   floodfill(s,hsv,11);
   if(hauteur>=nbl) {
   circle(v,hsv+nbl,2+(hauteur-nbl)/50);
   floodfill(v,hsv+nbl,11); }
   if(hauteur>=2*nbl) {
   circle(s,hsv+2*nbl,2+(hauteur-2*nbl)/50);
   floodfill(s,hsv+2*nbl,11); }
   if(hauteur>=3*nbl) {
   circle(v,hsv+3*nbl,2+(hauteur-3*nbl)/50);
   floodfill(v,hsv+3*nbl,11); }
   if(hauteur>=4*nbl) {
   circle(s,hsv+4*nbl,2+(hauteur-4*nbl)/50);
   floodfill(s,hsv+4*nbl,11); }
   if(hauteur>=5*nbl) {
   circle(v,hsv+5*nbl,2+(hauteur-5*nbl)/50);
   floodfill(v,hsv+5*nbl,11); }
   if(hauteur>=6*nbl) {
   circle(s,hsv+6*nbl,2+(hauteur-6*nbl)/50);
   floodfill(s,hsv+6*nbl,11); }
   if(hauteur>=7*nbl) {
   circle(v,hsv+7*nbl,2+(hauteur-7*nbl)/50);
   floodfill(v,hsv+7*nbl,11); }  }
 }
}
/***************************************************************************/
void Aquarium::clear_boule()
 { int nbl=30;
   setcolor(0);
   setfillstyle(1,0);
   floodfill(s,hsv,0);

   if(hauteur>=nbl) {floodfill(v,hsv+nbl,0);}
   if(hauteur>=2*nbl)floodfill(s,hsv+2*nbl,0);
   if(hauteur>=3*nbl)floodfill(v,hsv+3*nbl,0);
   if(hauteur>=4*nbl)floodfill(s,hsv+4*nbl,0);
   if(hauteur>=5*nbl)floodfill(v,hsv+5*nbl,0);
   if(hauteur>=6*nbl)floodfill(s,hsv+6*nbl,0);
   if(hauteur>=7*nbl)floodfill(v,hsv+7*nbl,0);

 }
////////////////////////////////////////////////////////////////////////////
	      /************* classe Poisson ************/
/////////////////////////////////////////////////////////////////////////////
class Poisson
 { int yp;
   int gm;
   int t_o;          // oscillation du poisson
   int  poly1[8],coly1[6],toly[8];  // pour la queue
   int color;

   public:

   int xp;
   int x_n;
   int age;           // Age d'un poisson
		     // constructeur inline
   Poisson(int y,int eat,int couleur=-4)
   { yp=getmaxy()/2-y;x_n=1;gm=eat;color=couleur;age=0; }
   void draw_poisson(int );
   void dessin(int,int,int,int,int);
   void clear(int);
   void clear_poisson(int);
   void eat_poisson(int,int);
   void clear_eat(int,int);
};
  /*********************************************************************/
void Poisson::dessin(int eta=1,int c1=-2,int c2=-3 ,int c3=-3,int c4=3)
{  if(eta==1){t_o=14*sin(xp*0.05);
   poly1[0] = 65+xp-age ;
   poly1[1] = yp+t_o;
   poly1[2] = poly1[0] - 10+3*sin(xp/2)+2-age ;
   poly1[3] = poly1[1] + 10-age;
   poly1[4] = poly1[0] - 5+3*sin(xp/2)+1-age ;
   poly1[5] = poly1[1]-age;
   poly1[6] = poly1[0] -10+3*sin(xp/2)+2-age;
   poly1[7] = poly1[1] -10-age;
      /*-------------------------------------------------------*/
   toly[0] = 65+xp -age;
   toly[1] = yp+t_o;
   toly[2] = toly[0] - 8+3*sin(xp/2)+2-age ;
   toly[3] = toly[1] + 8-age;
   toly[4] = toly[0] - 3+sin(xp/2)+1-age ;
   toly[5] = toly[1]-age;
   toly[6] = toly[0] -8+3*sin(xp/2)+2-age;
   toly[7] = toly[1] -8-age;
     /*--------------------------------------------------------*/
   coly1[0] = 88+xp ;
   coly1[1] = (int)t_o +yp-8-age ;
   coly1[2] =  coly1[0] - 10 -3*fabs(sin(xp/20));
   coly1[3] =  coly1[1] - 7-age;
   coly1[4] =  coly1[0] - 7;
   coly1[5] =  coly1[1] ;
    /*----------------------------------------------------------*/
   setcolor(0);       // queue
   setfillstyle(1,c4);
   fillpoly(4, poly1);
   setfillstyle(1,c3);
   fillpoly(4, toly);
    /*---------------------------------------------------------*/
   setfillstyle(1,c1); // poisson
   fillellipse(86+xp,(int)t_o+yp+1,20+age,10+age);
   setcolor(c2);
   arc(xp+101,(int)t_o+yp+2,120,210,9+age);
   arc(xp+101,(int)t_o+yp+2,130,200,11+age);
   arc(xp+101,(int)t_o+yp+2,150,190,13+age);
    /*----------------------------------------------------------*/
   setcolor(0);setfillstyle(1,0); // bouche
   fillellipse(101+xp-age/2,(int)t_o+yp+6+age,(age/2+3)*t_o/20,age/2);
   /*------------------------------------------------------------*/
   setcolor(0);      //za3nafa
   setfillstyle(1,c4);
   fillpoly(3, coly1);
   /*-----------------------------------------------------------*/
   setcolor(6);       //  oeil rouge
   circle(100+xp+age/2,(int)t_o+yp-1,2+age/2);
   setfillstyle(1,4);
   floodfill(100+xp+age/2,(int)t_o +yp,6);
   /*-----------------------------------------------------------*/
   setcolor(0);      // boIboI
   setfillstyle(1,0);
   circle(100+xp+age/2,(int)t_o+yp,age/2);
   floodfill(100+xp+age/2,(int)t_o +yp,0);}
}
 /********************************************************************/
void Poisson::clear(int eta)
{ if(eta==1){
  setcolor(0);
  arc(101+xp,(int)t_o+yp+2,120,210,9+age);
  arc(xp+101,(int)t_o+yp+2,130,200,11+age);
  arc(xp+101,(int)t_o+yp+2,150,190,13+age);
  setfillstyle(1,0);
  floodfill(coly1[0]-2,coly1[1]-1,0);
  fillellipse(86+xp,(int)t_o+yp+1,20+age,10+age);
  floodfill(poly1[0]-2,poly1[1],0);}
}
/*********************************************************************/
void Poisson::eat_poisson(int eta,int y=0)
{ if(eta==1){
  if(xp<gm && xp>gm-39){
  setcolor(7);setlinestyle(0,4,3);
  line(145,186+y,155,176+y);line(145,194+y,155,184+y);
  setcolor(color);
  line(145,189+y,154,180+y); line(145,191+y,154,182+y);
  setlinestyle(0,0,0); setcolor(0);setfillstyle(1,color);
  fillellipse(157+x_n,180-x_n+y,3,3);}
  if(xp<gm-39) {  setcolor(0);setlinestyle(0,4,3);
  line(145,186+y,155,176+y); line(145,194+y,155,184+y);
  setcolor(0);line(145,189+y,154,180+y); line(145,191+y,154,182+y);
  setcolor(7);line(145,180+y,145,200+y);setlinestyle(0,0,0);}}
}
/*********************************************************************/
void Poisson::draw_poisson(int eta)
{ if(eta==1){
  t_o=12*sin(xp*0.05);
  poly1[0] = xp-106+age ;
  poly1[1] = yp-90+t_o;
  poly1[2] = poly1[0] + 10+3*sin(xp/2)+age ;
  poly1[3] = poly1[1] + 10+age;
  poly1[4] = poly1[0] +5+3*sin(xp/2)+1+age ;
  poly1[5] = poly1[1] +age;
  poly1[6] = poly1[0] +10+3*sin(xp/2)+age;
  poly1[7] = poly1[1] -10+age;
  coly1[0] = xp-122+age ;
  coly1[1] = t_o+yp-99-age ;
  coly1[2] = coly1[0] + 7 -3*fabs(sin(xp/10));
  coly1[3] = coly1[1] -7;
  coly1[4] = coly1[0] -7;
  coly1[5] = coly1[1]+1 ;
      /*-------------------------------------------------------*/
  setcolor(0);         // queue
  setfillstyle(1, 15);fillpoly(4, poly1);
      /*--------------------------------------------------------*/
  setfillstyle(1,color);  // poisson
  fillellipse(xp-126,(int)t_o+yp-89,20+age,10+age);
     /*---------------------------------------------------------*/
  setcolor(color);setfillstyle(1,15);  // khorchofa j
  fillellipse(xp-122+age,(int)t_o+yp-89,9+age, 3+age);
     /*---------------------------------------------------------*/
  setfillstyle(1,color);     // fogha
  fillellipse(xp-118+age,(int)t_o+yp-89 ,5+age, 7-5*fabs(sin(xp*0.5))+age);
     /*---------------------------------------------------------*/
  setcolor(0);setfillstyle(1,0);  // bouche
  fillellipse(-141-age/2+xp,(int)t_o+yp-84+age,(age/2+3)*sin(xp/13),0+age/2);
     /*------------------------------------------------------------*/
  setcolor(0);         //za3nafa
  setfillstyle(1,15);fillpoly(3, coly1);
    /*-------------------------------------------------------------*/
   setcolor(6);          //  oeil bleue
   circle(-140-age/2+xp,(int)t_o+yp-91,2+age/2);
   setfillstyle(1,9);
   floodfill(-140-age/2+xp,(int)t_o+yp-90,6);
     /*-------------------------------------------------------------*/
   setcolor(0);          // boIboI
   setfillstyle(1,0);
   circle(-140-age/2+xp,(int)t_o+yp-90,age/2);
   floodfill(-140-age/2+xp,(int)t_o+yp-90,0);}
}
  /********************************************************************/
void Poisson::clear_eat(int eta,int y=0)
{ if(eta==1){if(xp<gm && xp>gm-39){
  setcolor(0); setfillstyle(1,0);
  fillellipse(157+x_n,180-x_n+y,3,3);
  x_n+=1;}}
}
 /*****************************************************************/
void Poisson::clear_poisson(int eta)
{  if(eta==1){clear_eat(1);
   setcolor(0);
   setfillstyle(1,0);
   floodfill(coly1[0]-2,coly1[1]-1,0);
   fillellipse(-126+xp,(int)t_o+yp-89,20+age,10+age);
   floodfill(poly1[0]+2,poly1[1],0);}
}
////////////////////////////////////////////////////////////////////
		    /****** less_menu()//fonction *****/
////////////////////////////////////////////////////////////////////

void less_menu()
{  /*------------- appel aux constructeurs des poissons ----------*/
  Poisson poisson1(-133,0,-4);     poisson1.xp=getmaxx();
  Poisson poisson2(-128,0,7);      poisson2.xp=getmaxx()-100;
  Poisson poisson3(-138,0,14);     poisson3.xp=getmaxx()-200;
  Poisson poisson4(-265,0,4);      poisson4.xp=getmaxx();
  Poisson poisson5(-260,0,8);      poisson5.xp=getmaxx()-100;
  Poisson poisson6(-270,0,5);      poisson6.xp=getmaxx()-200;
  Poisson poisson7(-150,0,15);     poisson7.xp=getmaxx()-300;
  Poisson poisson8(-280,0,3);      poisson8.xp=getmaxx()-300;
  Poisson poisson(-104,0);         poisson.xp =138;
  Poisson poissond(-119,0);        poissond.xp=238;
  Poisson poissont(-125,0);        poissont.xp=338;
  Poisson poissone(-111,0);        poissone.xp=438;
     /*--------------- dessin ded poissons -----------------*/
  setlinestyle(0,0,0);
  poisson.dessin(1,15,2,-4,2);   poissond.dessin(1,11,13);
  poissont.dessin(1,13,3,6,-2);  poissone.dessin(1);
     /*-----------------------------------------------------*/
  poisson1.draw_poisson(1);      poisson2.draw_poisson(1);
  poisson3.draw_poisson(1);      poisson4.draw_poisson(1);
  poisson5.draw_poisson(1);      poisson6.draw_poisson(1);
  poisson7.draw_poisson(1);      poisson8.draw_poisson(1);
   /*-------------------------------------------------------*/
  setcolor(1);
  setlinestyle(0,4,3);
  rectangle(388,398,449,437);    rectangle(388,329,449,368);
  rectangle(388,266,449,305);    rectangle(488,398,549,437);
  rectangle(288,398,349,437);    rectangle(188,398,249,437);
  rectangle(488,329,549,368);    rectangle(288,329,349,368);
  rectangle(188,329,249,368);    rectangle(488,266,549,305);
  rectangle(288,266,349,305);    rectangle(188,266,249,305);
   /*-------------------------------------------------------*/
  setcolor(15); settextstyle(2,0,4);    outtextxy(306,375,"zizou");
  outtextxy(190,311,"blanchette");      outtextxy(398,311,"le pape");
  outtextxy(480,311,"la hollandaise");  outtextxy(184,375,"la marocaine");
  outtextxy(280,311,"la br?silienne");  outtextxy(305,443,"bouga");
  outtextxy(396,375,"zambrota");        outtextxy(500,375,"ronaldo");
  outtextxy(198,443,"hbichou");         outtextxy(382,443,"la congolaise");
  outtextxy(485,443,"la japonaise");
  settextstyle(0,0,0);
   /*--------------------------------------------------------*/
  setcolor(13);
  outtextxy(200,110,"**** Choisir la p?riode de la journ?e ****");
  setcolor(1);setfillstyle(1,9); fillellipse(245,160,40,10);
  fillellipse(365,160,60,10);    fillellipse(485,160,40,10);
  setcolor(15);
  outtextxy(226,157,"Matin");    outtextxy(326,157,"Apr?s-midi");
  outtextxy(470,157,"Nuit");
  setcolor(13);
  outtextxy(200,210,"****       Choisir les poissons       ****");
  setcolor(1);setfillstyle(1,9);fillellipse(70,415,60,15);
  setcolor(15); outtextxy(43,412,"Valider");
}
//////////////////////////////////////////////////////////////////////
	       /*******  lafonction principale   ********/
			 /*  _____main()_____  */
//////////////////////////////////////////////////////////////////////
void main()
{ int aq_i=0,aq_f=0,aq_d=0,cont=0,couloor,ch_p=0,a,ok,i,x,y;
  int Fish[12],b[3];
  char * code;
  while(1){
  inite();logo(315,320);
  setcolor(1);rectangle(0,82,getmaxx(),84);
  setcolor(-11);settextstyle(0,0,1);
  outtextxy(3,14," UNIVERSITE CADI AYYAD");
   setcolor(15);
  outtextxy(3,28," Ecole Nationale DES");
  outtextxy(3,40," SCIENCES APPLIQUEES");
  outtextxy(3,54,"     -MARRAKECH-");
	 /*-----------------------------------------*/
  setcolor(15);outtextxy(170,60,"Realis? by");
  setcolor(11);
  outtextxy(260,60,"Youssef baba");
  outtextxy(260,70,"babajosef@hotmail.com");
  setcolor(9); settextstyle(0,0,4);outtextxy(200,20,"AQUARIUM C++");
  settextstyle(0,0,1); setcolor(15);
	/*------------------------------------------*/
  outtextxy(460,60,"Encadr? par: "); setcolor(11);
  outtextxy(460,70,"Dr.Abdeljalil BENYOUB");
	/*------------------------------------------*/
  setcolor(1);setfillstyle(1,9);
  fillellipse(70,110,60,15);   fillellipse(70,150,60,15);
  setcolor(15);
  outtextxy(22,106,"Mon aquarium"); outtextxy(44,146,"Quitter");
	/*---------------------------------------------*/
  setcolor(9);
  outtextxy(20,290,"SEMAINE");
  outtextxy(20,305,"NATIONALE");
  outtextxy(20,320,"DE LA SCIENCE");
  outtextxy(70,330,"ÜÜÜ");
  outtextxy(86,335,"Û");outtextxy(86,343,"Û");
  outtextxy(86,351,"Û");outtextxy(86,359,"Û");
  outtextxy(70,345,"ÜÜÜ");outtextxy(70,360,"ÜÜÜ");
  settextstyle(2,0,4);
  outtextxy(100,331,"?me");
  settextstyle(0,0,0);
  outtextxy(100,345,"Edition");
	/*---------------------------------------------*/
   for(i=0;i<12;i++)
   Fish[i]=0;
   a=3; sinit(&a);scroix(); smontre_curs();
   do{
   sbread(b,&x,&y);  // lecture de position et etat de la souris
	     /*------  mon aquarium -----------*/
   if((x<115)&&(x>25)&&(y>102)&&(y<120)&&(b[0]==1)) less_menu();
	     /*------- boutons fonts d'ecrans --------*/
   if((x<280)&&(x>210)&&(y>150)&&(y<170)&&(b[0]==1)){
   scache_curs();setcolor(11); outtextxy(226,157,"Matin");
   smontre_curs();couloor=9;ch_p=1;}
   if((x<420)&&(x>310)&&(y>150)&&(y<170)&&(b[0]==1)){
   scache_curs();setcolor(11); outtextxy(326,157,"Apr?s-midi");
   smontre_curs();couloor=1;ch_p=1;}
   if((x<520)&&(x>450)&&(y>150)&&(y<170)&&(b[0]==1)){
   scache_curs();setcolor(11); outtextxy(470,157,"Nuit");
   smontre_curs();couloor=0;ch_p=1;}
	    /*--- effet du clique sur les poissons ------*/
   if((x<448)&&(x>389)&&(y>399)&&(y<436)&&(b[0]==1)){
   Fish[4]=1;setcolor(8);settextstyle(2,0,4);
   outtextxy(382,443,"la congolaise");settextstyle(0,0,0);}
   if((x<448)&&(x>389)&&(y>330)&&(y<367)&&(b[0]==1)){
   Fish[10]=1;setcolor(13);settextstyle(2,0,4);
   outtextxy(396,375,"zambrota");settextstyle(0,0,0);}
   if((x<448)&&(x>389)&&(y>329-63+1)&&(y<368-63-1)&&(b[0]==1)){
   Fish[1]=1;setcolor(7);settextstyle(2,0,4);
   outtextxy(398,311,"le pape");settextstyle(0,0,0);}
   if((x<548)&&(x>489)&&(y>399)&&(y<436)&&(b[0]==1)){
   Fish[3]=1;setcolor(4);settextstyle(2,0,4);
   outtextxy(485,443,"la japonaise");settextstyle(0,0,0);}
   if((x<348)&&(x>289)&&(y>399)&&(y<436)&&(b[0]==1)){
   Fish[5]=1;setcolor(-11);settextstyle(2,0,4);
   outtextxy(305,443,"bouga");settextstyle(0,0,0);}
   if((x<248)&&(x>189)&&(y>399)&&(y<436)&&(b[0]==1)){
   Fish[7]=1; setcolor(3);settextstyle(2,0,4);
   outtextxy(198,443,"hbichou");settextstyle(0,0,0); }
   if((x<548)&&(x>489)&&(y>330)&&(y<367)&&(b[0]==1)){
   Fish[11]=1;setcolor(6);settextstyle(2,0,4);
   outtextxy(500,375,"ronaldo");settextstyle(0,0,0);}
   if((x<348)&&(x>289)&&(y>330)&&(y<367)&&(b[0]==1)){
   Fish[9]=1;setcolor(11);settextstyle(2,0,4);
   outtextxy(306,375,"zizou");settextstyle(0,0,0);}
   if((x<248)&&(x>189)&&(y>330)&&(y<367)&&(b[0]==1)){
   Fish[8]=1; setcolor(2);settextstyle(2,0,4);
   outtextxy(184,375,"la marocaine");settextstyle(0,0,0);}
   if((x<548)&&(x>489)&&(y>329-63+1)&&(y<368-63-1)&&(b[0]==1)){
   Fish[0]=1;settextstyle(2,0,4);setcolor(-4);
   outtextxy(480,311,"la hollandaise");settextstyle(0,0,0);}
   if((x<348)&&(x>289)&&(y>329-63+1)&&(y<368-63-1)&&(b[0]==1)){
   Fish[2]=1;setcolor(14);settextstyle(2,0,4);
   outtextxy(280,311,"la br?silienne");settextstyle(0,0,0);}
   if((x<248)&&(x>189)&&(y>329-63+1)&&(y<368-63-1)&&(b[0]==1)){
   Fish[6]=1;setcolor(15);settextstyle(2,0,4);
   outtextxy(190,311,"blanchette");settextstyle(0,0,0);}
	/*---------------- bouton ok -------------------*/
   if((x<115)&&(x>25)&&(y>405)&&(y<425)&&(b[0]==1)&&(ch_p)){
   scache_curs(); cleardevice();break;}
   if((x<115)&&(x>25)&&(y>140)&&(y<160)&&(b[0]==1)){
   exit(0);getch();closegraph();}}
   while(1);
     /*----------------------------------------------------*/
   smontre_curs();Aquarium aquarium;Plancton plancton;
   aquarium.draw_aqua(couloor);aquarium.draw_decors();
   Poisson poisson1(10,380,-4);poisson1.xp=getmaxx();
   Poisson poisson2(10,380,7);poisson2.xp=getmaxx()-100;
   Poisson poisson3(10,380,14);poisson3.xp=getmaxx()-200;
   Poisson poisson4(-110,380,4);poisson4.xp=getmaxx();
   Poisson poisson5(-110,380,8);poisson5.xp=getmaxx()-100;
   Poisson poisson6(-110,380,5);poisson6.xp=getmaxx()-200;
   Poisson poisson7(10,380,15);poisson7.xp=getmaxx()-300;
   Poisson poisson8(-110,380,3);poisson8.xp=getmaxx()-300;
   Poisson poisson(40,0); poisson.xp =140;
   Poisson poissond(40,0);poissond.xp=240;
   Poisson poissont(40,0);poissont.xp=340;
   Poisson poissone(40,0);poissone.xp=440;
   for(int t=0;t<12;t++)
   aq_i+=Fish[t];
   while(1){
   plancton.draw_plancton();aquarium.draw_boule();
   poisson.dessin(Fish[8],15,2,-4,2);poissond.dessin(Fish[9],11,13);
   poissont.dessin(Fish[10],13,3,6,-2);poissone.dessin(Fish[11]);
   cont++;
   poisson1.draw_poisson(Fish[0]); poisson1.eat_poisson(Fish[0]);
   poisson4.draw_poisson(Fish[3]); poisson4.eat_poisson(Fish[3],110);
   poisson2.draw_poisson(Fish[1]); poisson2.eat_poisson(Fish[1]);
   poisson5.draw_poisson(Fish[4]); poisson5.eat_poisson(Fish[4],110);
   poisson3.draw_poisson(Fish[2]); poisson3.eat_poisson(Fish[2]);
   poisson6.draw_poisson(Fish[5]); poisson6.eat_poisson(Fish[5],110);
   poisson7.draw_poisson(Fish[6]); poisson7.eat_poisson(Fish[6]);
   poisson8.draw_poisson(Fish[7]); poisson8.eat_poisson(Fish[7],110);
	      /*-----------------------------------------*/
			     delay(60);
	      /*--------------------------------------*/
   aquarium.clear_boule();
   poisson.clear(Fish[8]);          poissond.clear(Fish[9]);
   poissont.clear(Fish[10]);        poissone.clear(Fish[11]);
   poisson1.clear_eat(Fish[0]);     poisson1.clear_poisson(Fish[0]);
   poisson4.clear_eat(Fish[3],110); poisson4.clear_poisson(Fish[3]);
   poisson2.clear_eat(Fish[1]);     poisson2.clear_poisson(Fish[1]);
   poisson5.clear_eat(Fish[4],110); poisson5.clear_poisson(Fish[4]);
   poisson3.clear_eat(Fish[2]);     poisson3.clear_poisson(Fish[2]);
   poisson6.clear_eat(Fish[5],110); poisson6.clear_poisson(Fish[5]);
   poisson7.clear_eat(Fish[6]);     poisson7.clear_poisson(Fish[6]);
   poisson8.clear_eat(Fish[7],110); poisson8.clear_poisson(Fish[7]);
	      /*--------------------------------------*/
   if(poisson1.xp<302) { poisson1.xp=getmaxx()+40;poisson1.x_n=1; }
   if(poisson2.xp<302) { poisson2.xp=getmaxx()+40;poisson2.x_n=1; }
   if(poisson3.xp<302) { poisson3.xp=getmaxx()+40;poisson3.x_n=1; }
   if(poisson4.xp<302) { poisson4.xp=getmaxx()+40;poisson4.x_n=1; }
   if(poisson5.xp<302) { poisson5.xp=getmaxx()+40;poisson5.x_n=1; }
   if(poisson6.xp<302) { poisson6.xp=getmaxx()+40;poisson6.x_n=1; }
   if(poisson7.xp<302) { poisson7.xp=getmaxx()+40;poisson7.x_n=1; }
   if(poisson8.xp<302) { poisson8.xp=getmaxx()+40;poisson8.x_n=1; }
	      /*-------------------------------------*/
   if(poisson.xp>getmaxx() -150) { poisson.xp=100;}
   if(poissond.xp>getmaxx()-150) { poissond.xp=100;}
   if(poissont.xp>getmaxx()-150) { poissont.xp=100;}
   if(poissone.xp>getmaxx()-150) { poissone.xp=100;}
	      /*-------------------------------------*/
   if(hauteur>getmaxy()-220) hauteur=0;hauteur+=2;
   poisson1.xp-=2;poisson3.xp-=2; poisson5.xp-=2;poisson7.xp-=2;
   poisson2.xp-=2;poisson4.xp-=2; poisson6.xp-=2;poisson8.xp-=2;
   poisson.xp+=2;poissond.xp+=2;  poissont.xp+=2;poissone.xp+=2;
	     /*---------------------------------------*/
   if(!fmod(cont,200))  poisson.age+=1;   if(poisson.age==4)  Fish[8]=0;
   if(!fmod(cont,400))  poisson1.age+=1;  if(poisson1.age==5) Fish[0]=0;
   if(!fmod(cont,500))  poissont.age+=1;  if(poissont.age==5) Fish[10]=0;
   if(!fmod(cont,600))  poisson4.age+=1;  if(poisson4.age==5) Fish[3]=0;
   if(!fmod(cont,700))  poisson2.age+=1;  if(poisson2.age==5) Fish[1]=0;
   if(!fmod(cont,800))  poisson5.age+=1;  if(poisson5.age==5) Fish[4]=0;
   if(!fmod(cont,900))  poisson6.age+=1;  if(poisson6.age==5) Fish[5]=0;
   if(!fmod(cont,1000)) poissond.age+=1;  if(poissond.age==5) Fish[9]=0;
   if(!fmod(cont,1100)) poisson8.age+=1;  if(poisson8.age==5) Fish[7]=0;
   if(!fmod(cont,1200)) poisson3.age+=1;  if(poisson3.age==5) Fish[2]=0;
   if(!fmod(cont,1300)) poisson7.age+=1;  if(poisson7.age==5) Fish[6]=0;
   if(!fmod(cont,1400)) poissone.age+=1;  if(poissone.age==5) Fish[11]=0;
	     /*----- quand l'aquarium et vide -------*/
   for(int q=0;q<12;q++)
   aq_f+=Fish[q];
   if(aq_f==0){
   scache_curs();
   setcolor(14);
   outtextxy(getmaxx()/2-50,getmaxy()/2,"L'aquarium est vide");sleep(3);
   cleardevice();break;}
	     /*------ revenir au menu principale -------*/
   sbread(b,&x,&y);
   sbbornes(126,559,421,449);
   if((x>314)&&(x<460)&&(y<449)&&(y>421)&&(b[0]==1)){
   scache_curs(); cleardevice();break; }
	     /*------ etat de l'auarium -------*/
   if((x>126)&&(x<284)&&(y<449)&&(y>421)&&(b[0]==1)){
   aq_d=0;aq_f=0;
   for(int t=0;t<12;t++) aq_f+=Fish[t];
   aq_d=aq_i-aq_f;itoa(aq_d,code,10);setcolor(7);
   setlinestyle(0,4,3);rectangle(90,30,608,90);
   setcolor(15); outtextxy(130,45,"L'etat de l'aquarium ");
   setcolor(11);outtextxy(100,60," Le nombre de poissons d?c?d?s est  :");
   outtextxy(420,60,code);
   delay(600);setcolor(couloor);
   outtextxy(100,40,"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
   outtextxy(100,45,"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
   outtextxy(100,60,"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
   setcolor(couloor);rectangle(90,30,608,90);}
   if((x>491&&x<559)&&(y<449&&y>421)&&b[0]==1&&b[0]==1){
   cleardevice();closegraph();exit(1);}
   setlinestyle(0,0,0);}}
}
	  /***************************************************/
	   /*                                                */
	   /*	             ÜÜÜÜÜ   Ü   ÜÜÜÜÜ                 */
	   /*	             Û       Û   Û   Û                 */
	   /*	             ÛÜÜÜÜ   Û   Û   Û                 */
	   /*	             Û       Û   Û   Û                 */
	   /*	             Û       Û   Û   Û                 */
	   /*                                                */
	 /****************************************************/
