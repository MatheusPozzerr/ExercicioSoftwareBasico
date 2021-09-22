#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "readline.h"
#define nome_len 40
#define nacionalidade_len 40
#define url_len 300

typedef struct
{
  int dia;
  int mes;
  int ano;
} date;

struct compuPessoas
{
    char nome[nome_len+1];
    char nacionalidade[nacionalidade_len+1];
    char urlImagem[url_len+1];
    date dataNascimento;

} personalidades[11];


int numPersonalidades = 0 ;

void insert(void);
void order(void);
void calcula(void);
void print(void);


int main(void){
    bool testing = false;
    //Alan Turing, ingles, https://upload.wikimedia.org/wikipedia/commons/thumb/a/a1/Alan_Turing_Aged_16.jpg/200px-Alan_Turing_Aged_16.jpg, 23-06-1912
    //Richard Stallman, americano, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQuCC4hcZeo7OxD7WPYvxqtSjhhHl0LwzV2mw&usqp=CAU , 15-03-1953
    //Edsger Dijkstra, holandes, http://1.bp.blogspot.com/-ok6cWc2Z-ug/Tft1MKADMjI/AAAAAAAAAB4/C60Soe_4U44/w1200-h630-p-k-no-nu/edsger_dijkstra5.jpg ,11-05-1930
    //Charles Babbage, ingles,https://miro.medium.com/max/500/1*XWTVc_GoKWRR_cjnFhGVDQ.jpeg, 26-12-1871
    //John Von Neumann, hungaro, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTKmqd8X83fbp0htEkiDwQ-8l6iDkl6arFALw&usqp=CAU ,28-12-1903
    //Bill Gates,americano , 28-10-1955  
    //

    date date1= {23,06,1912};
    personalidades[0].dataNascimento.dia = 23; 
    personalidades[0].dataNascimento.mes = 06;
    personalidades[0].dataNascimento.ano = 1912;
    personalidades[1].dataNascimento.ano = 1920;
    personalidades[2].dataNascimento.ano = 1930;
    numPersonalidades = 3;
    char code;
    while (testing == false){
    printf("Menu: \n");
    printf("Digite 0 para finalizar o programa.\nDigite 1 para inserir uma personalidade; \nDigite 2 para previsao do ano de nascimento da proxima personalidade;\nDigite 3 para mostrar na tela os dados das personalidades da computacao cadastradas;\n");
    scanf("%c", &code);
    switch (code) {
    case '1': insert();
    break;
    case '2': calcula();
    break;
    case '3': print();
    break;
    case '0': 
    printf("Finalizando programa...\n");
    return 0;
    default:
    if (code == ' ')
    {
      break;
    }
    printf("%c",code);
    printf("Caractere invalido\n");
}
printf("\n");
}
 
    return 0;
}

void insert(void)
{
if (numPersonalidades == 10) {
printf("Não é possível adicionar mais personalidades.\n");
return;
}
char code;
printf("Nome da Personalidade: \n");
scanf("%c", &code);
fgets(personalidades[numPersonalidades].nome, nome_len, stdin);
strtok(personalidades[numPersonalidades].nome, "\n");
printf("Sua Nacionalidade: \n");
scanf("%s", personalidades[numPersonalidades].nacionalidade);
printf("Sua Data de nascimento, colocando desta forma: dd mm yyyy: \n");
scanf("%d %d %d", &personalidades[numPersonalidades].dataNascimento.dia, &personalidades[numPersonalidades].dataNascimento.mes, &personalidades[numPersonalidades].dataNascimento.ano);
printf("A url da imagem: \n");
scanf("%s", personalidades[numPersonalidades].urlImagem);

numPersonalidades++;
return;
}

void order(void){
    int i, j, aux;
    if (numPersonalidades == 0)
    {
        return;
    }
    for( i=0; i<numPersonalidades; i++ ){
        for( j=i+1; j<numPersonalidades; j++ ){
            if( personalidades[i].dataNascimento.ano > personalidades[j].dataNascimento.ano ){
                 personalidades[11] = personalidades[i];
                 personalidades[i] = personalidades[j];
                 personalidades[j] = personalidades[11];
            }
        }
     }
    for(i=0;i<=numPersonalidades-1;i++)
    {
    printf("%d\n", personalidades[i].dataNascimento.ano);
    }     
}

void calcula(void){
    order();
    if (numPersonalidades == 0)
    {
        printf("Nao ha nenhuma personalidade cadastrada \n");
        return;
    }
    
    int media,total, soma = 0;
    for(int i=0;i<=numPersonalidades-1;i++)
    {
    soma = personalidades[i].dataNascimento.ano + soma;
    }
    media = soma/numPersonalidades;
    total = media - personalidades[0].dataNascimento.ano;

    printf("A proxima personalidade vai nascer no ano de: %d\n", personalidades[numPersonalidades-1].dataNascimento.ano + total);
    printf("-------------------------------------\n");
}


void print(void){
    printf("Quantidade de personalidades cadastradas: %d \n", numPersonalidades);
    printf("Informacoes cadastradas ate o momento: \n");
    for(int i=0;i<=numPersonalidades-1;i++)
    {
    printf("Personalidade %d: \n", i+1);
    printf("Nome: %s, nacionalidade: %s, data de nascimento: %d-%d-%d,imagem: %s\n", personalidades[i].nome, personalidades[i].nacionalidade, personalidades[i].dataNascimento.dia, 
    personalidades[i].dataNascimento.mes, personalidades[i].dataNascimento.ano,personalidades[i].urlImagem );
    printf("-------------------------------------\n");
    }  
}
