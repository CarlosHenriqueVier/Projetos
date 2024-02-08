#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGEM "imagem.bmp"
#define NOVAIMAGEM "nova_imagem.bmp"
#define BYTESPIXEL 3

//struct cabecalho
//struct dados da imagem

//criar dois arquivos
//imagem original
//imagem nova

//leitura dos dados de cabecalho e imagem da imagem
//armazenar dados na struct

//escrita dos dados de cabecalho da struct na imagem nova



typedef struct cabecalho{
    unsigned short int tipo; //2 bytes
    unsigned long int tam; //4 bytes
    unsigned long int res; // 4 byte (2 reservados + 2 reservados)
    unsigned long int desloc; //4 bytes
}CAB;

typedef struct dados{
    unsigned long int tamanhoBinario;
    unsigned long int largura;
    unsigned long int altura;
    unsigned short int planos;
    unsigned short int bits_pixel;
    unsigned long int compressao;
    unsigned long int tamanhoImagem;
    unsigned long int res_horizontal;
    unsigned long int res_vertical;
    unsigned long int n_cores;
    unsigned long int n_cores_importantes;
}DADOS;

int interface_usuario(int array)
{
    int aux[2];
    if(array==0){
        printf("-- DESEJAS RETIRAR OU DEIXAR APENAS UMA COR --\n\n");
        printf(" [0] - DEIXAR COR\n");
        printf(" [1] - RETIRAR COR\n");
        printf(" [2] - DEIXAR PRETO E BRANCO\n");
        printf(" [3] - EFEITO DE BORRAR (FRACO)\n");
        printf(" [4] - EFEITO DE BORRAR (FORTE)\n");
        printf(" [5] - COPIAR IMAGEM\n");
        printf(" [6] - BORDA 3X3\n");
        printf(" [7] - BORDA 9X9\n");
        printf(" [8] - PROCURAR PIXEL\n");
        scanf("%i", &aux[0]);

        system("cls");
    }
    if(array==1){
        if(aux[0]==0){
            printf("-- MENU DE ESCOLHA DE CORES --\n\n");
            printf(" [0] - Deixar o azul\n");
            printf(" [1] - Deixar o verde\n");
            printf(" [2] - Deixar o vermelho\n");
            scanf("%i", &aux[1]);
        }
        if(aux[0]==1){
            printf("-- MENU DE ESCOLHA DE CORES --\n\n");
            printf(" [0] - Borda azul\n");
            printf(" [1] - Borda verde\n");
            printf(" [2] - Borda vermelho\n");
            scanf("%i", &aux[1]);
        }
        if(aux[0]==6 || aux[0]==7){
            printf("-- MENU DE ESCOLHA DE CORES --\n\n");
            printf(" [0] - Borda azul\n");
            printf(" [1] - Borda verde\n");
            printf(" [2] - Borda vermelha\n");
            scanf("%i", &aux[1]);
        }
        system("cls");
    }
    return aux[array];
}

unsigned int efeito_borrar3x3(unsigned char *pixels, int i, unsigned long int largura)
{
    unsigned int media_pixels;

    media_pixels= (pixels[i] + pixels[i+1] + pixels[i+2])/3;
    media_pixels+= (pixels[i+BYTESPIXEL]+pixels[i+BYTESPIXEL+1]+pixels[i+BYTESPIXEL+2])/3;//pixel a direita
    media_pixels+= (pixels[i-BYTESPIXEL]+pixels[i-BYTESPIXEL+1]+pixels[i-BYTESPIXEL+2])/3;//pixel a esquerda
    media_pixels+= (pixels[i+(largura*3)]+pixels[i+1+(largura*3)]+pixels[i+2+(largura*3)])/3;//pixel abaixo
    media_pixels+= (pixels[i+(largura*3)+BYTESPIXEL]+pixels[i+BYTESPIXEL+1+(largura*3)]+pixels[i+BYTESPIXEL+2+(largura*3)])/3;
    media_pixels+= (pixels[i+(largura*3)-BYTESPIXEL]+pixels[i-BYTESPIXEL+1+(largura*3)]+pixels[i-BYTESPIXEL+2+(largura*3)])/3;
    media_pixels+= (pixels[i-(largura*3)]+pixels[i+1-(largura*3)]+pixels[i+2-(largura*3)])/3;//pixel acima
    media_pixels+= (pixels[i-(largura*3)-BYTESPIXEL]+pixels[i-BYTESPIXEL+1-(largura*3)]+pixels[i-BYTESPIXEL+2-(largura*3)])/3;
    media_pixels+= (pixels[i-(largura*3)+BYTESPIXEL]+pixels[i+BYTESPIXEL+1-(largura*3)]+pixels[i+BYTESPIXEL+2-(largura*3)])/3;

    return media_pixels /= 9;
}

unsigned int efeito_borrar9x9(unsigned char *pixels, int i, unsigned long int largura)
{
    unsigned int media_pixels;

    media_pixels= (pixels[i] + pixels[i+1] + pixels[i+2])/3; //pixel ref
    // pixels a direita
    media_pixels+= (pixels[i+BYTESPIXEL]+pixels[i+BYTESPIXEL+1]+pixels[i+BYTESPIXEL+2])/3;
    media_pixels+= (pixels[i+(BYTESPIXEL*2)]+pixels[i+(BYTESPIXEL*2)+1]+pixels[i+(BYTESPIXEL*2)+2])/3;
    media_pixels+= (pixels[i+(BYTESPIXEL*3)]+pixels[i+(BYTESPIXEL*3)+1]+pixels[i+(BYTESPIXEL*3)+2])/3;
    media_pixels+= (pixels[i+(BYTESPIXEL*4)]+pixels[i+(BYTESPIXEL*4)+1]+pixels[i+(BYTESPIXEL*4)+2])/3;

    // pixels a esquerda
    media_pixels+= (pixels[i-BYTESPIXEL]+pixels[i-BYTESPIXEL+1]+pixels[i-BYTESPIXEL+2])/3;
    media_pixels+= (pixels[i-(BYTESPIXEL*2)]+pixels[i-(BYTESPIXEL*2)+1]+pixels[i-(BYTESPIXEL*2)+2])/3;
    media_pixels+= (pixels[i-(BYTESPIXEL*3)]+pixels[i-(BYTESPIXEL*3)+1]+pixels[i-(BYTESPIXEL*3)+2])/3;
    media_pixels+= (pixels[i-(BYTESPIXEL*4)]+pixels[i-(BYTESPIXEL*4)+1]+pixels[i-(BYTESPIXEL*4)+2])/3;

    //pixels abaixo
    media_pixels+= (pixels[i+(largura*3)]+pixels[i+1+(largura*3)]+pixels[i+2+(largura*3)])/3;
    media_pixels+= (pixels[i+(largura*3*2)]+pixels[i+1+(largura*3*2)]+pixels[i+2+(largura*3*2)])/3;
    media_pixels+= (pixels[i+(largura*3*3)]+pixels[i+1+(largura*3*3)]+pixels[i+2+(largura*3*3)])/3;
    media_pixels+= (pixels[i+(largura*3*4)]+pixels[i+1+(largura*3*4)]+pixels[i+2+(largura*3*4)])/3;

    //pixels acima
    media_pixels+= (pixels[i-(largura*3)]+pixels[i+1-(largura*3)]+pixels[i+2-(largura*3)])/3;
    media_pixels+= (pixels[i-(largura*3*2)]+pixels[i+1-(largura*3*2)]+pixels[i+2-(largura*3*2)])/3;
    media_pixels+= (pixels[i-(largura*3*3)]+pixels[i+1-(largura*3*3)]+pixels[i+2-(largura*3*3)])/3;
    media_pixels+= (pixels[i-(largura*3*4)]+pixels[i+1-(largura*3*4)]+pixels[i+2-(largura*3*4)])/3;

    // pixels diagonal direita baixo
    media_pixels+= (pixels[i+(largura*3)+BYTESPIXEL]+pixels[i+BYTESPIXEL+1+(largura*3)]+pixels[i+BYTESPIXEL+2+(largura*3)])/3;
    media_pixels+= (pixels[i+(largura*3*2)+(BYTESPIXEL*2)]+pixels[i+(BYTESPIXEL*2)+1+(largura*3*2)]+pixels[i+(BYTESPIXEL*2)+2+(largura*3*2)])/3;
    media_pixels+= (pixels[i+(largura*3*3)+(BYTESPIXEL*3)]+pixels[i+(BYTESPIXEL*3)+1+(largura*3*3)]+pixels[i+(BYTESPIXEL*3)+2+(largura*3*3)])/3;
    media_pixels+= (pixels[i+(largura*3*4)+(BYTESPIXEL*4)]+pixels[i+(BYTESPIXEL*4)+1+(largura*3*4)]+pixels[i+(BYTESPIXEL*4)+2+(largura*3*4)])/3;

    // pixels diagonal esquerda baixo
    media_pixels+= (pixels[i+(largura*3)-BYTESPIXEL]+pixels[i-BYTESPIXEL+1+(largura*3)]+pixels[i-BYTESPIXEL+2+(largura*3)])/3;
    media_pixels+= (pixels[i+(largura*3*2)-(BYTESPIXEL*2)]+pixels[i-(BYTESPIXEL*2)+1+(largura*3*2)]+pixels[i-(BYTESPIXEL*2)+2+(largura*3*2)])/3;
    media_pixels+= (pixels[i+(largura*3*3)-(BYTESPIXEL*3)]+pixels[i-(BYTESPIXEL*3)+1+(largura*3*3)]+pixels[i-(BYTESPIXEL*3)+2+(largura*3*3)])/3;
    media_pixels+= (pixels[i+(largura*3*4)-(BYTESPIXEL*4)]+pixels[i-(BYTESPIXEL*4)+1+(largura*3*4)]+pixels[i-(BYTESPIXEL*4)+2+(largura*3*4)])/3;

    // pixels diagonal cima esquerda
    media_pixels+= (pixels[i-(largura*3)-BYTESPIXEL]+pixels[i-BYTESPIXEL+1-(largura*3)]+pixels[i-BYTESPIXEL+2-(largura*3)])/3;
    media_pixels+= (pixels[i-(largura*3*2)-(BYTESPIXEL*2)]+pixels[i-(BYTESPIXEL*2)+1-(largura*3*2)]+pixels[i-(BYTESPIXEL*2)+2-(largura*3*2)])/3;
    media_pixels+= (pixels[i-(largura*3*3)-(BYTESPIXEL*3)]+pixels[i-(BYTESPIXEL*3)+1-(largura*3*3)]+pixels[i-(BYTESPIXEL*3)+2-(largura*3*3)])/3;
    media_pixels+= (pixels[i-(largura*3*4)-(BYTESPIXEL*4)]+pixels[i-(BYTESPIXEL*4)+1-(largura*3*4)]+pixels[i-(BYTESPIXEL*4)+2-(largura*3*4)])/3;

    // pixels diagonal baixo esquerda
    media_pixels+= (pixels[i-(largura*3)+BYTESPIXEL]+pixels[i+BYTESPIXEL+1-(largura*3)]+pixels[i+BYTESPIXEL+2-(largura*3)])/3;
    media_pixels+= (pixels[i-(largura*3*2)+(BYTESPIXEL*2)]+pixels[i+(BYTESPIXEL*2)+1-(largura*3*2)]+pixels[i+(BYTESPIXEL*2)+2-(largura*3*2)])/3;
    media_pixels+= (pixels[i-(largura*3*3)+(BYTESPIXEL*3)]+pixels[i+(BYTESPIXEL*3)+1-(largura*3*3)]+pixels[i+(BYTESPIXEL*3)+2-(largura*3*3)])/3;
    media_pixels+= (pixels[i-(largura*3*4)+(BYTESPIXEL*4)]+pixels[i+(BYTESPIXEL*4)+1-(largura*3*4)]+pixels[i+(BYTESPIXEL*4)+2-(largura*3*4)])/3;

    return media_pixels /= 27;
}

void set_pixels(unsigned char *pixels, int i, int b, int g, int r)
{
    pixels[i] = b;
    pixels[i+1] = g;
    pixels[i+2] = r;
}

void procura_pixel(unsigned char *pixels, unsigned long int tam_img, int b, int g, int r)
{
    for(int i=0; i<tam_img; i+=3){
        if(pixels[i]==b && pixels[i+1]==g && pixels[i+2]==r){
            printf("%ix%i\n", i/(300*3)+1, (i%300*3)*170*3);
        }
    }
}

void desenha_circulo(unsigned char *pixels)
{
    for(int i=0; i<150; i+=3){
        set_pixels(pixels, 3000+i, 0, 0, 255);
        set_pixels(pixels, 3000+i+(900*114), 0, 0, 255);

    }
}

int main()
{
    //arquivos de imagem utilizados
    FILE *imagem;
    FILE *nova_imagem;

    // variaveis que armazenam os dados de cabecalho da imagem original
    DADOS dados_imagem;
    CAB cabecalho_imagem;

    // abre a imagem
    imagem = fopen(IMAGEM, "rb");
    if(imagem == NULL)printf("Nao foi possivel abrir o arquivo de imagem");

    //le os dados de cabecalho
    fread(&cabecalho_imagem, 14, 1, imagem);
    fread(&dados_imagem, 40, 1, imagem);

    // analisando a imagem em um editor de hexa percebi pelo padrao dos bytes
    // que a imagem tinha 3 bytes por pixel, pois o padrao se repetia a cada tres bytes

    // le as informacoes dos pixels
    unsigned long int tam_img = dados_imagem.altura * dados_imagem.largura * BYTESPIXEL; // armazena o o tamnho de bytes necessários para exibir a imagem ->
    // altura da imagem * largura da imagem * numero de bytes por pixel (3)
    unsigned char *pixels = (unsigned char*) malloc(tam_img); // aloca espaco na memoria
    fseek(imagem, 54, SEEK_SET);
    fread(pixels, tam_img, 1, imagem); // leitura dos pixels da imagem original

    fclose(imagem);

////////////////////////////////////////////////////////////////////////////////////////////

    // abre nova imagem
    nova_imagem = fopen(NOVAIMAGEM, "wb");
    if(nova_imagem == NULL)printf("Nao foi possivel abrir um novo arquivo de imagem");

    // escreve os dados de cabecalho na nova imagem
    fwrite(&cabecalho_imagem, 14, 1, nova_imagem);
    fwrite(&dados_imagem, 40, 1, nova_imagem);

    printf("%i", dados_imagem.bits_pixel);
    // escreve e modifica o valor dos pixels da imagem original na imagem nova
    int op = interface_usuario(0);
    int cor_escolhida = interface_usuario(1);
    unsigned int media_pixels;


    fseek(nova_imagem, 0, SEEK_CUR);
    //desloca o ponteiro até o segundo pixel da segunda linha de pixels
    for(int i = 0; i<tam_img; i+=BYTESPIXEL){
        switch(op){
            case 0: //deixar cor
            switch(cor_escolhida){
                case 0:
                pixels[i+1]=0;
                pixels[i+2]=0;
                break;
                case 1:
                pixels[i+0]=0;
                pixels[i+2]=0;
                break;
                case 2:
                pixels[i+0]=0;
                pixels[i+1]=0;
                break;
            }
            break;
            case 1: //tirar cor
                pixels[i+cor_escolhida]=0;
                break;
            case 2: //preto e branco
                media_pixels = (pixels[i] + pixels[i+1] + pixels[i+2])/3;
                set_pixels(pixels, i, media_pixels, media_pixels, media_pixels);
                break;
            case 3: //borrar
                media_pixels = efeito_borrar3x3(pixels, i, dados_imagem.largura);
                set_pixels(pixels, i, media_pixels, media_pixels, media_pixels);
                break;
            case 4:
                media_pixels = efeito_borrar9x9(pixels, i, dados_imagem.largura);
                set_pixels(pixels, i, media_pixels, media_pixels, media_pixels);
                break;
            case 5:
            // n faz nada (cópia)
            break;
            case 6:
            //borda 3x3
                if(i<dados_imagem.largura*BYTESPIXEL*3 || i>(tam_img-(dados_imagem.largura*BYTESPIXEL*3))){
                    switch(cor_escolhida){
                        case 0:
                            set_pixels(pixels, i, 255, 0, 0);
                            break;
                        case 1:
                            set_pixels(pixels, i, 0, 255, 0);
                            break;
                        case 2:
                            set_pixels(pixels, i, 0, 0, 255);
                            break;
                }
                }
                if(i%(dados_imagem.largura*BYTESPIXEL)==0 || i%(dados_imagem.largura*BYTESPIXEL)==3 || i%(dados_imagem.largura*BYTESPIXEL)==6){
                    switch(cor_escolhida){
                        case 0:
                            set_pixels(pixels, i, 255, 0, 0);
                            set_pixels(pixels, i-9, 255, 0, 0);
                            break;
                        case 1:
                            set_pixels(pixels, i, 0, 255, 0);
                            set_pixels(pixels, i-9, 0, 255, 0);
                            break;
                        case 2:
                            set_pixels(pixels, i, 0, 0, 255);
                            set_pixels(pixels, i-9, 0, 0, 255);
                            break;
                }
                }
                break;
            case 7:
                if(i<dados_imagem.largura*BYTESPIXEL*9 || i>(tam_img-(dados_imagem.largura*BYTESPIXEL*9))){
                    switch(cor_escolhida){
                        case 0:
                            set_pixels(pixels, i, 255, 0, 0);
                            break;
                        case 1:
                            set_pixels(pixels, i, 0, 255, 0);
                            break;
                        case 2:
                            set_pixels(pixels, i, 0, 0, 255);
                            break;
                }
                }
                if(i%(dados_imagem.largura*BYTESPIXEL)==0 || i%(dados_imagem.largura*BYTESPIXEL)==3 || i%(dados_imagem.largura*BYTESPIXEL)==6 || i%(dados_imagem.largura*BYTESPIXEL)==9 || i%(dados_imagem.largura*BYTESPIXEL)==12 || i%(dados_imagem.largura*BYTESPIXEL)==15 || i%(dados_imagem.largura*BYTESPIXEL)==18 || i%(dados_imagem.largura*BYTESPIXEL)==21 || i%(dados_imagem.largura*BYTESPIXEL)==24){
                    switch(cor_escolhida){
                        case 0:
                            set_pixels(pixels, i, 255, 0, 0);
                            set_pixels(pixels, i-27, 255, 0, 0);
                            break;
                        case 1:
                            set_pixels(pixels, i, 0, 255, 0);
                            set_pixels(pixels, i-27, 0, 255, 0);
                            break;
                        case 2:
                            set_pixels(pixels, i, 0, 0, 255);
                            set_pixels(pixels, i-27, 0, 0, 255);
                            break;
                    }
            }
                break;
        }
    }


    desenha_circulo(pixels);

    if(op==8){
        printf("Digite a intensidade do pixel vermelho\n");
        int red;
        scanf("%i", &red);
        printf("Digite a intensidade do pixel verde\n");
        int green;
        scanf("%i", &green);
        printf("Digite a intensidade do pixel azul\n");
        int blue;
        scanf("%i", &blue);
        procura_pixel(pixels, tam_img, blue, green, red);
    }

    fwrite(pixels, tam_img, 1, nova_imagem);
    fclose(nova_imagem);

    return 0;
}
