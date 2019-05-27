#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
main(){
        
        int i,tam,qtd=0,count=0;
        do{
            char string[50],auxiliar[50];
            printf("Palavra: ");
            gets(string);  
            tam=strlen(string)-1;    
            for(i=0;string[i]!='\0';i++){        
                auxiliar[tam]=string[i];
                tam--;     
            }
            auxiliar[i]='\0';     
            if(strcmp(string,auxiliar)==0)
                qtd++;
            count++;    
        }while(count<5);
        printf("%d",qtd);
}