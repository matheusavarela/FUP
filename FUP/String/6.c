#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	char frase[100];
	int i,qtd=1;
	printf("\nFrase:");
	gets(frase);//Gets é uma função para receber uma string pórem não é aconselhado utilizala.
	//scanf("%s",frase);
	for ( i = 0;frase[i]!='\0'; i++){
		if(frase[i]==' '){
			qtd=qtd+1;
		}		
	}
	printf("\nA frase Dada tem %d palavra(s)",qtd);
	

}
