#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i;
    float s;
    printf("Digite um número inteiro\n");
    scanf("%d", &n);
    s = 0.0;
    if(n==0){
        printf("Somatória = 1");
    }
    else{
    for (i=1;i<=n; i=i+1){
        s= s + 1/pow(i,i);


    }
    printf("O valor da somatória é : %.5f", s);
    }
}
