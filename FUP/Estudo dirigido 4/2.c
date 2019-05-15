#include<stdio.h>
#include<string.h>
int main(){
	char nome[10], nomeMaiorPont[10];
	float pontuacao, maiorPont =0;
	int i;
	for (i=1; i<=8;i=i+1){
		printf("Informe a pontuacão: ");
		scanf("%f", &pontuacao);
		printf("Informe o nome: ");
		scanf("%s", nome);
		if(pontuacao>maiorPont){
			maiorPont = pontuacao;
			strcpy(nomeMaiorPont, nome);
		}
	}
	printf("O vencedor foi %s, com %.2f de pontuacão", nomeMaiorPont, maiorPont);
}
