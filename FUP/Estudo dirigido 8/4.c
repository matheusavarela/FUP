#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j;
    int m[3][3],soma=0;
    for (i = 0; i < 3; i++)
        for (j =0; j < 3; j++)
            m[i][j]=rand() % 20;
    
    printf("Matriz A:\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            printf(" %d ", m[i][j]);        
        printf("\n");
    }
    j=3-1;
    for (i = 0; i < 3; i++){
        soma = soma + m[i][j];
        printf(" %d\n",m[i][j]);
        j--;
    }
    printf("\nSoma = %d",soma);

            
}