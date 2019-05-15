	#include<stdio.h>
	#define T 5
	#define Y 20
	int main(){
		int idades[T], somaIdade=0;
		char nomes[T][Y];
		int i;
		for(i=0;i<T;i=i+1){
			printf("Informe uma idade:\n");
			scanf("%d", &idades[i]);
			somaIdade = idades[i]+somaIdade;
			
			printf("Informe um nome:\n ");
			scanf("%s",nomes[i]);
			fflush(stdin);
		}
		printf("RESPOSTA A)\n");
		for(i=0;i<T;i=i+1)
			if(idades[i]< (somaIdade/T))
				printf("%s\n", nomes[i]);
				
		printf("RESPOSTA B)\n");
		for(i=0;i<T;i=i+1)
			if((idades[i]>=18)&&(idades[i]<=65))
				printf("%s\n", nomes[i]);
	}