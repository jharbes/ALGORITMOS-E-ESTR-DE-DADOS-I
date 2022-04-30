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
    printf("ESCOLHA A OPCAO: \n1- INSERIR ELEMENTO NA LISTA. \n2- IMPRIMIR LISTA. \n3- BUSCAR ELEMENTO NA LISTA. \n4- ALTERAR ELEMENTO. \n5- EXCLUIR UM ELEMENTO. \n6- EXCLUIR LISTA. \n0- FIM. \n\nOPCAO: ");
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
    printf("\n** NUMERO INCLUIDO COM SUCESSO**\n\n");
}

void imprimir(){
    No *aux = ini;

    printf("LISTA ATUAL:");
    while (aux != NULL){
        printf(" %d ", aux->dado);
        aux = aux->ant;
    }
    printf("\n\n");
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
        printf("\n\nNUMERO ALTERADO.\n\n");
    }else
        printf("\nNUMERO NAO ESTA NA LISTA.\n\n");
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
        printf("\n\nO NUMERO FOI EXCLUIDO COM SUCESSO, CONFIRA A LISTA ATUALIZADA.\n");
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
        printf("\nLISTA VAZIA.\n\n");
        return 0;
    }
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1:
            printf("\nINFORME VALOR A SER INCLUIDO: ");
            scanf("%d", &num);
            inserir(num);
        break;
        case 2:
            if(verifica_lista())
                imprimir();
        break;
        case 3: {
            if(verifica_lista()){
                int num_busca;
                printf("\nQUAL ELEMENTO DESEJA BUSCAR: ");
                scanf("%d", &num_busca);
                No * obj = buscar(num_busca);
                if(obj!=NULL)
                    printf("\nRESULTADO: %d\n\n", obj->dado);
                else
                    printf("\nELEMENTO NAO ENCONTRADO.\n\n");
            }
            break;
        }case 4: {
            if(verifica_lista()){
                int num_alteracao, num_alvo;
                printf("\nSEGUE A LISTA.\n\n");

                imprimir();

                printf("\nINFORME QUAL DOS ELEMENTOS DESEJA ALTERAR: ");
                scanf("%d", &num_alvo);

                printf("\nINFORME O NOVO VALOR QUE DESEJA INSERIR NA LISTA: ");
                scanf("%d", &num_alteracao);
                alterar(num_alvo, num_alteracao);
                imprimir();
            }
            break;
        }case 5:{
            if(verifica_lista()){
                int num_exclusao;
                printf("\nOSEGUE LISTA ATUALIZADA.\n\n");

                imprimir();

                printf("\nINFORME O ELEMENTO QUE DESEJA EXCLUIR: ");
                scanf("%d", &num_exclusao);

                excluir_1(num_exclusao);
                imprimir();
            }
            break;
        }case 6:
            if(verifica_lista()){
                excluir_tudo();
                if(ini == NULL && fim == NULL)
                    printf("\nLISTA EXCLUIDA COM SUCESSO.\n\n");
                else
                    printf("\nERRO AO EXCLUIR\nLISTA EM BRANCO.\n");
            }
            break;
        case 0: // SAI DO SISTEMA
            printf("FIM!\n");
            break;
        default:
            printf("OPCAO NAO RECONHECIDA PELO SISTEMA, OPCOES APENAS ENTRE 0 E 6.\n");
            break;
        }
    }while(op);
}
