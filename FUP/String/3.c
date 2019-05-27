#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char A[50],B[50],C[100];
    int i,tam,j=0;
    printf("\n1ª string:");
    gets(A);
    printf("\n2ª string:");
    gets(B);
    tam = strlen(A)+strlen(B);
    printf("%d\n",tam);
    for ( i = 0; i < tam; i++){
        if(i%2==0){
            C[i]=A[j];
            j++;
        }
        if(i%2==1){
            C[i]=B[j-1];
            
        }
    }
    C[i]='\0';
    puts(C);
    

}