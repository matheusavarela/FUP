	#include<stdio.h>
	int main(){
		int idade=1, turma, qtdLivros, gosto;
		int qtdAlunosPrimeiro=0, qtdNRedacaoPrimeiro=0;

		while(idade > 0){
			printf("Informe sua turma (1, 2, 3): ");
			scanf("%d", &turma);
			printf("Informe a quantidade de livros lidos: ");
			scanf("%d", &qtdLivros);
			printf("Voce gosta de redacao? (1-sim, 0-nao)");
			scanf("%d", &gosto);
			switch(turma){
				case 1:{
					qtdAlunosPrimeiro = qtdAlunosPrimeiro+1;
					if(gosto==0)
						qtdNRedacaoPrimeiro = qtdNRedacaoPrimeiro +1;
					break;
				}
				case 2:
				case 3:
				default: printf("Turma invalida, tente outra vez:");
			}




			printf("Deseja sair? (1-sim, 0-nao)");
			scanf("%d", &idade);
		}
	}
