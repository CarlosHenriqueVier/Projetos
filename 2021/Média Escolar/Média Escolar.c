#include <stdio.h>
#include <stdlib.h>

int main()

{
  float n1, n2, n3, media;

  printf("==============Media Escolar==============\n");

  printf("\nDigite a primeira nota \n");
  scanf("%f", &n1);

  while(n1 < 0 || n1 > 10)
{
    printf("Digite novamente, o valor da nota deve ser de 0 a 10 \n");
    scanf("%f", &n1);
}
  printf("\nDigite a segunda nota \n");
  scanf("%f", &n2);

  while(n2 < 0 || n2 > 10)
{
    printf("Digite novamente, o valor da nota deve ser de 0 a 10 \n");
    scanf("%f", &n2);
}
  printf("\nDigite a terceira nota \n");
  scanf("%f", &n3);

  while(n3 < 0 || n3 > 10)
{
    printf("Digite novamente, o valor da nota deve ser de 0 a 10 \n");
    scanf("%f", &n3);
}
{
    media= ( n1 + n2 + n3) / 3;
}
    if ( media < 6){
    printf("Insuficiente! \n");
}
    else if (media >= 6 && media <8){
            printf("Mediocre! \n");
}
    else{
            printf("Exelente! \n");
}
  system ("PAUSE");
  return(0);
}
