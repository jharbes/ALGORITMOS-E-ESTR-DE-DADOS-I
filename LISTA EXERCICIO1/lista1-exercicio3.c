#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
//declarando variaveis
    float n1,n2,n3;
    char tipo;
//rodando programa

    float calculo(float a,float b,float c,char d){
        float media=0;
        switch(d){
            case 'a':
                media=(a+b+c)/3; break;
            case 'p':
                media=(a*5+b*3+c*2)/10; break;
            case 'h':
                media=3/((1/a)+(1/b)+(1/c)); break;
            case 'A':
                media=(a+b+c)/3; break;
            case 'P':
                media=(a*5+b*3+c*2)/10; break;
            case 'H':
                media=3/((1/a)+(1/b)+(1/c)); break;
            default:
                printf("Opcao invalida");
        }
        return media;
    }

    printf("INFORME AS NOTAS DO ALUNO PARA O CALCULO DE SUA MEDIA.\n\n");

    printf("Informe a primeira nota do aluno: ");
    scanf("%f",&n1);
    printf("\n");

    printf("Informe a segunda nota do aluno: ");
    scanf("%f",&n2);
    printf("\n");

    printf("Informe a terceira nota do aluno: ");
    scanf("%f",&n3);
    printf("\n");

    printf("Informeo tipo de media a ser calculada(A para aritmetica, P para ponderada e H para harmonica: ");
    scanf(" %c",&tipo);
    printf("\n");

    if (calculo(n1,n2,n3,tipo)!=0)
        printf("A media solicitada eh igual a %f.\n\n",calculo(n1,n2,n3,tipo));


    return 0;
}
