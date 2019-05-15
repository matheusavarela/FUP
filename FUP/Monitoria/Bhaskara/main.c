#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a,b,c, delta, raiz, x1, x2;
    printf("Digite valor de a de b e de c\n");
    scanf("%f %f %f", &a, &b,&c);
    delta = b*b+4*a*c;
    if (delta >=0){
    raiz = sqrt(delta);
    x1 = (-b + raiz)/2*a;
    x1 = (-b - raiz)/2*a;
    printf("X1 é:%.2f", x1);
    printf("X2 é:%.2f", x2);
    }
    else
        printf("Não existe raiz real para delta");

}
