#include <stdio.h>
#include <stdlib.h>
#define L 15
#define C 15


int fX(int *m2, int *m1)
{

int x;

m2 += (L*C)-1;

for( x=0; x<L*C; x++){

    *m1 = *m2;
    m1++;
    m2--;

    }
}

int fY(int *m1)

{

int x;

srand(time(0));


for(x=0; x<L*C; x++){

    *m1=rand()%80;
    m1++;

    }
}

int fZ(int *m1)

{
    int x,z=1;

for( x=0; x<L*C; x++){
    printf(" %02i ", *m1);

        if(z==L){

    printf("\n");
    z=0;
        }

    z++;
    m1++;

    }
}

int main()
{
int matriz1[L][C]={0}, matriz2[L][C]={0};

fY(matriz1);


fX(matriz1, matriz2);

    printf("-----------------------  Matriz 1   -----------------------");

printf("\n");
printf("\n");
fZ(matriz1);
printf("\n");
    printf("-----------------------  Matriz 2   -----------------------");

printf("\n");
printf("\n");

fZ(matriz2);


printf("\n");
printf("            Carlos Henrique Vier, 4212");
printf("\n");

}


