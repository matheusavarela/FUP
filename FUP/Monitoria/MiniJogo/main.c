#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



int main(){

	char nome[20], nomeTop[20] = "------";
	int opcao, operacao, qtdOperacoes;
	int pontos, resposta, gabarito, pontMaxima=0;
	int num1, num2, i;



	int maxSomaSubt = 50;
	int maxMult = 10;
	int maxDiv = 100;

	srand(time(NULL));

	do{

		pontos=0;


		system("clear");


		printf("\t# M47H M1N1 G4M3 #\n\n");



		do{

			printf("    MENU\n");
			printf("1 - Nova partida\n");
			printf("2 - Pontuacao maxima\n");
			printf("0 - Sair\n\n");

			printf("Opcao: ");
			scanf("%d", &opcao);

			if(opcao!=0 && opcao!=1 && opcao!=2){

				printf("\nOpcao invalida!\n\n");
			}

		}while(opcao!=0 && opcao!=1 && opcao!=2);

		if(opcao==0){

			return 0; 		}

		printf("\n");


		system("clear");

		if(opcao==1){

			printf("\t# M47H M1N1 G4M3 #\n\n");

			printf("Digite seu nome: ");
			scanf("%s", nome);

			printf("\n");

			do{


				printf("    OPERACAO\n");
				printf("1 - Soma (+)\n");
				printf("2 - Subtracao (-)\n");
				printf("3 - Multiplicacao (*)\n");
				printf("4 - Divisao (/)\n\n");

				printf("Opcao: ");
				scanf("%d", &operacao);

				if(operacao!=1 && operacao!=2 && operacao!= 3 && operacao!=4){

					printf("\nOperacao invalida!\n\n");
				}

			}while(operacao!=1 && operacao!=2 && operacao!= 3 && operacao!=4);



			do{

				printf("\nDigite a quantidade de operacoes: ");
				scanf("%d", &qtdOperacoes);

				if(qtdOperacoes<1){

					printf("\nQuantidade invalida!\n\n");
				}

			}while(qtdOperacoes<1);

			printf("\n");


			system("clear");

			printf("\t# M47H M1N1 G4M3 #\n\n");



			if(operacao==1){

				for(i=0; i<qtdOperacoes; i++){



					num1 = rand() % maxSomaSubt+1;
					num2 = rand() % maxSomaSubt+1;

					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);

					printf("%d + %d = ", num1, num2);
					scanf("%d", &resposta);

					gabarito = num1+num2;
					if(resposta==gabarito){

						++pontos;
						printf("Correto!\n");
					}
					else{

						printf("Errou: %d\n", gabarito);
					}

					printf("\n");
				}
			}



			if(operacao==2){

				for(i=0; i<qtdOperacoes; i++){



					num1 = rand() % maxSomaSubt+1;
					num2 = rand() % maxSomaSubt+1;

					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);

					printf("%d - %d = ", num1, num2);
					scanf("%d", &resposta);

					gabarito = num1-num2;

					if(resposta==gabarito){

						++pontos;
						printf("Correto!\n");
					}
					else{

						printf("Errou: %d\n", gabarito);
					}

					printf("\n");
				}
			}



			if(operacao==3){

				for(i=0; i<qtdOperacoes; i++){



					num1 = rand() % 10+1;
					num2 = rand() % 10+1;

					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);

					printf("%d * %d = ", num1, num2);
					scanf("%d", &resposta);

					gabarito = num1*num2;

					if(resposta==gabarito){

						++pontos;
						printf("Correto!\n");
					}
					else{

						printf("Errou: %d\n", gabarito);
					}

					printf("\n");
				}
			}



			if(operacao==4){

				for(i=0; i<qtdOperacoes; i++){

					do{



						num1 = rand() % 100+1;
						num2 = rand() % 100+1;

					}while(num1%num2!=0);

					printf("OPERACAO #%d de %d\n", i+1, qtdOperacoes);

					printf("%d / %d = ", num1, num2);
					scanf("%d", &resposta);

					gabarito = num1/num2;

					if(resposta==gabarito){

						++pontos;
						printf("Correto!\n");
					}
					else{

						printf("Errou: %d\n", gabarito);
					}

					printf("\n");
				}
			}

			if(pontos>pontMaxima){

				pontMaxima = pontos;
				strcpy(nomeTop, nome);
			}

			printf("PONTUACAO: %d de %d\n", pontos, qtdOperacoes);

			printf("\n");

			do{

				printf("O que deseja fazer?\n");
				printf("1 - Menu\n");
				printf("0 - Sair\n\n");

				printf("Opcao: ");
				scanf("%d", &opcao);

				if(opcao!=0 && opcao!=1){

					printf("\nOpcao invalida!\n\n");
				}

			}while(opcao!=0 && opcao!=1);
		}
		else
		if(opcao==2){


			system("clear");

			printf("\t# M47H M1N1 G4M3 #\n\n");

			printf("PONTUACAO MAXIMA:\n");
			printf("Jogador: %s\n", nomeTop);
			printf("Pontos: %d\n\n", pontMaxima);

			do{
				printf("O que deseja fazer?\n");
				printf("1 - Menu\n");
				printf("0 - Sair\n\n");

				printf("Opcao: ");
				scanf("%d", &opcao);

				if(opcao!=0 && opcao!=1){

					printf("\nOpcao invalida!\n\n");
				}

			}while(opcao!=0 && opcao!=1);
		}

	}while(opcao!=0);

	return 0;
}
