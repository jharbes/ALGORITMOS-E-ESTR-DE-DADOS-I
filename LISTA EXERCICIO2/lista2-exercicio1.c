#include <stdio.h>
#include <stdlib.h>

typedef struct No no;

struct No{
    int dado;
    struct No *prox;

} *ini=NULL;

no* criar_no(){
    no *novo=(no*)malloc(sizeof(no));
    return novo;
}

no* inserir_ini(no* lista,int num){
    no *novo_no=criar_no();
    novo_no->dado=num;

    if (lista==NULL){
        lista=novo_no;
        novo_no->prox=NULL;
    }
    else{
        novo_no->prox=lista;
        lista=novo_no;
    }
    return lista;
    }


no* inserir_fim(no* lista,int num){
    no *novo_no=criar_no();
    novo_no->dado=num;

    if(lista==NULL){
        novo_no->prox=NULL;
        lista=novo_no;
    }
    else{
        no* aux=lista;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        novo_no->prox=NULL;
        aux->prox=novo_no;
    }
    return lista;
    }

void alterar(no* lista,int num,int posicao){
    no* aux=lista;
    int cont=1;

    while (cont<posicao){
        cont++;
        aux=aux->prox;
    }
    aux->dado=num;
}


void imprimir(no* lista){
    no *aux=lista;

    while(aux!=NULL){
        printf("%i ",aux->dado);
        aux=aux->prox;
    }
    }




int main(){

    char opcao;
    int x,y,k=0;

    no *lista=NULL;

    MENU:

    printf("Escolha a opcao:\n1- Inserir elemento no inicio.\n2- Inserir elemento no fim.\n3- Imprimir lista.\n4- Alterar elemento.\n5- Fim.\n\n");
    printf("OPCAO: ");
    scanf(" %c",&opcao);
    switch(opcao){
        case '1':
            printf("Digite o valor solicitado: ");
            scanf("%i",&x);
            lista=inserir_ini(lista,x);
            k++;
            goto MENU;
        case '2':
            printf("Digite o valor solicitado: ");
            scanf("%i",&x);
            lista=inserir_fim(lista,x);
            k++;
            goto MENU;
        case '3':
            printf("Segue a lista: ");
            imprimir(lista);
            printf("\n\n\n");
            goto MENU;
        case '4':
            printf("Digite a posicao a ser alterada: ");
            scanf("%i",&x);
            while(x<1 || x>k){
                printf("Posicao invalida, favor corrigir.\n");
                printf("Digite a posicao a ser alterada: ");
                scanf("%i",&x);
            }
            printf("Digite o valor novo para a alteracao: ");
            scanf("%i",&y);
            alterar(lista,y,x);
            goto MENU;
        case '5':
            break;
    }



return 0;

}
