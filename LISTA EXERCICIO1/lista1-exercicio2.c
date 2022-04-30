#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
//declarando variaveis
    int x,y,z,w,v;
//rodando programa

    int captura(int a){
        printf("Entre com o numero: ");
        scanf("%i",&a);
        if (a>0)
            return a;
        else{
            printf("VALOR INVALIDO, TENTE NOVAMENTE: ");
            while (a<=0)
                scanf("%i",&a);
            return a;
            }
        }

    int SomaDivisores(int a){
        int b=0;
        for (int i=(a-1);i>=1;i--){
            if(a%i==0)
                b=b+i;
        }
        return b;
        }

    printf("ENTRE COM CINCO INTEIROS POSITIVOS PARA OBTER A SOMA DE SEUS DIVISORES.\n\n");

    x=captura(x);
    y=captura(y);
    z=captura(z);
    w=captura(w);
    v=captura(v);

    printf("Os numeros sao: %i %i %i %i %i\n\n",x,y,z,w,v);

    printf("A soma dos divisores de cada um dos numeros sao: %i %i %i %i %i\n\n",SomaDivisores(x),SomaDivisores(y),SomaDivisores(z),SomaDivisores(w),SomaDivisores(v));


    return 0;
}
