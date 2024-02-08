#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, r=1;

    printf("==============FATORADOR===========\n");

    printf("\nInforme o valor que de seja ser fatorado:");
    scanf("%i", &n);

    if (n<0){
        printf("\nValor digitado nao pode ser fatorado, digite novamente:");
         scanf("%i", &n);
    }
    for(i=n; i>1; i--){
        r = r*i;
    }
    printf("\nO valor do fatorial de %i = %i\n", n, r);

    return 0;
}
