#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i, qtd, x, j;
    printf("Informe o número de elementos\n");
    scanf("%d", &x);
    for(j=0; j<x;j=j+1){
        printf("Informe um número\n");
        scanf("%d",&n);
        qtd=0;
        for(i=2;i<n;i=i+1){

            if(n%i==0)
                qtd=1;
        }
        if(qtd)
            printf("Número não é primo");
        else
            printf("Número primo");



    }
}
