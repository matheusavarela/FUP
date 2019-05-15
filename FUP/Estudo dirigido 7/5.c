	#include<stdio.h>
	#define T 10
	int main(){
		int v[T];
		int i, qtd=0;	
		for(i=0;i<T;i=i+1){
			printf("Informe um número:");
			scanf("%d", &v[i]);
		}
		for(i=0;i<T;i=i+1)
			if(v[i]>50){
				printf("%d -",i);
				qtd=qtd+1;
			}
		if(qtd==0)
			printf("Não existem números superiores a 50");
	}