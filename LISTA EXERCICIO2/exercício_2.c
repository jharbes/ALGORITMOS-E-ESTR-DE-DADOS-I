#include <stdio.h>
#include <time.h>

typedef struct No No;

struct No{
    int dado;
    No *prox;
}*ini=NULL;

int menu(){
    int op;
    printf("Escolha: \n1 - Inserir no inicio da lista. \n2 - Inserir no final da lista. \n3 - Imprimir. \n4 - Alterar lista \n0 - Finalizar. \nOpcao: ");
    scanf("%d", &op);
    return op;
}

void inserir_ini(int num){
    No *novo;
    novo = (No*) malloc(sizeof(No));

    novo->dado = num;

    novo->prox = ini;
    ini = novo;
    printf("\nNUMERO INSERIDO COM SUCESSO\n\n");
}

void inserir_fim(int num){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->dado = num;

    if(ini==NULL){
        novo->prox=ini;
        ini=novo;
    }else{
        No *aux = ini;
        while (aux->prox != NULL) aux=aux->prox;
        novo->prox=NULL;
        aux->prox=novo;
    }
    printf("\nNUMERO INSERIDO COM SUCESSO\n\n");
}

void imprimir(){
    printf("\n");
    No *aux = ini;
    if(aux != NULL){
        printf("+----------------------------------------------------------------------+\n| Lista:");
        while (aux != NULL){
            printf(" %d ", aux->dado);
            aux=aux->prox;
        }
        printf("\n+----------------------------------------------------------------------+\n");
    }else printf("Lista vazia\n");

    printf("\n");
}

void alterar(int num, int posicao){
    No *aux = ini;
    int cont=1;

    while (cont<posicao){
        cont++;
        aux=aux->prox;
    }
    aux->dado = num;
    printf("\n\nO NUMERO FOI ALTERADO COM SUCESSO, CONFIRA A LISTA ATUALIZADA.");
    imprimir();
    sleep(3);
}

int main(){
    system("cls");
    int op, num, posicao, num_elementos=0;
    do{
        op=menu();
        switch (op){
        case 1: // INSERE NO INICIO DA LISTA
            printf("\nInforme um numero para ser inserido no inicio da lista: ");
            scanf("%d", &num);
            inserir_ini(num);
            num_elementos++; // soma na quantdadede elementos inseridos
        break;
        case 2: // INSERE NO FINAL DA LISTA
            printf("\nInforme um numero para ser inserido no fim da lista: ");
            scanf("%d", &num);
            inserir_fim(num);
            num_elementos++; // soma na quantdadede elementos inseridos
        break;
        case 3: // IMPRIME A LISTA
            imprimir(); 
        break;
        case 4: // ALTERA A LISTA
            if(ini!=NULL){
                printf("\nObserve a situacao atual da lista.\n\n");

                imprimir();
                sleep(2);

                do{
                   printf("\nInforme a posicao do elemento que deseja alterar.");
                   printf("\n** NAO E PERMITIDA A ENTRADA DE VALORES MAIORES QUE A QUANTIDADE DE ELEMENTOS DA LISTA (Elementos: %d) OU MENORES QUE 1 **", num_elementos);
                   printf("\n(Ex.: Primeiro item, digite 1; Segundo item, digite 2, etc): ");
                   scanf("%d", &posicao);
                }while( posicao>num_elementos || posicao<1 );

                printf("\nAgora, informe o valor que deseja substituir na posicao %d da lista: ", posicao);
                scanf("%d", &num);
                alterar(num, posicao);
            }else{
                printf("\nA lista esta vazia.\nInsira pelo menos um elemento para esta opcao.\n\n");
            }
        break;

        case 0: // SAI DO SISTEMA
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|          SAINDO DO SISTEMA          |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            sleep(2);
        break;

        default:
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|  OPCAO NAO RECONHECIDA PELO SISTEMA |\n");
            printf("|    INFORME UMA OPCAO ENTRE 0 E 4    |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
        break;
        }
    }while (op);
}