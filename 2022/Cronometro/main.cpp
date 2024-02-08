#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "bugiganga.cpp"
#define TAM 50
#define LIN 10

int display(int dis, int m[LIN][TAM], int limit, DOS_COLORS digito, DOS_COLORS painel);
int displayAnimacao(int m[12][12]);
int Desenha(int d, int m[LIN][TAM]);
int zera(int m[LIN][TAM]);
void n0(int m[LIN][TAM]);
void n1(int m[LIN][TAM]);
void n2(int m[LIN][TAM]);
void n3(int m[LIN][TAM]);
void n4(int m[LIN][TAM]);
void n5(int m[LIN][TAM]);
void n6(int m[LIN][TAM]);
void n7(int m[LIN][TAM]);
void n9(int m[LIN][TAM]);
void n9(int m[LIN][TAM]);
void nome(int m[LIN][TAM]);
void turma(int m[LIN][TAM]);
void animacao(int m[LIN][TAM]);
void explosao(void);

int mtx[LIN][TAM]={0};

int f1[12][12] =
{
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 3, 2, 3, 1, 0, 0, 0,
0, 0, 0, 3, 2, 2, 2, 2, 3, 0, 0, 0,
0, 0, 0, 2, 3, 2, 4, 2, 2, 0, 0, 0,
0, 0, 0, 2, 2, 4, 4, 2, 1, 0, 0, 0,
0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0,
0, 0, 0, 0, 2, 3, 3, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int f2[12][12] =
{
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 3, 2, 3, 1, 0, 0, 0,
0, 0, 0, 3, 2, 2, 2, 2, 3, 0, 0, 0,
0, 0, 0, 2, 3, 2, 4, 2, 2, 0, 0, 0,
0, 0, 0, 2, 2, 4, 4, 2, 1, 0, 0, 0,
0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0,
0, 0, 0, 0, 2, 3, 3, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int f3[12][12] =
{
0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 1, 1, 1, 1, 3, 1, 1, 1, 1, 0, 0,
0, 1, 3, 3, 3, 3, 3, 3, 1, 3, 1, 0,
0, 0, 3, 3, 2, 2, 2, 3, 3, 3, 1, 0,
0, 1, 3, 3, 2, 2, 2, 2, 3, 3, 1, 0,
0, 1, 3, 2, 2, 4, 4, 2, 2, 3, 1, 0,
0, 1, 3, 2, 2, 4, 4, 2, 2, 3, 1, 0,
0, 1, 1, 3, 2, 2, 2, 2, 3, 3, 1, 0,
0, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int f4[12][12] =
{
0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 1, 1, 3, 3, 3, 3, 1, 1, 1, 0, 0,
0, 1, 1, 1, 2, 2, 2, 1, 3, 3, 1, 0,
0, 1, 1, 1, 2, 2, 1, 2, 3, 3, 1, 0,
1, 1, 2, 1, 4, 4, 4, 2, 2, 1, 1, 0,
1, 1, 3, 2, 4, 4, 4, 2, 1, 1, 1, 0,
1, 3, 3, 2, 2, 4, 4, 2, 2, 3, 1, 0,
1, 3, 1, 1, 2, 2, 2, 1, 1, 3, 1, 0,
1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 0,
0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int f5[12][12] =
{
0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 1, 1, 3, 3, 3, 3, 0, 0, 1, 0, 0,
0, 0, 1, 1, 2, 2, 2, 0, 3, 3, 1, 0,
0, 0, 0, 0, 2, 0, 0, 0, 3, 3, 1, 0,
1, 1, 2, 0, 0, 0, 0, 2, 2, 0, 1, 0,
1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 3, 3, 0, 0, 0, 0, 2, 2, 3, 1, 0,
1, 3, 1, 0, 0, 0, 0, 0, 0, 3, 1, 0,
1, 1, 0, 0, 0, 3, 3, 3, 0, 0, 1, 0,
0, 0, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int f6[12][12] =
{
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,
0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,
0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0,
0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

char index[16][15]={
        "PRETO\n",
        "AZUL\n",
        "VERDE\n",
        "CIANO\n",
        "VERMELHO\n",
        "MAGENTA\n",
        "MARRON\n",
        "LIGHT_GRAY\n",
        "DARK_GRAY\n",
        "LIGHT_BLUE\n",
        "LIGHT_GREEN\n",
        "LIGHT_CYAN\n",
        "LIGHT_RED\n",
        "LIGHT_MAGENTA\n",
        "YELLOW\n",
        "WHITE\n"
    };
int color_index(char str[14])
{
    int return_index;
    for(int i=0; i<16; i++){
        return_index = strcmp(str, index[i]);
        if(return_index == 0) return i;
    }
}
void SD(int tempo, int digito, int painel, int fundo)
{
    FILE *p;
    if(!(p = fopen("arquivo.txt", "w"))){
        printf("ERRO ao abrir o arquivo");
        exit(1);
    }
    int tempoinicial=100;
    if(tempo<1)tempo=tempoinicial;

    fprintf(p, "Tempo=%i\n", tempo);
    fprintf(p, "TempoInicial=%i\n", tempoinicial);
    fprintf(p, "CorDigito=%s", index[digito]);
    fprintf(p, "CorPainel=%s", index[painel]);
    fprintf(p, "CorFundo=%s", index[fundo]);

    fclose(p);
}
int LA(int retorno)
{
    char dado[15];
    int int_dado;
    FILE *p;
    p = fopen("arquivo.txt", "r");

    char c;
    int cont[5]={0}, aux=0, i=0;
    while(!feof(p)){
        aux++;
        c = getc(p);
        if(c == '='){
            cont[i]=aux;
            i++;
            aux++;
        }
    }

    fseek(p, (cont[retorno]), SEEK_SET);
    fgets(dado, 14, p);
    switch(retorno){
        case 0:

            int_dado = atoi(dado);
            break;
        default:
            int_dado = color_index(dado);
            break;
    }
    fclose(p);
    return int_dado;
}
void cria_arquivo()
{
    FILE *p;
    p = fopen("arquivo.txt", "r");
    if(!p){
        p = fopen("arquivo.txt", "w");
        fprintf(p, "Tempo=%i\n", 579);
        fprintf(p, "TempoInicial=%i\n", 100);
        fprintf(p, "CorDigito=%s\n", "AZUL");
        fprintf(p, "CorPainel=%s\n", "WHITE");
        fprintf(p, "CorFundo=%s\n", "YELLOW");
        fclose(p);
    }
    fclose(p);
}
DOS_COLORS define_color(int cor)
{
    DOS_COLORS digito;
    switch(cor){
    case 0:
        digito=PRETO;
        break;
    case 1:
        digito=AZUL;
        break;
    case 2:
        digito=VERDE;
        break;
    case 3:
        digito=CIANO;
        break;
    case 4:
        digito=VERMELHO;
        break;
    case 5:
        digito=MAGENTA;
        break;
    case 6:
        digito=MARRON;
        break;
    case 7:
        digito=LIGHT_GRAY;
        break;
    case 8:
        digito=DARK_GRAY;
        break;
    case 9:
        digito=LIGHT_BLUE;
        break;
    case 10:
        digito=LIGHT_GREEN;
        break;
    case 11:
        digito=LIGHT_CYAN;
        break;
    case 12:
        digito=LIGHT_RED;
        break;
    case 13:
        digito=LIGHT_MAGENTA;
        break;
    case 14:
        digito=YELLOW;
        break;
    case 15:
        digito=WHITE;
        break;
    }
    return digito;
}

int main()
{
    cria_arquivo();
    int tempo = LA(0);
    int CD = LA(2);
    int CP = LA(3);
    int CF = LA(4);

    DOS_COLORS digito = define_color(CD);
    DOS_COLORS fundo = define_color(CF);
    DOS_COLORS painel = define_color(CP);

    system("cls");
    Desenha(10, mtx);
    display(-1, mtx, 50, digito, fundo);
    zera(mtx);
    Desenha(11, mtx);
    display(4, mtx, 50, digito, fundo);
    zera(mtx);
    Sleep(2000);
    system("cls");


    int n = tempo;
    int unidade = (n%10);
    int dezena = ((n%100)/10);
    int centena = (n/100);

    while(centena>(-1)){
        char ch;
        if(kbhit()){
            ch = getch();
            system("cls");
        }
        if(ch == 's' || ch == 'S')unidade--;
        if(ch == ' '){
            textcolor(painel);
            gotoxy(40,20);
            printf("Digite um novo numero: ");
            scanf("%i", &n);
            unidade = (n%10);
            dezena = ((n%100)/10);
            centena = (n/100);
            ch = 'p';
        }
        if(ch == '.'){

            gotoxy(0, 0);
            textcolor(painel);
            printf("Mudar cor do digito [1]\n");
            printf("Mudar cor do painel [2]\n");
            printf("Mudar cor do fundo [3]\n");
            printf("Sair do menu [4]\n");
            int change;
            scanf("%i", &change);

            printf(" 0 - PRETO\n");
            printf(" 1 - AZUL\n");
            printf(" 2 - VERDE\n");
            printf(" 3 - CIANO\n");
            printf(" 4 - VERMELHO\n");
            printf(" 5 - MAGENTA\n");
            printf(" 6 - MARRON\n");
            printf(" 7 - LIGHT GRAY\n");
            printf(" 8 - DARK GRAY\n");
            printf(" 9 - LIGHT BLUE\n");
            printf(" 10 - LIGHT GREEN\n");
            printf(" 11 - LIGHT CYAN\n");
            printf(" 12 - LIGHT RED\n");
            printf(" 13 - LIGHT MAGENTA\n");
            printf(" 14 - AMARELO\n");
            printf(" 15 - BRANCO\n");

            int CE;
            switch(change){
            case 1:
                {
                scanf("%i", &CE);
                CD = CE;
                digito = define_color(CD);
                }
                break;
            case 2:
                {
                scanf("%i", &CE);
                CP = CE;
                painel = define_color(CP);
                }
                break;
            case 3:
                {
                scanf("%i", &CE);
                CF = CE;
                fundo = define_color(CF);
                }
                break;
            case 4:
                {
                ch = 'p';
                system("cls");
                }
                break;
            }
        }

        gotoxy(0,22);
        textcolor(painel);
        printf("\t[qualquer] - Aperte para pausar a contagem\n");
        printf("\t[ espaco ] - Para mudar o numero\n");
        printf("\t[   S    ] - Para comecar/continuar a contegem\n");
        printf("\t[   .    ] - Para acessar o menu de cores\n");

        Desenha(unidade, mtx);
        display(3, mtx, 10, digito, fundo);
        zera(mtx);
        Desenha(dezena, mtx);
        display(2, mtx, 10, digito, fundo);
        zera(mtx);
        Desenha(centena, mtx);
        display(1, mtx, 10, digito, fundo);
        zera(mtx);

        Sleep(200);

        //logica para decremento do contador
        if(unidade<0){
            unidade=9;
            dezena--;
        }
        if(dezena<0){
            dezena=9;
            centena--;
        }
        SD(unidade + (dezena*10) + (centena*100), CD, CP, CF);
    }

    system("cls");
    explosao();
    return 0;
}

int display(int dis, int m[LIN][TAM], int limit, DOS_COLORS digito, DOS_COLORS fundo)
{
    for(int i=0; i<LIN; i++){
        for(int j=0; j<limit; j++){
            gotoxy(j+12+(dis*10),i+10);
            if(m[i][j]==0){
                printf("%c", 219);
                textcolor(fundo);
            }
            else if(m[i][j]==1){
                printf("%c", 219);
                textcolor(digito);
            }
        }
    }
}

int displayAnimacao(int m[12][12])
{
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            gotoxy(j+75,i+9);
            if(m[i][j]==0){
                printf("%c", 219);
                textcolor(PRETO);
            }
            else if(m[i][j]==1){
                printf("%c", 219);
                textcolor(VERMELHO);
            }
            else if(m[i][j]==2){
                printf("%c", 219);
                textcolor(YELLOW);
            }
            else if(m[i][j]==3){
                printf("%c", 219);
                textcolor(LIGHT_RED);
            }
            else if(m[i][j]==4){
                printf("%c", 219);
                textcolor(WHITE);
            }
        }
    }
}

int zera(int m[LIN][TAM])
{
    for(int i=0; i<LIN; i++){
        for(int j=0; j<TAM; j++){
            m[i][j]=0;
        }
    }
}

int Desenha(int d, int m[LIN][TAM])
{
    switch(d)
    {
    case 0:
        {
        n0(m);
        break;
        }
    case 1:
        {
        n1(m);
        break;
        }
    case 2:
        {
        n2(m);
        break;
        }
    case 3:
        {
        n3(m);
        break;
        }
    case 4:
        {
        n4(m);
        break;
        }
    case 5:
        {
        n5(m);
        break;
        }
    case 6:
        {
        n6(m);
        break;
        }
    case 7:
        {
        n7(m);
        break;
        }
    case 8:
        {
        n9(m);
        break;
        }
    case 9:
        {
        n9(m);
        break;
        }
    case 10:
        {
        nome(m);
        break;
        }
    case 11:
        {
        turma(m);
        break;
        }
    case 12:
        {
        animacao(m);
        break;
        }
    }
}
void n0(int m[LIN][TAM])
{
    for(int j=2; j<8; j++){
        m[1][j]=1;
    }
    for(int j=1; j<9; j++){
        m[2][j]=1;
    }
    for(int j=2; j<8; j++){
        m[8][j]=1;
    }
    for(int j=1; j<9; j++){
        m[7][j]=1;
    }
    for(int i=2; i<8; i++){
        m[i][1]=1;
        m[i][2]=1;
        m[i][7]=1;
        m[i][8]=1;
    }
}
void n1(int m[LIN][TAM])
{
   for(int i=1; i<9; i++){
        m[i][5]=1;
        m[i][6]=1;
    }
}
void n2(int m[LIN][TAM])
{

    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][7]=1;
    m[3][8]=1;
    m[6][1]=1;
    m[6][2]=1;
}
void n3(int m[LIN][TAM])
{
    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][7]=1;
    m[3][8]=1;
    m[6][7]=1;
    m[6][8]=1;
}
void n4(int m[LIN][TAM])
{
    for(int i=1; i<9; i++){
        m[i][5]=1;
        m[i][6]=1;
    }
    for(int i=1; i<6; i++){
        m[i][1]=1;
        m[i][2]=1;
    }
    m[5][3]=1;
    m[5][4]=1;

}
void n5(int m[LIN][TAM])
{
    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][1]=1;
    m[3][2]=1;
    m[6][7]=1;
    m[6][8]=1;
}
void n6(int m[LIN][TAM])
{
    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][1]=1;
    m[3][2]=1;
    m[6][7]=1;
    m[6][8]=1;
    m[6][1]=1;
    m[6][2]=1;
}
void n7(int m[LIN][TAM])
{
    for(int i=1; i<9; i++){
        m[i][5]=1;
        m[i][6]=1;
    }
    for(int j=1; j<7; j++){
        m[1][j]=1;
        m[2][j]=1;
    }
}
void n8(int m[LIN][TAM])
{
    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][1]=1;
    m[3][2]=1;
    m[3][7]=1;
    m[3][8]=1;
    m[6][7]=1;
    m[6][8]=1;
    m[6][1]=1;
    m[6][2]=1;
}
void n9(int m[LIN][TAM])
{
    for(int j=1; j<9; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][1]=1;
    m[3][2]=1;
    m[3][7]=1;
    m[3][8]=1;
    m[6][7]=1;
    m[6][8]=1;
}

void nome(int m[LIN][TAM])
{
    //V
    for(int i=1; i<9; i++){
        m[1][0]=1;
        m[2][1]=1;
        m[3][1]=1;
        m[4][2]=1;
        m[5][2]=1;
        m[6][3]=1;
        m[7][3]=1;
        m[8][4]=1;

        m[1][8]=1;
        m[2][7]=1;
        m[3][7]=1;
        m[4][6]=1;
        m[5][6]=1;
        m[6][5]=1;
        m[7][5]=1;
        m[8][4]=1;
}
    //I
    for(int i=1; i<9; i++){
        m[i][1+10]=1;
        m[i][2+10]=1;
    }
    //E
    for(int i=1; i<9; i++){
        m[i][0+20]=1;
        m[i][1+20]=1;
    }
    for(int j=1; j<8; j++){
        m[1][j+20]=1;
        m[4][j+20]=1;
        m[8][j+20]=1;
    }
    //R
        for(int i=1; i<9; i++){
        m[i][0+32]=1;
        m[i][0+32]=1;
        m[i][1+32]=1;
        m[i][1+32]=1;
    }
       for(int j=1; j<9; j++){
        m[1][j+32]=1;
        m[4][j+32]=1;
        m[4][8+32]=0;
        m[4][7+32]=0;
        m[1][8+32]=0;
        m[1][7+32]=0;
        m[2][6+32]=1;
        m[4][3+32]=1;
        m[3][6+32]=1;
        m[4][7+32]=1;
        m[5][7+32]=1;
        m[6][7+32]=1;
        m[6][8+32]=1;
        m[6][8+32]=1;
        m[7][8+32]=1;
        m[8][8+32]=1;
    }
}
void turma(int m[LIN][TAM])
{
    // 4 ------------------
    for(int i=1; i<9; i++){
        m[i][5]=1;
        m[i][6]=1;
    }
    for(int i=1; i<6; i++){
        m[i][1]=1;
        m[i][2]=1;
    }
    m[5][3]=1;
    m[5][4]=1;

    // 3 ------------------
    for(int j=1; j<9; j++){
        m[1][j+10]=1;
        m[2][j+10]=1;
        m[4][j+10]=1;
        m[5][j+10]=1;
        m[7][j+10]=1;
        m[8][j+10]=1;
    }
    m[3][7+10]=1;
    m[3][8+10]=1;
    m[6][7+10]=1;
    m[6][8+10]=1;

    // 1 ------------------
    for(int i=1; i<9; i++){
        m[i][5+20]=1;
        m[i][6+20]=1;
    }

    // 2 ------------------
    for(int j=1; j<9; j++){
        m[1][j+30]=1;
        m[2][j+30]=1;
        m[4][j+30]=1;
        m[5][j+30]=1;
        m[7][j+30]=1;
        m[8][j+30]=1;
    }
    m[3][7+30]=1;
    m[3][8+30]=1;
    m[6][1+30]=1;
    m[6][2+30]=1;
}

void animacao(int m[LIN][TAM])
{
    for(int i=1; i<9; i++){
        m[i][0]=1;
    }
    for(int j=1; j<7; j++){
        m[1][j]=1;
        m[2][j]=1;
        m[4][j]=1;
        m[5][j]=1;
        m[7][j]=1;
        m[8][j]=1;
    }
    m[3][7]=1;
    m[6][7]=1;

    for(int j=2; j<8; j++){
        m[1][j+10]=1;
    }
    for(int j=1; j<9; j++){
        m[2][j+10]=1;
    }
    for(int j=2; j<8; j++){
        m[8][j+10]=1;
    }
    for(int j=1; j<9; j++){
        m[7][j+10]=1;
    }
    for(int i=2; i<8; i++){
        m[i][1+10]=1;
        m[i][2+10]=1;
        m[i][7+10]=1;
        m[i][8+10]=1;
    }

    for(int j=2; j<8; j++){
        m[1][j+20]=1;
    }
    for(int j=1; j<9; j++){
        m[2][j+20]=1;
    }
    for(int j=2; j<8; j++){
        m[8][j+20]=1;
    }
    for(int j=1; j<9; j++){
        m[7][j+20]=1;
    }
    for(int i=2; i<8; i++){
        m[i][1+20]=1;
        m[i][2+20]=1;
        m[i][7+20]=1;
        m[i][8+20]=1;
    }

    for(int i=1; i<9; i++){
        m[i][0+30]=1;
        m[i][1+30]=1;
        m[i][7+30]=1;
        m[i][8+30]=1;
    }
        m[2][2+30]=1;
        m[3][3+30]=1;
        m[4][4+30]=1;
        m[3][5+30]=1;
        m[2][6+30]=1;
}

void explosao()
{
    zera(mtx);
    Desenha(12, mtx);

    for(int i=0; i<20; i++){
        while(kbhit()){
            int ch=getch();
            if(ch==27){
                system("cls");
                exit(0);
                }
            }

        display(1, mtx, 50, VERMELHO, PRETO);
        displayAnimacao(f1);
        Sleep(100);

        display(1, mtx, 50, LIGHT_RED, PRETO);
        displayAnimacao(f2);
        Sleep(100);

        display(1, mtx, 50, YELLOW, PRETO);
        displayAnimacao(f3);
        Sleep(100);

        display(1, mtx, 50, WHITE, PRETO);
        displayAnimacao(f4);
        Sleep(100);

        display(1, mtx, 50, VERMELHO, PRETO);
        displayAnimacao(f5);
        Sleep(100);

        display(1, mtx, 50, LIGHT_RED, PRETO);
        displayAnimacao(f6);
        Sleep(100);
    }
}
