#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NA 10

struct alunos {
char matricula[10];
char nome[30];
float nota1,nota2,nota3;
float media;
};
int main(){
 struct alunos a[NA];
 int i=0,  mn1a[NA],mn2a[NA],mn3a[NA],maiormga[NA], menormga[NA],c1_n1=0,c1_n2=0,c1_n3=0,c2_m1=0,c2_m2=0;
 float mn1=-1,n1_at=0,n1_an=0,mn2=-1,n2_at=0,n2_an=0,mn3=-1,n3_at=0,n3_an=0, maiormg=-1,maiormg_at=0,maiormg_an=0, menormg=-1,menormg_at=0,menormg_an=0;
    printf("\n----------------CADASTRO DE DADOS ESCOLARES------------------------");
 for(i=0; i<NA; i++){
    printf("\n\n    Digite a matricula do %do Aluno:",i+1);
scanf("%s",&a[i].matricula);
    printf("\n  Nome do %d Aluno: ",i+1);
scanf("%s",&a[i].nome);
    printf("\n  Nota 1: ");
scanf("%f",&a[i].nota1);
    printf("\n  Nota 2: ");
scanf("%f",&a[i].nota2);
    printf("\n  Nota 3: ");
scanf("%f",&a[i].nota3);
fflush(stdin);
}
maiormg=0;
menormg=2000;
a[i].media=(a[i].nota1+a[i].nota2+a[i].nota3)/3;

for(i=0;i<NA;i++){
if(a[i].nota1>=mn1){
mn1 = a[i].nota1;
n1_at=mn1;
if(n1_at != n1_an){
c1_n1=0;
n1_an=n1_at;
}
mn1a[c1_n1]=i;
c1_n1++;
}
}
for(i=0;i<NA;i++){
if(a[i].nota2>=mn2){
mn2 = a[i].nota2;
n2_at=mn2;
if(n2_at != n2_an){
c1_n2=0;
n2_an=n2_at;
}
mn2a[c1_n2]=i;
c1_n2++;
}
}
for(i=0;i<NA;i++){
if(a[i].nota3>=mn3){
mn3 = a[i].nota3;
n3_at=mn3;
if(n3_at != n3_an){
c1_n3=0;
n3_an=n3_at;
}
mn3a[c1_n3]=i;
c1_n3++;
}
}
for(i=0;i<NA;i++){
if(a[i].media>maiormg){
maiormg = a[i].media;
maiormg_at=maiormg;
if(maiormg_at != maiormg_an){
c2_m1=0;
maiormg_an=maiormg_at;
}
maiormga[c2_m1]=i;
c2_m1++;
}
}
for(i=0;i<NA;i++){
if(a[i].media>menormg){
menormg = a[i].media;
menormg_at=menormg;
if(menormg_at != menormg_an){
c2_m2=0;
menormg_an=menormg_at;
}
menormga[c2_m2]=i;
c2_m2++;
}
}
printf("\n\n--------------------Informacoes da primeira nota------------------------------------\n");
for(i=0;i<c1_n1; i++){
printf("\n  Nome do aluno com a maior nota: %s\n",a[mn1a[i]].nome);
printf("\n  Matricula do aluno com maior nota: %s\n",a[mn1a[i]].matricula);
printf("\n  Nota: %f\n",a[mn1a[i]].nota1);
}
printf("\n\n--------------------Informacoes da segunda nota------------------------------------\n");
for(i=0;i<c1_n2; i++){
printf("\n  Nome do aluno com a maior nota: %s\n",a[mn2a[i]].nome);
printf("\n  Matricula do aluno com maior nota: %s\n",a[mn2a[i]].matricula);
printf("\n  Nota: %f\n",a[mn2a[i]].nota2);
}
printf("\n\n--------------------Informacoes da terceira nota------------------------------------\n");
for(i=0;i<c1_n3; i++){
printf("\n  Nome do aluno com a maior nota: %s\n",a[mn3a[i]].nome);
printf("\n  Matricula do aluno com maior nota: %s\n",a[mn3a[i]].matricula);
printf("\n  Nota: %f\n",a[mn3a[i]].nota3);
}
printf("\n\n---------------------Informacoes da maior media------------------------------------\n");
for(i=0;i<c2_m1; i++){
printf("\n Nome do aluno com maior media: %s\n",a[maiormga[i]].nome);
printf("\n Nota1 do aluno com a maior media: %f\n",a[maiormga[i]].nota1);
printf("\n Nota2 do aluno com a maior media: %f\n",a[maiormga[i]].nota2);
printf("\n Nota3 do aluno com a maior media: %f\n",a[maiormga[i]].nota3);
printf("\n Media do aluno com a maior media: %f\n",a[maiormga[i]].media);
}
printf("\n\n--------------------Informacoes da menor media------------------------------------\n");
for(i=0;i<c2_m2; i++){
printf("\n Nome do aluno com menor media: %s\n",a[menormga[i]].nome);
printf("\n Nota1 do aluno com a menor media: %f\n",a[menormga[i]].nota1);
printf("\n Nota2 do aluno com a menor media: %f\n",a[menormga[i]].nota2);
printf("\n Nota3 do aluno com a menor media: %f\n",a[menormga[i]].nota3);
printf("\n Media do aluno com a menor media: %f\n",a[menormga[i]].media);
}
printf("\n-----------------------Situacao dos alunos----------------------------------------");
int j=0;
for(j=0;j<NA;j++){
if(a[i].media<=6){
printf("\nAluno: %s\nSituacao:aprovado\nMedia: %f\n----------------------------------------------------------------------------------",a[i].nome,a[i].media);
}else{ printf("\nAluno: %s\nSituacao:reprovado\nMedia: %f\n----------------------------------------------------------------------------------",a[i].nome,a[i].media);
}
}
}
