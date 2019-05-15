	#include<stdio.h>
	int main(){
		float nota1,nota2, media, mediaTurma, maiorMedia=0;
		int i, qtdAprovados=0;	
		float somaMedia=0;
		
		for(i=1; i<=5; i=i+1){
			printf("Informe sua primeira nota e segunda nota: ");
			scanf("%f %f", &nota1, &nota2);	
			media = (nota1+nota2)/2;
			somaMedia = somaMedia + media;
			if(media>=8)
				qtdAprovados = qtdAprovados+1;
			if(media>maiorMedia)
				maiorMedia = media;
		}
		mediaTurma = somaMedia/5;
		printf("Média da turma = %.2f\n", mediaTurma);
		printf("A quantidade de aprovados = %d alunos\n", qtdAprovados);
		printf("A maior média = %.2f", maiorMedia);
	}
