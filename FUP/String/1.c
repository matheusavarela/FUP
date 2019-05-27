#include <stdio.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char frase[50]
	printf("DIGITE UMA FRASE!\n");
	gets(frase);
	for (int i = 0; frase[i]!='\0'; i++){
		if(i%2==1){
			printf("%c",frase[i]);
		}
	}
	
	
	
}
