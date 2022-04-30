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
    printf("Escolha: \n1 - Inserir. \n2 - Imprimir. \n3 - Buscar. \n4 - Alterar. \n5 - Excluir 1 item. \n6 - Excluir tudo. \n0 - Finalizar. \nOpcao: ");
    scanf("%d", &op);
    return op;
}

void inserir(int num){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->dado = num;

    if(ini==NULL){
        novo->prox = ini;
        novo->ant = fim;
        ini = fim = novo;
    }else{
        novo->prox = fim;
        novo->ant = NULL;
        novo->prox->ant = novo;
        fim = novo;
    }
    printf("\nNUMERO INSERIDO COM SUCESSO\n\n");
}

void imprimir(){
    No *aux = ini;
    
    printf("\n+----------------------------------------------------------------------+\n| Lista:");
    while (aux != NULL){
        printf(" %d ", aux->dado);
        aux = aux->ant;
    }
    printf("\n+----------------------------------------------------------------------+\n\n");
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
                aux_ini=aux_ini->ant;
                aux_fim=aux_fim->prox;
            }
        }while (aux_ini->prox!=aux_fim->ant && aux_ini->prox!=aux_fim);
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

void excluir_1(int num_alvo){
    No *aux;
    aux = buscar(num_alvo);
    if(aux!=NULL){
        if (aux->prox == NULL){ // se o proximo for igual a NULL então ta no comeco
            ini = aux->ant;
            ini->prox = NULL;
        }else if(aux->ant == NULL){ // se o anterior for igual a NULL então ta no fim
            fim = aux->prox;
            fim->ant = NULL;
        }else{
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
        }
        free(aux);
        printf("\n\nO NUMERO FOI EXCLUIDO COM SUCESSO, CONFIRA A LISTA ATUALIZADA.");
    }else
        printf("\nERRO. NUMERO INFORMADO NAO ENCONTRADO.\n\n");
}

void excluir_tudo(){
    do{
        if(ini->ant == fim->prox || ini->ant == fim){
            free(ini->ant);
            fim = ini = NULL;
        }else{
            ini = ini->ant;
            fim = fim->prox;
            free(ini->prox);
            free(fim->ant);
            ini->prox = fim->ant = NULL;
        }
    }while (ini!=NULL && fim !=NULL);
}

int verifica_lista(){
    if(ini)
        return 1;
    else{
        printf("\nLISTA VAZIA.\nInsira pelo menos um elemento para esta opcao.\n\n");
        return 0;
    }
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1: // INSERE NA LISTA
            printf("\nInforme um numero para ser inserido na lista: ");
            scanf("%d", &num);
            inserir(num);
        break;
        case 2: // IMPRIME A LISTA
            if(verifica_lista())
                imprimir();
        break;
        case 3: { // BUSCA UM VALOR
            if(verifica_lista()){
                int num_busca;
                printf("\nInforme o numero que deseja buscar: ");
                scanf("%d", &num_busca);
                No * obj = buscar(num_busca);
                if(obj!=NULL)
                    printf("\nNUMERO BUSCADO: %d\n\n", obj->dado);
                else
                    printf("\nERRO. NUMERO INFORMADO NAO ENCONTRADO.\n\n");
            }
            break;
        }case 4: { // ALTERAR
            if(verifica_lista()){
                int num_alteracao, num_alvo;
                printf("\nObserve a situacao atual da lista.\n\n");

                imprimir();
                sleep(2);

                printf("\nInforme o numero da lista que deseja substituir: ");
                scanf("%d", &num_alvo);

                printf("\nAgora, informe o novo numero que deseja inserir: ");
                scanf("%d", &num_alteracao);
                alterar(num_alvo, num_alteracao);
                imprimir();
                sleep(2);
            }
            break;
        }case 5:{ // EXCLUIR 1
            if(verifica_lista()){
                int num_exclusao;
                printf("\nObserve a situacao atual da lista.\n\n");

                imprimir();
                sleep(2);

                printf("\nInforme o numero da lista que deseja excluir: ");
                scanf("%d", &num_exclusao);

                excluir_1(num_exclusao);
                imprimir();
                sleep(2);
            }
            break;
        }case 6: // EXCLUIR TODOS
            if(verifica_lista()){
                excluir_tudo();
                if(ini == NULL && fim == NULL)
                    printf("\nLISTA EXCLUIDA COM SUCESSO.\n\n");
                else
                    printf("\nERRO AO EXCLUIR\nLista ainda preenchida.\n");
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
            printf("|    INFORME UMA OPCAO ENTRE 0 E 6    |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            break;
        }
    }while(op);
}