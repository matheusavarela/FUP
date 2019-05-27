#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char frase[100];
	int i=0;
	printf("Frase:\n");
	gets(frase);
	for ( i = 0; frase[i]!='\0'; i++){
		if(frase[i]!=frase[i+1]){
			printf("%c",frase[i]);
		}
	}
	

}
