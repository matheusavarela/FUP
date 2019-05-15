#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    float h;
    printf("Digite um número!\n");
    scanf("%d", &n);
    h = 1;
    for(i=2;i<=n; i=i+1){
        if(i%2==0)
            h = h + 1.0/i;
        if(i%2==1)
            h = h - 1.0/i;
    }
    printf("Resut =  %f", h);
}
