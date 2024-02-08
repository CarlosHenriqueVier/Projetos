#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int main(){
struct cord{
int a;
int b;
}p,l;
float result;
printf("Digite os valores x e y da primeira cordenada=\n");
scanf("%i%i",&p.a,&p.b);
printf("\n\nDigite os valores x e y da segunda cordenada=\n");
scanf("%i%i",&l.a,&l.b);
result= sqrt(pow(p.a-l.a,2)+pow(p.b-l.b,2));
printf("\n\nResultado da diferenca entre dois pontos=%f\n",result);
}