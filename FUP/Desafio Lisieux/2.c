/*Faça um programa que simule o sorteio de seis números entre 1 e 90, inclusive. Imprima-os.
 Os números devem ser apresentados em ordem crescente de valor e não poderá haver repetição.*/
#include<stdio.h>
#include<stdlib.h>
#define VALIDO 0
#define INVALIDO 1
int main(){
    int vetor[6];
    int i,j,status,aux;
    for (i = 0; i < 6; ++i) {
        do {
            vetor[i] = (rand()%90)+1;
            status = VALIDO;
            for (j = 0; j < i; ++j)
                if (vetor[i] == vetor[j])
                    status = INVALIDO;
        } while (status == INVALIDO);

    }
    for(i = 0; i < 6; i++)
            for(j = 0; j < 6-1; j++)
                if(vetor[j]>vetor[j+1]){
                    aux=vetor[j];
                    vetor[j]=vetor[j+1];
                    vetor[j+1]=aux;
                }
    for(i=0;i<6;i=i+1)
        printf(" %d ",vetor[i]);            
}