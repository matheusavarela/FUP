#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char letra[1],string[50],auxiliar[50],a='*';
    int tam,i;
    printf("\nTexto:");
    gets(string);
    printf("\nLetra:");
    gets(letra);
    tam = strlen(string);
    
    for(i=0;i<tam;i++){
        if (string[i]==letra[0])
        {
            auxiliar[i]='*';
        }
        else
            auxiliar[i]=string[i];

        
    }
    puts(auxiliar);



}