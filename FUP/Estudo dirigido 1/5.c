#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sbruto, ir, inss, sliquido;
    printf("Digite seu sálario Bruto\n");
    scanf("%f", &sbruto);
    ir = sbruto * 0.20;
    inss = (sbruto-ir)*0.10;
    sliquido = sbruto-ir-inss;
    printf("O slário líquido é de R$%.2f",sliquido);
    return 0;
}
