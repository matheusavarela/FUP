#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior = 0, x = 1;
    while(x>0){
        printf("Informe um número:");
        scanf("%d", &x);
        if(x>maior)
            maior = x;

    }
}
