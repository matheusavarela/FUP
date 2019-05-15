#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[200];
    float slfixo, tvendas, comissao, slfinal;
    printf("Digite seu nome:\n");
    scanf("%s",nome);
    printf("\nDigite o salário fixo:");
    scanf("%f", &slfixo);
    printf("\nDigite o total de vendas(Em dinheiro)");
    scanf("%f",&tvendas);
    comissao = tvendas*0.15;
    slfinal = comissao+slfixo+tvendas;
    printf("%c seu salaŕio fixo é de R$%.2f e o salário total foi de R$%.2f!",nome, slfixo, slfinal);
}
