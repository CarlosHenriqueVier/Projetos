#include <stdio.h>
#define D 100

void pilha :: cp(void) // função esvazia pilha
{
ptrP--;
}
int pilha :: vazio(int *vazio_para)
{
if(ptrP == -1)// pilha vazia, retorna 0
{
return 0;
}
else //caso não, retorna dados
    *vazio_para = dados[ptrP--];
return 1;
}

int pilha :: cheio(int cheio_para)
{
if(ptrP >=99) //pilha vazia, retorna 0
{
return 0;
}
else
dados[++ptrP] = cheio_para;
}

int interface(){
    int z;
        while(1){
        printf("------------ Digite a opção que deseja fazer ----------------------------\n");
        printf("[1] Empilhar\n");
        printf("[2] Desempilhar\n");
        printf("[3] Empilhar e Desempilhar\n");
        scanf("%i",&z);
        system("cls");
        if(z<=3 && z>0){
            return z;
        }
        else
        printf("------------ Digite a opção que deseja fazer ----------------------------\n");
        printf("[1] Empilhar\n");
        printf("[2] Desempilhar\n");
        printf("[3] Empilhar e Desempilhar\n");
        scanf("%i",&z);
        system("cls");
        }
}

int op(void){
    int y;
while(1){
        printf("------------ Digite um valor de 1 a 100 para empilhar -------------------\n");
        scanf("%i",&y);
        system("cls");
            if(y>0 && y<=100){
                return y;
        }
            else
                printf("------------ Digite um valor de 1 a 100 para empilhar -------------------\n");
                scanf("%i",&y);
                system("cls");
        }
}

int main()
{
    int loop,desempilha,x,limite;

    cpilha.cp();
    x = interface();
    limite = op();
    limite++;
    switch(x){
        case 1: //empilha mostra a empilha
    for(loop = 0; loop<limite;loop ++){
        cpilha.cheio(loop);
        printf("Valor empilhado ->[%d]\n",loop);
    }
    break;
        case 2:// empilha e desempilha mostra só o desempilha
    for(loop = 0; loop<limite;loop ++){
        cpilha.cheio(loop);
    }
    for(loop = 0; loop<limite; loop ++){
        cpilha.vazio(&desempilha);
        printf("Valor desempilhado ->[%d]\n",desempilha);
    }
    break;
        case 3: // caso empilha e desempilha mostrando ambos
    for(loop = 0; loop<limite;loop ++){
        cpilha.cheio(loop);
        printf("Valor empilhado ->[%d]\n",loop);
    }
    printf("\n");
    for(loop = 0; loop<limite; loop ++){
        cpilha.vazio(&desempilha);
        printf("Valor desempilhado ->[%d]\n",desempilha);
    }
    break;
    }
    return 0;
}
