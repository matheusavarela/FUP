#include <stdio.h>
#include <stdlib.h>

int main()
{
    float custof, pdistri, impostos, total;
    printf("Digite o valor do custo de fábrica!\n");
    scanf("%f", &custof);
    pdistri = custof*0.28;
    impostos = custof*0.45;
    total = custof+pdistri+impostos;
    printf("\nO custo final é de R$%.2f",total);

    return 0;
}
