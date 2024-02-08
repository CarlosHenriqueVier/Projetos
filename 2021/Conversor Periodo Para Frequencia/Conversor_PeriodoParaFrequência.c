#include <stdio.h>
#include <stdlib.h>

int s(float *p,float *f){

if(*p==0 && *f==0) return -1;

else if(*p!=0 && *f==0 || *p==0 && *f!=0){
if(*p==0)
    *p=1/ *f;
if(*f==0)
    *p=1/ *p;
return 0;
}
}
int main(){
float a=2;
float b=0;
int k;
    printf("Valor para periodo= %f\n",a);
    printf("Valor para frequencia= %f\n",b);
k = s(&a,&b);
if (k==0){
    printf("\nRetorno=-1\n");
}
if (k!=0){
    printf("\nRetorno=0\n");
}
printf("\n\nBy Carlos\n\n");
}
