#include <string.h>
#include <stdio.h>
#include <stdbool.h>
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

} personalidades[10];


int numPersonalidades = 0 ;

void insert(void);
void order(void);
void calcula(void);
void print(void);
bool retorna = false;


int main(void){
    bool testing = false;
    numPersonalidades = 10;
    //Alan Turing, ingles, https://upload.wikimedia.org/wikipedia/commons/thumb/a/a1/Alan_Turing_Aged_16.jpg/200px-Alan_Turing_Aged_16.jpg, 23-06-1912
    //Richard Stallman, americano, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQuCC4hcZeo7OxD7WPYvxqtSjhhHl0LwzV2mw&usqp=CAU , 15-03-1953
    //Edsger Dijkstra, holandes, http://1.bp.blogspot.com/-ok6cWc2Z-ug/Tft1MKADMjI/AAAAAAAAAB4/C60Soe_4U44/w1200-h630-p-k-no-nu/edsger_dijkstra5.jpg ,11-05-1930
    //Charles Babbage, ingles,https://miro.medium.com/max/500/1*XWTVc_GoKWRR_cjnFhGVDQ.jpeg, 26-12-1871
    //John Von Neumann, hungaro, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTKmqd8X83fbp0htEkiDwQ-8l6iDkl6arFALw&usqp=CAU ,28-12-1903
    //Bill Gates,americano, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRvi5iTp44HHluayPLRKcotcjb1mk05hNlBNg&usqp=CAU , 28-10-1955  
    // James Gosling, canadense,https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSOwfskjg0WXrD9ATiCHZo2V7ps8Q6wZrbawQ&usqp=CAU ,19-05-1955
    // Timothy John Berners-Lee, ingles,https://www.techlise.com.br/blog/wp-content/uploads/2020/09/quem-e-tim-berners-lee.png, 12-03-1989
    // Robert Cailliau, belga, https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT_It3NNqiJb0rBG225h4IEQQWmF_n1NV-oYQ&usqp=CAU ,26-01-1947
    // Vint Cerf, americano, https://i4ada.org/wp2019/wp-content/uploads/2019/10/vinc-cerf500.jpg, 23-06-1943
    strcpy(personalidades[0].nome, "Alan Turing");
    strcpy(personalidades[0].nacionalidade, "ingles");
    strcpy(personalidades[0].urlImagem, "https://upload.wikimedia.org/wikipedia/commons/thumb/a/a1/Alan_Turing_Aged_16.jpg/200px-Alan_Turing_Aged_16.jpg");
    personalidades[0].dataNascimento.dia = 23;
    personalidades[0].dataNascimento.mes = 06;
    personalidades[0].dataNascimento.ano = 1912;
    strcpy(personalidades[1].nome, "Richard Stallman");
    strcpy(personalidades[1].nacionalidade, "americano");
    strcpy(personalidades[1].urlImagem, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQuCC4hcZeo7OxD7WPYvxqtSjhhHl0LwzV2mw&usqp=CAU");
    personalidades[1].dataNascimento.dia = 15;
    personalidades[1].dataNascimento.mes = 03;
    personalidades[1].dataNascimento.ano = 1953;
    strcpy(personalidades[2].nome, "Edsger Dijkstra");
    strcpy(personalidades[2].nacionalidade, "holandes");
    strcpy(personalidades[2].urlImagem, "http://1.bp.blogspot.com/-ok6cWc2Z-ug/Tft1MKADMjI/AAAAAAAAAB4/C60Soe_4U44/w1200-h630-p-k-no-nu/edsger_dijkstra5.jpg");
    personalidades[2].dataNascimento.dia = 11;
    personalidades[2].dataNascimento.mes = 05;
    personalidades[2].dataNascimento.ano = 1930;
    strcpy(personalidades[3].nome, "Charles Babbage");
    strcpy(personalidades[3].nacionalidade, "ingles");
    strcpy(personalidades[3].urlImagem, "https://miro.medium.com/max/500/1*XWTVc_GoKWRR_cjnFhGVDQ.jpeg");
    personalidades[3].dataNascimento.dia = 26;
    personalidades[3].dataNascimento.mes = 12;
    personalidades[3].dataNascimento.ano = 1871;
    strcpy(personalidades[4].nome, "John Von Neumann");
    strcpy(personalidades[4].nacionalidade, "hungaro");
    strcpy(personalidades[4].urlImagem, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTKmqd8X83fbp0htEkiDwQ-8l6iDkl6arFALw&usqp=CAU");
    personalidades[4].dataNascimento.dia = 28;
    personalidades[4].dataNascimento.mes = 12;
    personalidades[4].dataNascimento.ano = 1903;
    strcpy(personalidades[5].nome, "Bill Gates");
    strcpy(personalidades[5].nacionalidade, "americano");
    strcpy(personalidades[5].urlImagem, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRvi5iTp44HHluayPLRKcotcjb1mk05hNlBNg&usqp=CAU");
    personalidades[5].dataNascimento.dia = 28;
    personalidades[5].dataNascimento.mes = 10;
    personalidades[5].dataNascimento.ano = 1955;
    strcpy(personalidades[6].nome, "James Gosling");
    strcpy(personalidades[6].nacionalidade, "canadense");
    strcpy(personalidades[6].urlImagem, "https://www.techlise.com.br/blog/wp-content/uploads/2020/09/quem-e-tim-berners-lee.png");
    personalidades[6].dataNascimento.dia = 19;
    personalidades[6].dataNascimento.mes = 05;
    personalidades[6].dataNascimento.ano = 1955;
    strcpy(personalidades[7].nome, "Timothy John Berners-Lee");
    strcpy(personalidades[7].nacionalidade, "ingles");
    strcpy(personalidades[7].urlImagem, "https://www.techlise.com.br/blog/wp-content/uploads/2020/09/quem-e-tim-berners-lee.png");
    personalidades[7].dataNascimento.dia = 12;
    personalidades[7].dataNascimento.mes = 03;
    personalidades[7].dataNascimento.ano = 1989;
    strcpy(personalidades[8].nome, "Robert Cailliau");
    strcpy(personalidades[8].nacionalidade, "belga");
    strcpy(personalidades[8].urlImagem, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT_It3NNqiJb0rBG225h4IEQQWmF_n1NV-oYQ&usqp=CAU");
    personalidades[8].dataNascimento.dia = 26;
    personalidades[8].dataNascimento.mes = 01;
    personalidades[8].dataNascimento.ano = 1947;
    strcpy(personalidades[9].nome, "Vint Cerf");
    strcpy(personalidades[9].nacionalidade, "americano");
    strcpy(personalidades[9].urlImagem, "https://i4ada.org/wp2019/wp-content/uploads/2019/10/vinc-cerf500.jpg");
    personalidades[9].dataNascimento.dia = 23;
    personalidades[9].dataNascimento.mes = 06;
    personalidades[9].dataNascimento.ano = 1943;
    char code;
    while (testing == false){
    if (retorna == true)
    {
        scanf("%c", &code);
    }
    printf("Menu: \n");
    printf("Digite 0 para finalizar o programa.\nDigite 1 para previsao do ano de nascimento da proxima personalidade;\nDigite 2 para mostrar na tela os dados das personalidades da computacao cadastradas;\n");
    scanf("%c", &code);
    retorna = false;
    switch (code) {
    case '1': calcula();
    break;
    case '2': print();
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

void order(void){
    int i, j, aux;
    if (numPersonalidades == 0)
    {
        return;
    }
    for( i=0; i<numPersonalidades; i++ ){
        for( j=i; j<numPersonalidades; j++ ){
            if( personalidades[i].dataNascimento.ano < personalidades[j].dataNascimento.ano ){
                 personalidades[10] = personalidades[i];
                 personalidades[i] = personalidades[j];
                 personalidades[j] = personalidades[10];
            }
        }
     }
}

void calcula(void){
    retorna = true;
    order();
    if (numPersonalidades == 0)
    {
        printf("Nao ha nenhuma personalidade cadastrada \n");
        printf("-------------------------------------");
        return;
    }
    
    int media,total, soma = 0;
    for(int i=0;i<numPersonalidades-1;i++)
    {
    soma += personalidades[i].dataNascimento.ano - personalidades[i+1].dataNascimento.ano;
    }
    media = soma/numPersonalidades;
    total = personalidades[0].dataNascimento.ano + media;

    printf("A proxima personalidade vai nascer no ano de: %d\n", total);
    printf("-------------------------------------\n");
}


void print(void){
    retorna = true;
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
