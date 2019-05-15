	#include<stdio.h>
	#include<stdlib.h>
	#define T 10
	int main(){
		int v[T]={0}, i,qtd_par=0,qtd_impar=0;
		
		printf("\n");	
		for(i=0;i<T;i=i+1)
			v[i]= rand()%100;
			
		for(i=0;i<T;i=i+1){
			if(v[i]2%==0)
			    qtd_par++;
			else
			    qtd_impar++;
        }
        printf("Quantidade de número pares foi: %d\n", qtd_par);
        printf("Quantidade de número ímpares foi: %d\n", qtd_impar);
	}