#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b ,c;
    printf("Digite o valor de a\n");
    scanf("%d",&a);
    printf("Digite o valor de b\n");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("\nO valor de a agr é: %d", a);
    printf("\nO valor de a agr é: %d", b);
}
