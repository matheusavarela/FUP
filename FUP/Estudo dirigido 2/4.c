#include<stdio.h>
int main(){
    int n1, n2;
    
    scanf("%f %f",&n1,&n2);
    if((n1+n2)/2>=6)
        printf("Aluno aprovado com média %.2f",(n1+n2)/2);
    if((n1+n2)/2<6)
        printf("Aluno reprovado com média %.2f",(n1+n2)/2);
    if(n1<0 || n2<0)
        printf("Valor inválido!");               
}
