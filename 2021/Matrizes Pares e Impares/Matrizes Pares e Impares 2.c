#include <stdio.h>
#include <stdlib.h>
#define A 20
#define B 20
int main()
{
srand(time(0));

int matriz[A][B]={}, c,l;

int matrizI[A][B]={0};

int matrizP[A][B]={0};
for(c=0; c<A; c++){
    for(l=0; l<B; l++){
        matriz[c][l]=rand()%100;

        if(matriz[c][l]%2==0)matrizI[c][l]=0;
        else matrizI[c][l]=matriz[c][l];

        if(matriz[c][l]%2!=0)matrizP[c][l]=0;
        else matrizP[c][l]=matriz[c][l];
    }
}

printf("MATRIZ ORIGINAL");
printf("\n");
printf("\n");

for(c=0; c<A;c++){
    for(l=0;l<B;l++){
        printf("[%02i]",matriz[c][l]);
    }
    printf("\n");
}
printf("\n");
printf("MATRIZ DOS PARES");
printf("\n");
printf("\n");
for(c=0; c<A;c++){
    for(l=0;l<B;l++){
        printf("[%02i]",matrizP[c][l]);
    }
    printf("\n");
}
printf("\n");
printf("MATRIZ DOS IMPARES");
printf("\n");
printf("\n");
for(c=0; c<A;c++){
    for(l=0;l<B;l++){
        printf("[%02i]",matrizI[c][l]);
    }
    printf("\n");
}
}

