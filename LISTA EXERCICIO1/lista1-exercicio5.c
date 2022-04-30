#include <stdio.h>
#include <string.h>
#include <math.h>


int main() {
//declarando variaveis

    struct pessoa{
        char nome[30];
        int idade;
        char sexo;
        float peso;
    };


    struct pessoa a;

//rodando programa

    strcpy(a.nome,"maria dolores castro");
    a.idade=40;
    a.sexo='f';
    a.peso=78.5;

    printf("Os valores informados sao: \n\n");

    printf("NOME= %s\n",a.nome);
    printf("IDADE= %i\n",a.idade);
    printf("SEXO= %c\n",a.sexo);
    printf("PESO= %f\n",a.peso);

    return 0;
}
