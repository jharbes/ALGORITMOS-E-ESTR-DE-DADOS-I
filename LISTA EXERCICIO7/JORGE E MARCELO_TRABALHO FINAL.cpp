#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct Node{
 int number;
 char name[50];
 char cpf[11];
 int hour;
 int minute;
 int seconds;
 int day;
 int month;
 int year;
 struct Node *next;
};
typedef struct Node node;

struct tm *currentTIME;

int lineNUMBER = 0;
int size;

int menu(void);
void option(node *LINE, int op);
void start(node *LINE);
int empty(node *LINE);
node * allocate();
void insert(node *LINE);
node *trash(node *LINE);
void show(node *LINE);
void free(node *LINE);


int main(void)
{
 setlocale(LC_ALL, "Portuguese");
 printf("Bem-vindo ao sistema do Banco Harbes Santos!\n\n");
 node *LINE = (node *) malloc(sizeof(node));
 if(!LINE){
  printf("Sem memória disponível!\n");
  exit(1);
 }else{
 start(LINE);
 int opt;

 do{
  opt=menu();
  option(LINE,opt);
 }while(opt);

 free(LINE);
 return 0;
 }
}


int menu(void)
{
 int opt;

 printf("\nO que deseja fazer?\n\n1 - Pegar nova senha\n2 - Mostrar clientes na fila\n3 - Registrar atendimento no caixa\n4 - Registrar desistência de cliente\n5 - Apagar toda a fila \n0 - Sair do programa\n");
 printf("\nOpção escolhida: "); 
 scanf("%d", &opt);

 return opt;
}

void option(node *LINE, int op)
{
 node *tmp;
 switch(op){
  case 0:
   free(LINE);
   break;

  case 1:
   insert(LINE);
   printf("\n\nNova senha adicionada a fila!\n\n");
   break;

  case 2:
   show(LINE);
   break;

  case 3:
   tmp= trash(LINE);
   if(tmp != NULL){
    printf("\nO Cliente da senha %d foi atendido pelo caixa!\n\n", tmp->number);
    free(tmp);
    getchar();
   }
   break;

  case 4:
   tmp= trash(LINE);
   if(tmp != NULL){
    printf("\nO Cliente da senha %d desistiu do atendimento!\n\n", tmp->number);
    free(tmp);
    getchar();
   }
   break;

  case 5:
   free(LINE);
   start(LINE);
   printf("\nA fila foi esvaziada!\n\n");
   break;

  default:
   printf("Comando inválido\n\n");
 }
}

void start(node *LINE)
{
 LINE->next = NULL;
 size=0;
}

int empty(node *LINE)
{
 if(LINE->next == NULL)
  return 1;
 else
  return 0;
}

node * allocate()
{
 node *nu=(node *) malloc(sizeof(node));
 if(!nu){
  printf("Sem memória disponível!\n");
  exit(1);
 }else{
  lineNUMBER++;
  nu->number = lineNUMBER;
  printf("\nQual o nome do cliente?\n"); 
  getchar();
  gets (nu->name);
  printf("\nQual o CPF do cliente?\n");  
  gets(nu->cpf);
  time_t seconds; 
  time(&seconds);    
  currentTIME = localtime(&seconds);  
  nu->hour = currentTIME->tm_hour;
  nu->minute = currentTIME->tm_min;
  nu->seconds = currentTIME->tm_sec;
  nu->day = currentTIME->tm_mday;
  nu->month = currentTIME->tm_mon+1;
  nu->year = currentTIME->tm_year+1900;
  return nu;
 }
}

void insert(node *LINE)
{
 node *nu= allocate();
 nu->next = NULL;

 if(empty(LINE))
  LINE->next=nu;
 else{
  node *tmp = LINE->next;

  while(tmp->next != NULL)
   tmp = tmp->next;

  tmp->next = nu;
 }
 size++;
}


node *trash(node *LINE)
{
 if(LINE->next == NULL){
  printf("\nA fila já está vazia!\n");
  getchar();
  return NULL;
 }else{
  node *tmp = LINE->next;
  LINE->next = tmp->next;
  size--;
  return tmp;
 }

}


void show(node *LINE)
{
 int i;
 if(empty(LINE)){
  printf("\nA fila está vazia!\n\n");
  getchar();
  return ;
 }

 node *tmp;
 tmp = LINE->next;
 printf("\n\nFila atual :");
 while( tmp != NULL){
  printf("\n\n\n%d\n\nCPF:     ", tmp->number);
  for (i = 0; i < 11; i++) {
        printf("%c", tmp->cpf[i]);
  }
  printf("\nNome:    ");  	
  puts (tmp->name);
  printf("Senha retirada às %02d:%02d:%02d de %02d/%02d/%02d",tmp->hour, tmp->minute, tmp->seconds, tmp->day, tmp->month, tmp->year);
  tmp = tmp->next;
 }

 printf("\n\n");
 getchar();
}

void free(node *LINE)
{
 if(!empty(LINE)){
  node *nextNode,
     *current;

  current = LINE->next;
  while(current != NULL){
   nextNode = current->next;
   free(current);
   current = nextNode;
  }
 }
}

