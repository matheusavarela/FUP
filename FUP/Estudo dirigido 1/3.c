#include <stdio.h>
#include <stdlib.h>

int main()
{
    float gastos, gorgeta, despesa;
    printf("Digite o valor gasto:\n");
    scanf("%f", &gastos);
    gorgeta = gastos*0.10;
    despesa = gastos + gorgeta;
    printf("\nOvalor total da despesa foi de R$%.2f e a gorgeta foi de R$%.2f",despesa, gorgeta);
    return 0;
}
