#include<stdio.h>
int main(){
    int n;
    
    scanf("%d",&n);
    if(n>=12)
        printf("O custo é de %.2f",n/1.0);
    if(n>=12)
        printf("O custo é de %.2f",n/1.3);
    if(n<0)
        printf("Valor inválido!");               
}
