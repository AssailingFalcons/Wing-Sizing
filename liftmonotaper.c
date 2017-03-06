#include<stdio.h>
#include<stdlib.h>
float AR,e,alpha,cl,l,l1,cr,ct,d,mac;
float span;
float area;
int i;
int main(){
    for(span=133;span<=135;span++){
            for(AR=7.0;AR<=7.1;AR=AR+0.1){
for(d=0.2;d<=1;d=d+0.1){
mac=span/AR;
cr=1.5*mac*(1+d)/(1+d+d*d);
ct=d*cr;
area=((((cr+ct)*span)/2)*2.54*2.54)/10000;        //area
double x=pow(AR,0.68);
e=(1.78*(1-0.045*x))-0.64;                       //oswald efficiency
alpha=(0.057)/(1+((57.3*0.057)/(3.14*AR*e)));
cl=alpha*14.6;                                   //corrected coefficient of lift
l=0.5*1.225*area*15*15*cl;                       //lift equation
l1=(l/9.8)*2.2;
if(l1>30){
printf("lift is %.3f  ",(l1));
printf("alpha is %.3f  ",alpha);
printf("area is %.3f  " ,area);
printf("cl is %.3f  ",cl);
printf("AR is %f  ",AR);
printf("Span is %f  ",span);
printf("d is %f  ",d);
printf("cr is %f  ",cr);
printf("ct is %f  ",ct);
printf("e is %f  ",e);
printf("mac is %f  ",mac);
printf("\n");}

}

    }
}
}
