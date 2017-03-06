#include<stdio.h>
#include<stdlib.h>
#include <math.h>
float yo,yi,lamda,b,maxdeflection,vstall,swing,stotal,cdr,maxtc=0.137,arwing=7.1,rootchord=0.59,taw,c2d,c3d,yd,crollcoeff,cl,req,ixx,vapp,la;
float phione,rateofrollrate,t;
double main(){
    printf("enter outer aileron location\n");
    scanf("%f",&yo);
     printf("enter inner aileron location\n");
    scanf("%f",&yi);
     printf("enter taper ratio\n");
    scanf("%f",&lamda);
    printf("enter span\n");
    scanf("%f",&b);
    printf("enter max deflection\n");
    scanf("%f",&maxdeflection);
     printf("enter vstall\n");
     scanf("%f",&vstall);
     printf("enter area of wing\n");
     scanf("%f",&swing);
     printf("enter total area\n");
     scanf("%f",&stotal);
      printf("enter ixx\n");
        scanf("%f",&ixx);
      printf("enter required angle to bank\n");
      scanf("%f",&req);
   for(taw=0.5;taw<=0.6;taw=taw+0.5){
        for(cdr=0.7;cdr<=1.20;cdr=cdr+0.1){
c2d=1.8*3.14*(1+0.8*maxtc);
c3d=c2d/(1+c2d/(3.14*arwing));
crollcoeff=((2*taw*rootchord*c3d)/(swing*b))*((yo*yo/2)+0.66*(((lamda-1)/b)*yo*yo*yo) - ((yi*yi/2)+0.66*((lamda-1)/b)*yi*yi*yi));
cl=(crollcoeff*maxdeflection)/57.3;
vapp=1.3*vstall;
la=0.5*1.225*vapp*vapp*swing*cl*b;
yd=(0.4*b)/2;
double x=((2*la)/(1.225*stotal*cdr*yd*yd*yd));
double pss=pow(x,0.5);
phione=((ixx*log(pss*pss))/(1.225*yd*yd*yd*stotal*cdr));
rateofrollrate=(pss*pss)/(2*phione);
if((phione*57.3)>req){
       float y= (2*req/(rateofrollrate*57.3));
    t=pow(y,0.5);
    printf("time taken is %.3f\n",t);
    printf("taw is %.2f\n",taw);
    printf("la is %.2f Nm\n",la);
    printf("rate of roll rate is %.2f \n",rateofrollrate);

}
else{
    t=(req-phione)/pss + pow((2*req/(57.3*rateofrollrate)),0.5);
    printf("time taken is %.3f\n",t);
     printf("taw is %.2f\n",taw);
      printf("la is %.2f Nm\n",la);
        printf("rate of roll rate is %.2f \n",rateofrollrate);
}
   }
}
}
