#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cm, m;
    printf("Digite um comprimento em centimetros:\n");
    scanf("%f", &cm);
    m = cm/100;
    printf("\nO valor %f em metros é %.2f", cm, m);
    return 0;
}
