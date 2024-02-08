#include <stdio.h>
#include <stdlib.h>

float somar (float v1, float v2){
return v1 + v2;
}
float subtrair (float v1, float v2){
return v1 - v2;
}
float multiplicar(float v1,float v2){
return v1 * v2;
}
float dividir (float v1, float v2){
return v1 / v2;
}
int main(){
int op;
float v1,v2,resultado;
printf("---------Calculadora----------");

printf("\ninsira o primeiro valor:\n");
scanf("%f",&v1);

printf("insira o segundo valor:\n");
scanf("%f",&v2);

printf("1 para somar\n");
printf("2 para subtrair\n");
printf("3 para multiplicar\n");
printf("4 para dividir\n");
printf("digite a operacao:\n");
scanf("%d",&op);

switch(op)
{
    case 1:
        resultado = somar(v1,v2);
        break;


    case 2:
        resultado = subtrair(v1,v2);
        break;

{
    case 3:
        resultado = multiplicar(v1,v2);
        break;
}

    case 4:
    if(v2 == 0)
    {
        printf("nao eh possivel dividir por 0");
    }
    else
    {
        resultado = dividir(v1,v2);
    }
    break;

    default:
        printf("Opsao invalida");
        break;
}
printf("---------------------------------\n");
printf("\nResultado:%f\n",resultado);

  system ("PAUSE");
  return(0);
}

