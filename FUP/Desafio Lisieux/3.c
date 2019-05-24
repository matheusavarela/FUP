/*Dizemos que uma matriz quadrada inteira é um quadrado mágico se a soma dos elementos de cada linha,
 a soma dos elementos de cada coluna e a soma dos elementos das diagonais principal e secundária são todas iguais.*/
#include <stdio.h>
#include<stdlib.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	
	int mat[n][n];
	
	for (i = 0; i < n; i=i+1) {
		for (j = 0; j < n; j=j+1) {
			scanf("%d", &mat[i][j]);
		}
	}
 
	int somaDP = 0, somaDS = 0;
	
	
	for (i = 0; i < n; i=i+1) {
		somaDP = somaDP + mat[i][i];
	}
	
	
	for (i = 0; i < n; i=i+1) {
		somaDS = somaDS + mat[i][n-i-1];
	}
	

	int vetL[n];
	for (i = 0; i < n; i=i+1) {
		vetL[i] = 0;
		for (j = 0; j < n; j=j+1) {
			vetL[i] = vetL[i] + mat[i][j];
		}
	}
	

	
	int vetC[n];
	for (j = 0; j < n; j=j+1) {
		vetC[j] = 0;
		for (i = 0; i < n; i=i+1) {
			vetC[j] = vetC[j] + mat[i][j];
		}
	}
	
	
	
 
	int testaL = 1, testaC = 1;
	for (i = 1; i <  n; i=i+1) {
		if (vetL[i] != vetL[i-1]) {
			testaL = 0;
			break;
		} else if (vetC[i] != vetC[i-1]) {
			testaC = 0;
			break;
		}
	}
	
	if (testaL && testaC && somaDP == somaDS && somaDP == vetL[0]) {
		printf("\nO quadrado é mágico");
	} else {
		printf("\nO quadrado não é mágico");
	}
 
	return 0;
}