#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 4

int main(){

int x,y;
int matriz[L][C]={1,-2,3,-4,5,-6,7,-8,9,-10,11,-12};
printf("\n------------------------------MATRIZ----------------------------------\n");
printf("\n");
for(x=0;x<L;x++){
    for(y=0;y<C;y++){
    printf("[%i][%i]=%i\t",x,y,matriz[x][y]);
    if(y==3)
        {
        printf("\n");
    }
   }
}
printf("\n--------------------------MATRIZ MODIFICADA----------------------------\n");
printf("\n");
for(x=0;x<L;x++){
    for(y=0;y<C;y++){
if(matriz[x][y]<0){
    matriz[x][y]=0;
}
    printf("[%i][%i]=%i\t",x,y,matriz[x][y]);
    if(y==3)
        {
        printf("\n");
    }
   }
}
printf("\n\nCarlos Henrique Vier\n\n");
}
