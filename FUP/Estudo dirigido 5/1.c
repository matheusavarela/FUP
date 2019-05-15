#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i, fat;
    printf("Digite o número a ser fatorado\n");
    scanf("%d",&n);
    if(n >= 0){
        if((n==0)||(n==1))
            printf("O fatorial de %d é 1",n);
        else{
            fat = 1;
            for(i=n;i>=1; i=i-1){
            fat = i*fat;

            }
        printf("%d", fat);
        }
    }
    else
        printf("Digite valores válidos");


}
