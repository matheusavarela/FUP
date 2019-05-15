#include<stdio.h>
#include<stdlib.h>
int main(){

    int n[4][4];
    int i,j;
    int x;
    int result[4][4];
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 4; j++)
        {
            printf("Número\n");
            scanf("%d",&n[i][j]);
        }
        
    }
    printf("Numero q vai multiplicar\n");
    scanf("%d",&x);
    system("clear");
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 4; j++)
        {
            result[i][j]=n[i][j];
        }
        
    }
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 4; j++)
        {
            if (i==j) {
                result[i][j]=result[i][j]*x;
            }
            
        }
       
    }
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 4; j++)
        {
            printf("%d\t",result[i][j]);
            
        }
        printf("\n");
       
    }
    
}