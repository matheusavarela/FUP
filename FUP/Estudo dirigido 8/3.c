#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[4][4],b[4][4],c[4][4];
    int i,j;
    for (i = 0; i < 4; i++)
        for (j =0; j < 4; j++)
            a[i][j]=rand() % 20;
    
    for (i = 0; i < 4; i++)
        for (j =0; j < 4; j++)
            b[i][j]=rand() % 20;        
    
    for (i = 0; i < 4; i++)
        for (j =0; j < 4; j++){
            if (a[i][j]>=b[i][j])
                c[i][j]=a[i][j];
            if (b[i][j]>=a[i][j])
                c[i][j]=b[i][j];    
        }    
    printf("Matriz A:\n\n");
    for (i = 0; i < 4; i++){
        for (j =0; j < 4; j++)
            printf("%d ",a[i][j]);
        printf("\n");    
    }

    printf("Matriz B:\n\n");
    for (i = 0; i < 4; i++){
        for (j =0; j < 4; j++)
            printf("%d ",b[i][j]);
        printf("\n");    
    }

    printf("Matriz C:\n\n");
    for (i = 0; i < 4; i++){
        for (j =0; j < 4; j++)
            printf("%d ",c[i][j]);
        printf("\n");    
    }
}