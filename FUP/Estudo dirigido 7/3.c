	#include<stdio.h>
	#define T 10
	int main(){
		int v[T];
		int i, x, qtd=0;
		
		for(i=0;i<T;i=i+1){
			printf("Informe um número\n: ");
			scanf("%d", &v[i]);
		}
		
		printf("Informe o elemento a ser pesquisado\n:");
		scanf("%d", &x);
		
		for(i=0;i<T;i=i+1)
			if(x == v[i])
				qtd=qtd+1;
		printf("A quantidade de ocorrencias de x em v = %d\n", qtd);	
	}