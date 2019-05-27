#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char frase[100];
	int outros=0,a=0,e=0,i=0,o=0,u=0;
	printf("\nFrase:");
	gets(frase);
	for (int i = 0; frase[i]!='\0'; i++){
		if(frase[i]=='a')
			a++;
		if(frase[i]=='e')
			e++;
		if(frase[i]=='i')
			i++;
		if(frase[i]=='o')
			o++;
		if(frase[i]=='u')
			u++;
		if ((frase[i]!='a')&&(frase[i]!='e')&&(frase[i]!='i')&&(frase[i]!='o')&&(frase[i]!='u'))
			outros++;										
	}
	printf("\n------------");
	printf("\n  a	:  %d",a);
	printf("\n  e	:  %d",e);
	printf("\n  i	:  %d",i);
	printf("\n  o	:  %d",o);
	printf("\n  u	:  %d",u);
	printf("\noutros	:  %d",outros);
	printf("\n------------");
	printf("\nTOtal: %d",strlen(frase));
}
