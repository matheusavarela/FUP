#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <time.h>

#define t 4
#define tamaF 4
#define tamaM 5
#define tamaD 6

#define SUBIR 'w'
#define DESCER 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define VAZIO ' '
#define SALA '24'
FILE *ranking;

char nome[100];
int score=0;
int pontos=0;
int cad=0;
void Ranking();
void Cadastro();
void pontuacao(int code);
void Executar();
void Jogar();
void Jogar2();
void Jogar3();
void ExibirMenu();
void inicializarLabirinto();
void inicializarLabirinto2();
void inicializarLabirinto3();
void imprimirLabirinto();
void imprimirLabirinto2();
void imprimirLabirinto3();
void movimentarJogador(char movimento);
void movimentarJogador2(char movimento2);
void movimentarJogador3(char movimento3);
void Regras();
void monstro();
void poteOuro();
void poteOuro2();
void poteOuro3();
void poco1();
void poco2();
void poco3();
void poco4();
void poco5();
void poco6();
void poco7();
void sair();
void GameOver();
void atirar(char direcao);
int tam,T;

int posicaoMonsL;
int posicaoMonsC;

int linha_pote;
int coluna_pote;

int linha_poco1;
int linha_poco2;
int linha_poco3;
int linha_poco4;
int linha_poco5;
int linha_poco6;
int linha_poco7;
int coluna_poco1;
int coluna_poco2;
int coluna_poco3;
int coluna_poco4;
int coluna_poco5;
int coluna_poco6;
int coluna_poco7;

char labirinto[tamaD][tamaD];

int posicaoJogadorLinha=0, posicaoJogadorColuna=0;

void inicializarLabirinto(){
	int i,j;
	srand(time(NULL));
	for(i=0;i<tamaF;i++){
		for(j=0;j<tamaF;j++){
                labirinto[i][j] = '#'; 
            }
		}
	
	linha_poco1 = (rand()%3)+1;
	linha_poco2 = (rand()%3)+1;
	linha_poco3 = (rand()%3)+1;
	
	coluna_poco1 = (rand()%3)+1;
	coluna_poco2 = (rand()%3)+1;
	coluna_poco3 = (rand()%3)+1;
	
	while((linha_poco1==linha_poco2)&&(coluna_poco1==coluna_poco2)){
		linha_poco2 = (rand()%3)+1;
		coluna_poco2 = (rand()%3)+1;
	}
	while((linha_poco2==linha_poco3)&&(coluna_poco2==coluna_poco3)){
		linha_poco3 = (rand()%3)+1;
		coluna_poco3 = (rand()%3)+1;
	}
	while((linha_poco1==linha_poco3)&&(coluna_poco1==coluna_poco3)){
		linha_poco3 = (rand()%3)+1;
		coluna_poco3 = (rand()%3)+1;
	}
	
	labirinto[linha_poco1][coluna_poco1] = '#' ;
	labirinto[linha_poco2][coluna_poco2] = '#' ;
	labirinto[linha_poco3][coluna_poco3] = '#' ;	
	
	posicaoMonsL=(rand()%3)+1;
	posicaoMonsC=(rand()%3)+1;	
	
	while(((linha_poco1==posicaoMonsL)&&(coluna_poco1==posicaoMonsC))||((linha_poco2==posicaoMonsL)&&(coluna_poco2==posicaoMonsC))||((linha_poco3==posicaoMonsL)&&(coluna_poco3==posicaoMonsC))){
		posicaoMonsL=(rand()%3)+1;
		posicaoMonsC=(rand()%3)+1;	
	}
	
	labirinto[posicaoMonsL][posicaoMonsC] = '#' ;
	
	linha_pote = (rand()%3)+1;
	coluna_pote = (rand()%3)+1;
	
	while(((linha_poco1==linha_pote)&&(coluna_poco1==coluna_pote))||((linha_poco2==linha_pote)&&(coluna_poco2==coluna_pote))||((linha_poco3==linha_pote)&&(coluna_poco3==coluna_pote))){
		linha_pote = (rand()%3)+1;
		coluna_pote = (rand()%3)+1;	
	}
	
	while((posicaoMonsL==linha_pote)&&(posicaoMonsC==coluna_pote)){
		linha_pote = (rand()%3)+1;
		coluna_pote = (rand()%3)+1;	
	}
	
	labirinto[linha_pote][coluna_pote] = '#' ;
}

void inicializarLabirinto2(){
	int i,j;
	srand(time(NULL));
	for(i=0;i<tamaM;i++){
		for(j=0;j<tamaM;j++){
                labirinto[i][j] = '#'; 
            }
		}
	
	linha_poco1 = (rand()%4)+1;
	linha_poco2 = (rand()%4)+1;
	linha_poco3 = (rand()%4)+1;
	linha_poco4 = (rand()%4)+1;
	linha_poco5 = (rand()%4)+1;
	
	
	coluna_poco1 = (rand()%4)+1;
	coluna_poco2 = (rand()%4)+1;
	coluna_poco3 = (rand()%4)+1;
	coluna_poco4 = (rand()%4)+1;
	coluna_poco5 = (rand()%4)+1;
	
	while((linha_poco1==linha_poco2)&&(coluna_poco1==coluna_poco2)){//1,2
		linha_poco2 = (rand()%4)+1;
		coluna_poco2 = (rand()%4)+1;
	}
	while((linha_poco2==linha_poco3)&&(coluna_poco2==coluna_poco3)){//2,3
		linha_poco3 = (rand()%4)+1;
		coluna_poco3 = (rand()%4)+1;
	}
	while((linha_poco1==linha_poco3)&&(coluna_poco1==coluna_poco3)){//1,3
		linha_poco3 = (rand()%4)+1;
		coluna_poco3 = (rand()%4)+1;
	}
	while((linha_poco1==linha_poco4)&&(coluna_poco1==coluna_poco4)){//1,4
		linha_poco4 = (rand()%4)+1;
		coluna_poco4 = (rand()%4)+1;
	}
	while((linha_poco1==linha_poco5)&&(coluna_poco1==coluna_poco5)){//1,5
		linha_poco5 = (rand()%4)+1;
		coluna_poco5 = (rand()%4)+1;
	}
	while((linha_poco2==linha_poco4)&&(coluna_poco2==coluna_poco4)){//2,4
		linha_poco4 = (rand()%4)+1;
		coluna_poco4 = (rand()%4)+1;
	}
	while((linha_poco2==linha_poco5)&&(coluna_poco2==coluna_poco5)){//2,5
		linha_poco5 = (rand()%4)+1;
		coluna_poco5 = (rand()%4)+1;
	}
	while((linha_poco3==linha_poco4)&&(coluna_poco3==coluna_poco4)){//3,4
		linha_poco4 = (rand()%4)+1;
		coluna_poco4 = (rand()%4)+1;
	}
	while((linha_poco3==linha_poco5)&&(coluna_poco3==coluna_poco5)){//3,5
		linha_poco5 = (rand()%4)+1;
		coluna_poco5 = (rand()%4)+1;
	}
	while((linha_poco4==linha_poco5)&&(coluna_poco4==coluna_poco5)){//4,5
		linha_poco5 = (rand()%4)+1;
		coluna_poco5 = (rand()%4)+1;
	}
	
	labirinto[linha_poco1][coluna_poco1] = '#' ;
	labirinto[linha_poco3][coluna_poco3] = '#' ;//poço3
	labirinto[linha_poco4][coluna_poco4] = '#' ;//poço4
	labirinto[linha_poco5][coluna_poco5] = '#' ;//poço5	
	
	posicaoMonsL=(rand()%4)+1;
	posicaoMonsC=(rand()%4)+1;	
	
	while(((linha_poco1==posicaoMonsL)&&(coluna_poco1==posicaoMonsC))||((linha_poco2==posicaoMonsL)&&(coluna_poco2==posicaoMonsC))||((linha_poco3==posicaoMonsL)&&(coluna_poco3==posicaoMonsC))){
		posicaoMonsL=(rand()%4)+1;
		posicaoMonsC=(rand()%4)+1;	
	}//no caso isso não precisa ja que o hup e o poço podem ficar na mesma casa
	
	labirinto[posicaoMonsL][posicaoMonsC] = '#' ;
	
	linha_pote = (rand()%4)+1;
	coluna_pote = (rand()%4)+1;
	
	while(((linha_poco1==linha_pote)&&(coluna_poco1==coluna_pote))||((linha_poco2==linha_pote)&&(coluna_poco2==coluna_pote))||((linha_poco3==linha_pote)&&(coluna_poco3==coluna_pote))){
		linha_pote = (rand()%4)+1;
		coluna_pote = (rand()%4)+1;	
	}
	
	while((posicaoMonsL==linha_pote)&&(posicaoMonsC==coluna_pote)){
		linha_pote = (rand()%4)+1;
		coluna_pote = (rand()%4)+1;	
	}
	
	labirinto[linha_pote][coluna_pote] = '#' ;
}

void inicializarLabirinto3(){
	int i,j;
	srand(time(NULL));
	for(i=0;i<tamaD;i++){
		for(j=0;j<tamaD;j++){
                labirinto[i][j] = '#'; 
            }
		}
	
	linha_poco1 = (rand()%5)+1;
	linha_poco2 = (rand()%5)+1;
	linha_poco3 = (rand()%5)+1;
	linha_poco4 = (rand()%5)+1;
	linha_poco5 = (rand()%5)+1;
	linha_poco6 = (rand()%5)+1;
	linha_poco7 = (rand()%5)+1;
	
	coluna_poco1 = (rand()%5)+1;
	coluna_poco2 = (rand()%5)+1;
	coluna_poco3 = (rand()%5)+1;
	coluna_poco4 = (rand()%5)+1;
	coluna_poco5 = (rand()%5)+1;
	coluna_poco6 = (rand()%5)+1;
	coluna_poco7 = (rand()%5)+1;
	
	while((linha_poco1==linha_poco2)&&(coluna_poco1==coluna_poco2)){//1,2
		linha_poco2 = (rand()%5)+1;
		coluna_poco2 = (rand()%5)+1;
	}
	while((linha_poco2==linha_poco3)&&(coluna_poco2==coluna_poco3)){//2,3
		linha_poco3 = (rand()%5)+1;
		coluna_poco3 = (rand()%5)+1;
	}
	while((linha_poco1==linha_poco3)&&(coluna_poco1==coluna_poco3)){//1,3
		linha_poco3 = (rand()%5)+1;
		coluna_poco3 = (rand()%5)+1;
	}
	while((linha_poco1==linha_poco4)&&(coluna_poco1==coluna_poco4)){//1,4
		linha_poco4 = (rand()%5)+1;
		coluna_poco4 = (rand()%5)+1;
	}
	while((linha_poco1==linha_poco5)&&(coluna_poco1==coluna_poco5)){//1,5
		linha_poco5 = (rand()%5)+1;
		coluna_poco5 = (rand()%5)+1;
	}
	while((linha_poco2==linha_poco4)&&(coluna_poco2==coluna_poco4)){//2,4
		linha_poco4 = (rand()%5)+1;
		coluna_poco4 = (rand()%5)+1;
	}
	while((linha_poco2==linha_poco5)&&(coluna_poco2==coluna_poco5)){//2,5
		linha_poco5 = (rand()%5)+1;
		coluna_poco5 = (rand()%5)+1;
	}
	while((linha_poco3==linha_poco4)&&(coluna_poco3==coluna_poco4)){//3,4
		linha_poco4 = (rand()%5)+1;
		coluna_poco4 = (rand()%5)+1;
	}
	while((linha_poco3==linha_poco5)&&(coluna_poco3==coluna_poco5)){//3,5
		linha_poco5 = (rand()%5)+1;
		coluna_poco5 = (rand()%5)+1;
	}
	while((linha_poco4==linha_poco5)&&(coluna_poco4==coluna_poco5)){//4,5
		linha_poco5 = (rand()%5)+1;
		coluna_poco5 = (rand()%5)+1;
	}
	while((linha_poco1==linha_poco6)&&(coluna_poco1==coluna_poco6)){//1,6
		linha_poco6 = (rand()%5)+1;
		coluna_poco6 = (rand()%5)+1;
	}
	while((linha_poco1==linha_poco7)&&(coluna_poco1==coluna_poco7)){//1,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	while((linha_poco2==linha_poco6)&&(coluna_poco2==coluna_poco6)){//2,6
		linha_poco6 = (rand()%5)+1;
		coluna_poco6 = (rand()%5)+1;
	}
	while((linha_poco2==linha_poco7)&&(coluna_poco2==coluna_poco7)){//2,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	while((linha_poco3==linha_poco6)&&(coluna_poco3==coluna_poco6)){//3,6
		linha_poco6 = (rand()%5)+1;
		coluna_poco6 = (rand()%5)+1;
	}
	while((linha_poco3==linha_poco7)&&(coluna_poco3==coluna_poco7)){//3,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	while((linha_poco4==linha_poco6)&&(coluna_poco4==coluna_poco6)){//4,6
		linha_poco6 = (rand()%5)+1;
		coluna_poco6 = (rand()%5)+1;
	}
	while((linha_poco4==linha_poco7)&&(coluna_poco4==coluna_poco7)){//4,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	while((linha_poco5==linha_poco6)&&(coluna_poco5==coluna_poco6)){//5,6
		linha_poco6 = (rand()%5)+1;
		coluna_poco6 = (rand()%5)+1;
	}
	while((linha_poco5==linha_poco7)&&(coluna_poco5==coluna_poco7)){//5,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	while((linha_poco6==linha_poco7)&&(coluna_poco6==coluna_poco7)){//6,7
		linha_poco7 = (rand()%5)+1;
		coluna_poco7 = (rand()%5)+1;
	}
	
	labirinto[linha_poco1][coluna_poco1] = '#' ;
	labirinto[linha_poco2][coluna_poco2] = '#' ;
	labirinto[linha_poco3][coluna_poco3] = '#' ;
	labirinto[linha_poco4][coluna_poco4] = '#' ;
	labirinto[linha_poco5][coluna_poco5] = '#' ;
	labirinto[linha_poco6][coluna_poco6] = '#' ;	
	labirinto[linha_poco7][coluna_poco7] = '#' ;	
	
	posicaoMonsL=(rand()%3)+1;
	posicaoMonsC=(rand()%3)+1;	
	
	while(((linha_poco1==posicaoMonsL)&&(coluna_poco1==posicaoMonsC))||((linha_poco2==posicaoMonsL)&&(coluna_poco2==posicaoMonsC))||((linha_poco3==posicaoMonsL)&&(coluna_poco3==posicaoMonsC))){
		posicaoMonsL=(rand()%3)+1;
		posicaoMonsC=(rand()%3)+1;	
	}
	
	labirinto[posicaoMonsL][posicaoMonsC] = '#' ;
	
	linha_pote = (rand()%3)+1;
	coluna_pote = (rand()%3)+1;
	
	while(((linha_poco1==linha_pote)&&(coluna_poco1==coluna_pote))||((linha_poco2==linha_pote)&&(coluna_poco2==coluna_pote))||((linha_poco3==linha_pote)&&(coluna_poco3==coluna_pote))){
		linha_pote = (rand()%3)+1;
		coluna_pote = (rand()%3)+1;	
	}
	
	while((posicaoMonsL==linha_pote)&&(posicaoMonsC==coluna_pote)){
		linha_pote = (rand()%3)+1;
		coluna_pote = (rand()%3)+1;	
	}
	
	labirinto[linha_pote][coluna_pote] = '#' ;
}

void imprimirLabirinto(){
//	system("cls");
	printf("%d",score);
	int i, j;
	for(i=0; i<tamaF; i++){
        printf("\t");
		for(j=0; j<tamaF; j++){
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}	
}

void imprimirLabirinto2(){
//	system("cls");
	printf("%d\n",score);
	int i, j;
	for(i=0; i<tamaM; i++){
        printf("\t");
		for(j=0; j<tamaM; j++){
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}	
}

void imprimirLabirinto3(){
//	system("cls");
	int i, j;
	printf("\n");
	printf("%d\n",score);
	for(i=0; i<tamaD; i++){
        printf("\t");
		for(j=0; j<tamaD; j++){
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}	
}

void poteOuro(){
	if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote)){//venceu
		textcolor(WHITE);
		printf("\n");
		printf("PARABENS VOCÊ GANHOU! \nJogue agora a proxima fase\n");
		textcolor(LIGHTGRAY);
        system("pause");
        system("cls");
        pontuacao(3);
        Jogar2();
        //chamar logo o proximo nivel, no caso o inicializarLabirinto2();
	}else{
		if((posicaoJogadorLinha==linha_pote-1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em cima
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);//coloquei o sleep para o jogador ter uma rápida sensação do que está acontecendo aumentando assim a dificuldade
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote-1)){//fedor a esquerda
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote+1)){//fedor a direita
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote+1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em baixo
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }	
	}
}

void poteOuro2(){
	if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote)){//venceu
		textcolor(WHITE);
		printf("\n");
		printf("PARABENS VOCÊ GANHOU! \nJogue agora a proxima fase\n");
		textcolor(LIGHTGRAY);
        system("pause");
        system("cls");
        pontuacao(3);
        Jogar3();
        //chamar logo o proximo nivel, no caso o inicializarLabirinto2();
	}else{
		if((posicaoJogadorLinha==linha_pote-1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em cima
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);//coloquei o sleep para o jogador ter uma rápida sensação do que está acontecendo aumentando assim a dificuldade
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote-1)){//fedor a esquerda
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote+1)){//fedor a direita
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote+1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em baixo
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }	
	}
}

void poteOuro3(){
	if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote)){//venceu
		textcolor(WHITE);
		printf("\n");
		printf("PARABENS VOCÊ GANHOU O JOGO! \n");
		textcolor(LIGHTGRAY);
        system("pause");
        system("cls");
        pontuacao(3);
        ExibirMenu();
        //chamar logo o proximo nivel, no caso o inicializarLabirinto2();
	}else{
		if((posicaoJogadorLinha==linha_pote-1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em cima
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);//coloquei o sleep para o jogador ter uma rápida sensação do que está acontecendo aumentando assim a dificuldade
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote-1)){//fedor a esquerda
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote)&&(posicaoJogadorColuna==coluna_pote+1)){//fedor a direita
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==linha_pote+1)&&(posicaoJogadorColuna==coluna_pote)){//fedor em baixo
            textcolor(YELLOW);
            printf("BRILHO ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }	
	}
}

void monstro(){
	if((posicaoJogadorLinha==posicaoMonsL)&&(posicaoJogadorColuna==posicaoMonsC)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        Executar();
	}else{
		 if((posicaoJogadorLinha==posicaoMonsL-1)&&(posicaoJogadorColuna==posicaoMonsC)){//fedor em cima
            textcolor(GREEN);
            printf("FEDOR ");
            sleep(1);//coloquei o sleep para o jogador ter uma rápida sensação do que está acontecendo aumentando assim a dificuldade
            textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==posicaoMonsL)&&(posicaoJogadorColuna==posicaoMonsC-1)){//fedor a esquerda
            textcolor(GREEN);
            printf("FEDOR ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==posicaoMonsL)&&(posicaoJogadorColuna==posicaoMonsC+1)){//fedor a direita
            textcolor(GREEN);
            printf("FEDOR ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
        if((posicaoJogadorLinha==posicaoMonsL+1)&&(posicaoJogadorColuna==posicaoMonsC)){//fedor em baixo
            textcolor(GREEN);
            printf("FEDOR ");
            sleep(1);
			textcolor(LIGHTGRAY);
        }
	}
}

void poco1(){
	if((posicaoJogadorLinha==linha_poco1)&&(posicaoJogadorColuna==coluna_poco1)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        Executar();
	}else{
		if((posicaoJogadorLinha==linha_poco1-1)&&(posicaoJogadorColuna==coluna_poco1)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);//coloquei o sleep para o jogador ter uma rápida sensação do que está acontecendo aumentando assim a dificuldade
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco1)&&(posicaoJogadorColuna==coluna_poco1-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco1)&&(posicaoJogadorColuna==coluna_poco1+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco1+1)&&(posicaoJogadorColuna==coluna_poco1)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}	
}

void poco2(){
	if((posicaoJogadorLinha==linha_poco2)&&(posicaoJogadorColuna==coluna_poco2)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco2-1)&&(posicaoJogadorColuna==coluna_poco2)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco2)&&(posicaoJogadorColuna==coluna_poco2-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco2)&&(posicaoJogadorColuna==coluna_poco2+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco2+1)&&(posicaoJogadorColuna==coluna_poco2)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}	
}

void poco3(){
	if((posicaoJogadorLinha==linha_poco3)&&(posicaoJogadorColuna==coluna_poco3)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco3-1)&&(posicaoJogadorColuna==coluna_poco3)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco3)&&(posicaoJogadorColuna==coluna_poco3-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco3)&&(posicaoJogadorColuna==coluna_poco3+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco3+1)&&(posicaoJogadorColuna==coluna_poco3)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}
}

void poco4(){
	if((posicaoJogadorLinha==linha_poco4)&&(posicaoJogadorColuna==coluna_poco4)){//morreu
		GameOver();
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco4-1)&&(posicaoJogadorColuna==coluna_poco4)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco4)&&(posicaoJogadorColuna==coluna_poco4-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco4)&&(posicaoJogadorColuna==coluna_poco4+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco4+1)&&(posicaoJogadorColuna==coluna_poco4)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}
}

void poco5(){
	if((posicaoJogadorLinha==linha_poco5)&&(posicaoJogadorColuna==coluna_poco5)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco5-1)&&(posicaoJogadorColuna==coluna_poco5)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco5)&&(posicaoJogadorColuna==coluna_poco5-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco5)&&(posicaoJogadorColuna==coluna_poco5+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco5+1)&&(posicaoJogadorColuna==coluna_poco5)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}
}

void poco6(){
	if((posicaoJogadorLinha==linha_poco6)&&(posicaoJogadorColuna==coluna_poco6)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco6-1)&&(posicaoJogadorColuna==coluna_poco6)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco6)&&(posicaoJogadorColuna==coluna_poco6-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco6)&&(posicaoJogadorColuna==coluna_poco6+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco6+1)&&(posicaoJogadorColuna==coluna_poco6)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}
}

void poco7(){
	if((posicaoJogadorLinha==linha_poco7)&&(posicaoJogadorColuna==coluna_poco7)){//morreu
		GameOver();
        system("pause");
        system("cls");
        ranking = fopen("Ranking.bin","a");
        fprintf(ranking,"%s %d", nome, pontos);
        fclose(ranking);
        ExibirMenu();
	}else{
		if((posicaoJogadorLinha==linha_poco7-1)&&(posicaoJogadorColuna==coluna_poco7)){//brisa em cima
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco7)&&(posicaoJogadorColuna==coluna_poco7-1)){//brisa a esquerda
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco7)&&(posicaoJogadorColuna==coluna_poco7+1)){//brisa a direita
			textcolor(BLUE);
			printf("BRISA ");
			textcolor(LIGHTGRAY);
		}
		if((posicaoJogadorLinha==linha_poco7+1)&&(posicaoJogadorColuna==coluna_poco7)){//brisa em baixo
			textcolor(BLUE);
			printf("BRISA ");
			sleep(1);
			textcolor(LIGHTGRAY);
		}
	}
}

void movimentarJogador(char movimento){
	if(movimento==SUBIR){ 
		if(posicaoJogadorLinha!=0){
			if(labirinto[posicaoJogadorLinha-1][posicaoJogadorColuna]=='#'){
				pontuacao(1);
			}else{
				pontuacao(4);
			}
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[--posicaoJogadorLinha][posicaoJogadorColuna]='*';
			
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento==DESCER){
		if(posicaoJogadorLinha!=tamaF-1){
			if(labirinto[posicaoJogadorLinha+1][posicaoJogadorColuna]=='#'){
				pontuacao(1);
			}else{
				pontuacao(4);
			}
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[++posicaoJogadorLinha][posicaoJogadorColuna]='*';
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento==ESQUERDA){	
		if(posicaoJogadorColuna!=0){
			if(labirinto[posicaoJogadorLinha][posicaoJogadorColuna-1]=='#'){
				pontuacao(1);
			}else{
				pontuacao(4);
			}
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[posicaoJogadorLinha][--posicaoJogadorColuna]='*';
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento==DIREITA){ 
		if(posicaoJogadorColuna!=tamaF-1){
			if(labirinto[posicaoJogadorLinha][posicaoJogadorColuna+1]=='#'){
				pontuacao(1);
			}else{
				pontuacao(4);
			}
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; 
			labirinto[posicaoJogadorLinha][++posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	if(movimento=='f'){
		char mirar;
		printf("Digite para onde vai atirar! ");
		mirar = getch();
		atirar(mirar);
	}
	monstro();
	poco1();
	poco2();
	poco3();
	poteOuro();
}

void movimentarJogador2(char movimento2){
	if(movimento2==SUBIR){ 
		if(posicaoJogadorLinha!=0){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[--posicaoJogadorLinha][posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento2==DESCER){
		
		if(posicaoJogadorLinha!=tamaM-1){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[++posicaoJogadorLinha][posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento2==ESQUERDA){
		
		if(posicaoJogadorColuna!=0){
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[posicaoJogadorLinha][--posicaoJogadorColuna]='*';
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	
	if(movimento2==DIREITA){ 
		
		if(posicaoJogadorColuna!=tamaM-1){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; 
			labirinto[posicaoJogadorLinha][++posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
			Beep(300,500);
		}
	}
	if(movimento2=='f'){
		char mirar;
		printf("Digite para onde vai atirar! ");
		mirar = getch();
		atirar(mirar);
	}
	monstro();
	poco1();
	poco2();
	poco3();
	poco4();
	poco5();
	poteOuro2();
}

void Cadastro(){
	system("cls");
	pontos=0;
		
	ranking = fopen("cadastros.bin", "r");
	if(ranking == NULL){
		tam = 0; T = 0;
	} 
	fclose(ranking);
	
	if(ranking != NULL){
	ranking = fopen("Ranking.bin", "r");
	if(ranking == NULL) printf("");
	fclose(ranking);
	
	if(ranking != NULL){
	ranking = fopen("cadastros.bin", "r");
	fscanf(ranking, "%d", &tam);
	fclose(ranking);
	T = tam;
	}
	}
	
	printf("Cadastre um nickname para poder Jogar\n");
	printf("\nDigite seu nome:");
	scanf("%s",nome);

	T++;
	tam = T;
	ranking = fopen("cadastros.bin", "w");
	fprintf(ranking, "%d", T);
	fclose(ranking);
}


void Ranking(){
	int i, j;
	
	system("cls");
	ranking = fopen("cadastros.bin", "r");
	if(ranking != NULL){
	fscanf(ranking, "%d", &tam);
	}
	fclose(ranking);
	char nome[tam][1000], auxC[tam], admin[5], senha[5];
	int pont[tam], aux;
	
	if(ranking == NULL){
	printf("Nenhum Ranking disponivel\n");
	tam = 0;
	T = 0;
	}
	else if(ranking != NULL){
		printf("Ranking\t\tPts.\n");
		ranking=fopen("Ranking.bin","r");
		for(i = 0, j = 0; i,j < tam; i++,j++){
			fscanf(ranking, "%s %d", nome[i], &pont[i]);
			pont[j] = pont[i];
			strcpy(nome[j], nome[i]);
		}
		fclose(ranking);
		if(tam > 10){
			for(i = 0; i < tam; i++){
				for(j = i + 1; j < tam; j++){
					if (pont[i] > pont[j]){
						aux = pont[i];
						pont[i] = pont[j];
						pont[j] = aux;
						
						strcpy(auxC, nome[i]);
				    	strcpy(nome[i], nome[j]);
				    	strcpy(nome[j], auxC);
					}
				}
			}
		for (i = 9, j=0; i >= 0; i--,j++){
			printf("%d - %s\t\t\t%d\n", j+1, nome[i], pont[i]);
			Sleep(300);
			}
		}
		else{
			for(i = 0; i < tam; i++){
				for(j = i + 1; j < tam; j++){
					if (pont[i] > pont[j]){
						aux = pont[i];
						pont[i] = pont[j];
						pont[j] = aux;
						strcpy(auxC, nome[i]);
				    	strcpy(nome[i], nome[j]);
				    	strcpy(nome[j], auxC);
					}
				}
			}
			for (i = tam-1, j=0; i >= 0; i--,j++){
				printf("%d - %s\t\t\t%d\n", j+1, nome[i], pont[i]);
				Sleep(300);
			}
		}
	}
	system("pause");
	ExibirMenu();
	
}
void movimentarJogador3(char movimento3){
	if(movimento3==SUBIR){ 
		if(posicaoJogadorLinha!=0){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[--posicaoJogadorLinha][posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
		}
	}
	
	if(movimento3==DESCER){
		
		if(posicaoJogadorLinha!=tamaD-1){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[++posicaoJogadorLinha][posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
		}
	}
	
	if(movimento3==ESQUERDA){
		
		if(posicaoJogadorColuna!=0){
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' ';
			labirinto[posicaoJogadorLinha][--posicaoJogadorColuna]='*';
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
		}
	}
	
	if(movimento3==DIREITA){ 
		
		if(posicaoJogadorColuna!=tamaD-1){
			
			labirinto[posicaoJogadorLinha][posicaoJogadorColuna]=' '; 
			labirinto[posicaoJogadorLinha][++posicaoJogadorColuna]='*'; 
		}else{
			textcolor(YELLOW);
			printf("Impacto");
			textcolor(LIGHTGRAY);
		}
	}
	if(movimento3=='f'){
		char mirar;
		printf("Digite para onde vai atirar! ");
		mirar = getch();
		atirar(mirar);
	}
	monstro();
	poco1();
	poco2();
	poco3();
	poco4();
	poco5();
	poco6();
	poco7();
	poteOuro3();
}

void ExibirMenu(){
	
		system("cls");
		int op;
		printf("\t\t\t\t\t\t  +--------------------------MENU------------------------------+\n");
		printf("\t\t\t\t\t\t  |   1-Jogar                                                  |\n");
	    printf("\t\t\t\t\t\t  |   2-Ranking                                                |\n");
	    printf("\t\t\t\t\t\t  |   3-Instruções                                             |\n");
		printf("\t\t\t\t\t\t  |   0-Sair                                                   |\n");
		printf("\t\t\t\t\t\t  +------------------------------------------------------------+\n");
		scanf("%d",&op);
		switch(op){
			case 1:{
	
				Cadastro();
	
				Jogar();	
			break;
				}
			case 2:{
				Ranking();
					break;	
				}
	
			case 3:{
					Regras();
					break;
				}
			case 0:{
				sair();
				break;
			}
		}	
}
				
void Regras(){
	system("cls");
	puts("Bem vindo ao jogo!");
	puts("INSTRUÇÕES:");
	puts("Trata-se de uma caverna que consiste em salas conectadas por passagens. À espreita em");
	puts("algum lugar na caverna está o terrível HUP, um monstro que devora qualquer guerreiro que");
	puts("entrar em sua sala.");
	puts("O HUP pode ser atingido pelo guerreiro através de flechas.");
	puts("Algumas salas contêm poços sem fundo nos quais cairá qualquer um que vagar por elas");
	puts("(com exceção do HUP, que é muito grande para cair em um poço).");
	puts("A única característica que abranda esse ambiente desolador é a possibilidade de encontrar");
	puts("um pote de ouro. ");
	
	printf("Movimentação:\n");
	printf("W - Subir\n");
	printf("A - Esquerda\n");
	printf("S - Descer\n");
	printf("D - Direita\n");
	printf("F - Atirar\n");
	printf("Ao cliclar F para atirar vc deverá escolher para onde ele irá atirar!\n");
	printf("\n");
	system("pause");
	system("cls");

	ExibirMenu();
}

void Jogar(){
	inicializarLabirinto();
	posicaoJogadorLinha=0;
	posicaoJogadorColuna=0;
	
	labirinto[posicaoJogadorLinha][posicaoJogadorColuna]='*';

	char movimento;
	do{
		
		system("cls");
		imprimirLabirinto(); 
		printf("\nDigite o movimento: ");
		movimento = getch();
		movimentarJogador(movimento);
		
		
	}while(movimento!='x');	
	//system("cls");
}

void Jogar2(){
	inicializarLabirinto2();
	posicaoJogadorLinha=0;
	posicaoJogadorColuna=0;
	
	labirinto[posicaoJogadorLinha][posicaoJogadorColuna]='*';

	char movimento2;

	do{
		
		
		system("cls");
		//system("clear");
		imprimirLabirinto2(); 
		printf("\nDigite o movimento: ");
		movimento2 = getch();
		movimentarJogador2(movimento2);
		if(movimento2=='x'){
			system("cls");
			Executar();
		}
		
	}while(movimento2!='x');	
	//system("cls");
}

void Jogar3(){
	inicializarLabirinto3();
	posicaoJogadorLinha=0;
	posicaoJogadorColuna=0;
	labirinto[posicaoJogadorLinha][posicaoJogadorColuna]='*';
	char movimento3;
	do{	
		system("cls");
		imprimirLabirinto3(); 
		printf("\nDigite o movimento: ");
		movimento3 = getch();
		movimentarJogador3(movimento3);
	}while(movimento3!='x');	
}

void Executar(){
	score=0;
	ExibirMenu();
}
void sair(){
	exit(0);
}
void GameOver(){
	textcolor(RED);
		printf("\n");
		system("cls");
		printf(" _______  _______  __   __  _______   \n"); 
		printf("|       ||   _   ||  |_|  ||       |   \n");
		printf("|    ___||  |_|  ||       ||    ___|   \n");
		printf("|   | __ |       ||       ||   |___    \n");
		printf("|   ||  ||       ||       ||    ___|   \n");
		printf("|   |_| ||   _   || ||_|| ||   |___    \n");
		printf("|_______||__| |__||_|   |_||_______|   \n");
		printf(" _______  __   __  _______  ______     \n");
		printf("|       ||  | |  ||       ||    _ |    \n");
		printf("|   _   ||  |_|  ||    ___||   | ||    \n");
		printf("|  | |  ||       ||   |___ |   |_||_   \n");
		printf("|  |_|  ||       ||    ___||    __  |  \n");
		printf("|       | |     | |   |___ |   |  | |  \n");
		printf("|_______|  |___|  |_______||___|  |_|  \n");
		textcolor(LIGHTGRAY);
		Beep(200,500);
}
void atirar(char direcao){
	if(direcao==SUBIR){ 
		if((posicaoJogadorLinha-1 == posicaoMonsL ) && (posicaoJogadorColuna == posicaoMonsC)){
			printf("GRITO!!!!\n");
			sleep(1);
			posicaoMonsL=9;
			posicaoMonsC=9;
			pontuacao(2);
		}
		else{
			printf("Vc errou!!\n");
			pontuacao(5);
			sleep(1);		}
	}
	if(direcao==DESCER){ 
		if((posicaoJogadorLinha+1 == posicaoMonsL ) && (posicaoJogadorColuna == posicaoMonsC)){
			printf("GRITO!!!!\n");
			sleep(1);
			posicaoMonsL=9;
			posicaoMonsC=9;
			pontuacao(2);
		}
		else{
			printf("Vc errou!!\n");
			pontuacao(5);
			sleep(1);		}
	}
	if(direcao==ESQUERDA){ 
		if((posicaoJogadorLinha == posicaoMonsL ) && (posicaoJogadorColuna-1 == posicaoMonsC)){
			printf("GRITO!!!!\n");
			sleep(1);
			posicaoMonsL=9;
			posicaoMonsC=9;
			pontuacao(2);
		}
		else{
			printf("Vc errou!!\n");
			pontuacao(5);
			sleep(1);		}
	}
	if(direcao==DIREITA){ 
		if((posicaoJogadorLinha == posicaoMonsL ) && (posicaoJogadorColuna+1 == posicaoMonsC)){
			printf("GRITO!!!!\n");
			sleep(1);
			posicaoMonsL=9;
			posicaoMonsC=9;
			pontuacao(2);
			
		}
		else{
			printf("Vc errou!!\n");
			pontuacao(5);
			sleep(1);		}
	}
}
void pontuacao(int cod){
	switch(cod){
		case 1:{//Nova sala segura...
			pontos = pontos + 5;
			break;
		}
		case 2:{//Matar o monstro...
			pontos = pontos + 30;
			break;
		}
		case 3:{//resgatar o pote de ouro
			pontos = pontos + 50;
			break;
		}
		case 4:{//revisar uma sala
			pontos = pontos - 2;
			break;
		}
		case 5:{//errar um tiro
			pontos = pontos - 30;
			break;
		}
	}
	score = pontos;
}


