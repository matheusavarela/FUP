#include<stdio.h>
int main(){
    int ano;
    
    scanf("%d",&ano);
    if(2019-ano>=16)
        printf("Poderá votar");
    else
        printf("Não poderá votar!");
    if(ano<0)
        printf("Valor inválido!");               
}
