#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Digite um número\n");
    scanf("%d", &x);
    printf("Digite mais um número\n");
    scanf("%d", &y);
    printf("\n");

    while(x<=y){
        printf("%d\n",x);
        x = x+1;

    }
}
