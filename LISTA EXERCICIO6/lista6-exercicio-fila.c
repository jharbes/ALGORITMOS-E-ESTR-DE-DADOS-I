/* Lista duplamente encadeada para que possa correr em ambos os sentidos,
do inicio para o fim e do fim para o inicio igualmente. */

#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void)
{
 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("MEMORIA INDISPONIVEL!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;

 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void inicia(node *LISTA)
{
 LISTA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;

 printf("ESCOLHA A OPCAO:\n\n");
 printf("0- FIM\n");
 printf("1- APAGAR LISTA\n");
 printf("2. IMPRIMIR\n");
 printf("3. INCLUIR ELEMENTO NO INICIO\n");
 printf("4. INCLUIR ELEMENTO NO FINAL\n");
 printf("5. OPTAR POR ONDE INSERIR ELEMENTO\n");
 printf("6. APAGAR ELEMENTO NO INICIO\n");
 printf("7. APAGAR ELEMENTO NO FIM\n");
 printf("8. OPTAR ONDE APAGAR ELEMENTO\n\n");
 printf("OPCAO: "); scanf("%d", &opt);

 return opt;
}

void opcao(node *LISTA, int op)
{
 node *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   break;

  case 1:
   libera(LISTA);
   inicia(LISTA);
   break;

  case 2:
   exibe(LISTA);
   break;

  case 3:
   insereInicio(LISTA);
   break;

  case 4:
   insereFim(LISTA);
   break;

  case 5:
   insere(LISTA);
   break;

  case 6:
   tmp= retiraInicio(LISTA);
   printf("APAGADO: %3d\n\n", tmp->num);
   break;

  case 7:
   tmp= retiraFim(LISTA);
   printf("APAGADO: %3d\n\n", tmp->num);
   break;

  case 8:
   tmp= retira(LISTA);
   printf("APAGADO: %3d\n\n", tmp->num);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(node *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("MEMORIA INDISPONIVEL!\n");
  exit(1);
 }else{
  printf("NOVO ELEMENTO: "); scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(node *LISTA)
{
 node *novo=aloca();
 novo->prox = NULL;

 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  node *tmp = LISTA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}

void insereInicio(node *LISTA)
{
 node *novo=aloca();
 node *oldHead = LISTA->prox;

 LISTA->prox = novo;
 novo->prox = oldHead;

 tam++;
}

void exibe(node *LISTA)
{
 if(vazia(LISTA)){
  printf("LISTA SEM ELEMENTOS!\n\n");
  return ;
 }

 node *tmp;
 tmp = LISTA->prox;
 printf("LISTA:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nORDEM:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}

void libera(node *LISTA)
{
 if(!vazia(LISTA)){
  node *proxNode,
     *atual;

  atual = LISTA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void insere(node *LISTA)
{
 int pos,
  count;
 printf("EM QUAL POSICAO, [DE 1 ATE %d] DESEJA INSERIR O ELEMENTO: ", tam);
 scanf("%d", &pos);

 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   node *atual = LISTA->prox,
     *anterior=LISTA;
   node *novo=aloca();

   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }

 }else
  printf("ELEMENTO INVALIDO\n\n");
}

node *retiraInicio(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("LISTA VAZIA!\n");
  return NULL;
 }else{
  node *tmp = LISTA->prox;
  LISTA->prox = tmp->prox;
  tam--;
  return tmp;
 }

}

node *retiraFim(node *LISTA)
{
 if(LISTA->prox == NULL){
  printf("LISTA VAZIA!\n\n");
  return NULL;
 }else{
  node *ultimo = LISTA->prox,
    *penultimo = LISTA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}

node *retira(node *LISTA)
{
 int opt,
  count;
 printf("QUAL POSICAO, [DE 1 ATE %d] DESEJA RETIRAR O ELEMENTO: ", tam);
 scanf("%d", &opt);

 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   node *atual = LISTA->prox,
     *anterior=LISTA;

   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }

  anterior->prox=atual->prox;
  tam--;
  return atual;
  }

 }else{
  printf("ELEMENTO INVALIDO\n\n");
  return NULL;
 }
}
