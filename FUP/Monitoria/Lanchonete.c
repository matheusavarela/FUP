#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,cod, qnt, nvpedido, nvlanche;
    char cliente[50];
    float custo = 0, lucro = 0;
    do{

        system("clear");
        custo = 0;
        printf("Nome do cliente\n");
        scanf("%s", cliente);

        do{
        printf("\nDigite o código:\n");
        scanf("%d", &cod);
        printf("\nDigite a quantidade:\n");
        scanf("%d", &qnt);

        switch(cod){
            case 1:

                custo = custo + (2.00*qnt);
                break;
            case 2:

                custo = custo + (2.50*qnt);
                break;
            case 3:

                custo = custo + (4.00*qnt);
                break;
            case 4:

                custo = custo + (3.50*qnt);
                break;
            case 5:

                custo = custo + (3.00*qnt);
                break;
        }
        printf("\nDeseja fazer outro pedido:\n?");
        printf("\n1-Sim\n");
        printf("\n0-Não\n");
        scanf("%d", &nvlanche);

        }while(nvlanche==1);
        printf("\nSr(a) %s o custo foi de %.2f", cliente, custo);
        lucro = lucro + custo;
        printf("\nDeseeja continuar?(sim = 1)(não = 0)");
        scanf("%d", &nvpedido);
    }while(nvpedido==1);
        printf("\nO lucro do dia foi de R$%.2f", lucro);



    }




