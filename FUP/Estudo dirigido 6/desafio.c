#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1, v2 = 0, qtd = 0, maior = 0, menor = 0, qntpar= 0, mediapar = 0;
    do {
        scanf("%d", &v1);
        if(v1 > v2){
            v2 = v1;
            if(v1%2==0){
                qntpar = qntpar +1;
                mediapar = mediapar + v1;
            }
            if(v1 > maior){
                maior = v1;
            }
            if(menor == 0 && v1 == 0){
                menor = menor -1;
            }
            else{
                if(menor == 0 && v1 > 0){
                    menor = v1;
                }
            }

        }
        qtd = qtd +1;

    }while(v2<=v1);
    if(menor < 0){
        menor = 0;
    }
    printf("%d\n", qtd);
    printf("%d %d\n",maior, menor);
    printf("%f", mediapar/qntpar);


}
