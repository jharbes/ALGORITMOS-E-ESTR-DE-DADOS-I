#include <stdio.h>
#include <string.h>
#include <math.h>


int main() {
//declarando variaveis

    struct complexo{
        float real;
        float imaginario;
    };


    struct complexo a,b;

//rodando programa

    float calculo(float x,float y,float w,float z){
        x=x+w;
        y=y+z;
        printf("Soma dos complexos eh: %f + %fi\n",x,y);
        return;
        }


    a.real=2;
    a.imaginario=3;
    b.real=1;
    b.imaginario=4;

    calculo(a.real,a.imaginario,b.real,b.imaginario);

    return 0;
}
