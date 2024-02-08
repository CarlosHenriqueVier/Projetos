#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){

union temp{float gc, gf,gk;}a;
int x;
printf("              Digite o valor da temperatura em graus celsius=");
scanf("%f",&a.gc);
system("cls");
printf("        Digite 1 para converter para graus Fahrenheit\n         Digite 2 para converter para graus Kelvin\n");
scanf("%i",&x);
if(x==1){
a.gf=(a.gc * (9.0/5.0))+32.0;
system("cls");
printf("%f",a.gf);
}
if(x==2){
a.gk=(a.gc+273.15);
if(a.gk<0){
system("cls");
printf("Erro, temperatura negativa maxima em Kelvin é 0");
}
else{
system("cls");
printf("%f",a.gk);
}
}

while(x != 1 && x !=2){
printf("\n        Digite 1 para converter para graus Fahrenheit\n         Digite 2 para converter para graus Kelvin\n");
scanf("%i",&x);
if(x==1){
a.gf=(a.gc * (9.0/5.0))+32.0;
system("cls");
printf("%f",a.gf);
}
if(x==2){
a.gk=(a.gc+273.15);
if(a.gk<0){
system("cls");
printf("Erro, Kelvin = 0");
}
else{
system("cls");
printf("%f",a.gk);
}
}
}
};
