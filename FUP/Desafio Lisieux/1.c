/*Dada uma matriz de inteiros M x N verificar 
quantas vezes um cada elemento aparece nesta matriz*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n,k=0,l;
    int i,j,qtd=0;
    printf("Digite a quantidade de linhas da matriz");
    scanf("%d",&m);
    printf("\nDigite a quantidade de colunas da matriz");
    scanf("%d",&n);
    int aux[m*n];
    int matriz[m][n];
    for(i=0;i<m;i=i+1)
        for(j=0;j<n;j=j+1){
            printf("Elemento [%d][%d]",i,j);
            scanf("%d",&matriz[i][j]);
        }

 
    for ( i = 0; i < m; i=i+1){
        for ( j = 0; j < n; j++){
            l=matriz[i][j];
            aux[k]=l;
            k++;
        }
    }
     for(i = 0; i < k; i=i+1)
            for(j = 0; j < k-1; j=j+1)
                if(aux[j]>aux[j+1]){
                    l=aux[j];
                    aux[j]=aux[j+1];
                    aux[j+1]=l;
                
    for(int i = 0; i < k; i++){
        int cont=0;
        for(int j = 0; j < k; j++){
            if(aux[j]==aux[i]){
                if(j<i)
                    break;
                cont++;
            }
        }
        if(cont>=1){
            printf("\nO numero %d se repete %d vezes ",aux[i],cont);
        }    
    }
}