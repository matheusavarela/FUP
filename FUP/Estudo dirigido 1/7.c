#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kmi, kmf, capacidade, lgastos, preco, custo, mkm, kmlitro;
    printf("Digite a quilometragem inicial\n");
    scanf("%f", &kmi);
    printf("Digite a quilometragem final\n");
    scanf("%f", &kmf);
    printf("Digite a quantidade de litros gastos\n");
    scanf("%f", &lgastos);
    printf("Digite a capacidade do tanque\n");
    scanf("%f", &capacidade);
    printf("Digite o preço do combustível\n");
    scanf("%f", &preco);
    mkm = kmf - kmi;
    kmlitro = mkm/lgastos;
    custo = lgastos*preco;
    printf("A quilometragem rodada foi de %.3f km",mkm);
    printf("O carro faz em média %.3f km por litro", kmlitro);
    printf("O custo da viagem foi de R$%.2f",custo);


    return 0;
}
