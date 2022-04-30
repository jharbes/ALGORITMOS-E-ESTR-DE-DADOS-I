#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
//declarando variaveis
    float x1,y1,x2,y2;
//rodando programa

    float distancia(float a,float b,float c,float d){
        return sqrt((a-c)*(a-c)+(b-d)*(b-d));
        }

    printf("ENTRE COM DOIS PONTOS PARA CALCULO DA DISTANCIA ENTRE ELES.\n\n");

    printf("Entre com o valor de X1: ");
    scanf("%f",&x1);
    printf("\n");

    printf("Entre com o valor de X2: ");
    scanf("%f",&x2);
    printf("\n");

    printf("Entre com o valor de Y1: ");
    scanf("%f",&y1);
    printf("\n");

    printf("Entre com o valor de Y2: ");
    scanf("%f",&y2);
    printf("\n");

    printf("O valor da distancia entre os pontos solicitados eh: %f",distancia(x1,y1,x2,y2));


    return 0;
}
