#include <stdio.h>
#include <string.h>
#include <math.h>


int main() {
//declarando variaveis

    struct Livro{
        int isbn;
        char titulo[20];
        int numeropg;
        float preco;
        int ano;
    };


    struct Livro a;

//rodando programa

    a.isbn=15;
    strcpy(a.titulo,"nossa felicidade");
    a.numeropg=50;
    a.preco=30;
    a.ano=1985;

    printf("Os valores informados sao: \n\n");

    printf("ISBN= %i\n",a.isbn);
    printf("TITULO= %s\n",a.titulo);
    printf("NUMERO DE PAGINAS= %i\n",a.numeropg);
    printf("PRECO= %f\n",a.preco);
    printf("ANO= %i\n",a.ano);

    return 0;
}
