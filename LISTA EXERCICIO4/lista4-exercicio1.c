#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No No;

struct No{
    int dado;
    No *prox;
    No *ant;
}*ini=NULL, *fim=NULL;

int menu(){
    int op;
    printf("OPCOES: \n1- INSERIR ELEMENTO. \n2- IMPRIMIR LISTA. \n3- PROCURAR ELEMENTO. \n4- ALTERAR ELEMENTO. \n0- FIM. \n\nESCOLHA A OPCAO: ");
    scanf("%d", &op);
    return op;
}

void inserir(int num){
    No *novo;
    novo = (No*) malloc(sizeof(No));

    if(ini==NULL){
        novo->dado = num;
        novo->prox = ini;
        novo->ant = fim;
        ini = fim = novo;
    }else{
        novo->dado = num;
        novo->prox = ini;
        novo->ant = NULL;
        novo->prox->ant = novo;
        ini = novo;
    }
    printf("\nNUMERO INSERIDO COM SUCESSO\n\n");
}

void imprimir(){
    printf("\n");
    No *aux = ini;
    if(aux != NULL){
        printf("\nLISTA: ");
        while (aux != NULL){
            printf(" %d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n\n");
    }else printf("LISTA VAZIA\n");

    printf("\n");
}

No * buscar(int num_busca){
    No *aux_ini = ini;
    No *aux_fim = fim;
    No *retorno=NULL;

    if(ini!=NULL)
        do{
            if(aux_ini->dado==num_busca){
                retorno = aux_ini;
                break;
            }else if(aux_fim->dado==num_busca){
                retorno = aux_fim;
                break;
            }else{
                aux_ini=aux_ini->prox;
                aux_fim=aux_fim->ant;
            }
        }while (aux_ini->ant!=aux_fim->prox && aux_ini->ant!=aux_fim);
    return retorno;
}

void alterar(int num_alvo, int num_alterar){
    No *aux;
    aux = buscar(num_alvo);
    if(aux!=NULL){
        aux->dado = num_alterar;
        printf("\n\nO NUMERO FOI ALTERADO COM SUCESSO, CONFIRA A LISTA ATUALIZADA.");
    }else
        printf("\nERRO. NUMERO INFORMADO NAO ENCONTRADO.\n\n");
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1: // INSERE NA LISTA
            printf("\nQUAL VALOR A SER INCLUIDO NA LISTA: ");
            scanf("%d", &num);
            inserir(num);
        break;
        case 2:
            imprimir();
        break;
        case 3: {
            int num_busca;
            printf("\nQUAL VALOR DESEJA PROCURAR: ");
            scanf("%d", &num_busca);
            No * obj = buscar(num_busca);
            if(obj!=NULL){
                printf("\nNUMERO BUSCADO: %d\n\n", obj->dado);
            }else{
                printf("\nERRO. NUMERO INFORMADO NAO ENCONTRADO.\n\n");
            }
            break;
        }case 4: {
            if(ini){
                int num_alteracao, num_alvo;
                printf("\nLISTA ATUALIZADA.\n\n");
                imprimir();
                printf("\nQUAL NUMERO DESEJA ALTERAR: ");
                scanf("%d", &num_alvo);
                printf("\nQUAL NOVO NUMERO DESEJA INFORMAR: ");
                scanf("%d", &num_alteracao);
                alterar(num_alvo, num_alteracao);
                imprimir();
            }else
                printf("\nLISTA VAZIA.\n\n");
            break;
        }case 0:
            printf("\nFIM\n\n");
            break;
        default:
            printf("\nFAVOR INFORMAR UMA OPCAO ENTRE 0 e 5\n\n");
            break;
        }
    }while(op);
}
