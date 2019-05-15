	#include<stdio.h>
	int main(){
		int tamanho;
		printf("Informe a quantidade de números  que serão lidos: \n");
		scanf("%d", &tamanho);
		int v[tamanho];
		int i;
		
		for(i=0;i<tamanho;i++){
			printf("Informe o número da posicão %d", i);
			scanf("%d", &v[i]);
		}
		for(i=0;i<tamanho;i++)
			printf("%d ", v[i]);
		
	}