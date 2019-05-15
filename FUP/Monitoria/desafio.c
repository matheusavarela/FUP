#include <stdio.h>
#include <stdlib.h>

int main()
{
    char coluna[1];
    int linha, c, qnt, cor;
    printf("digite a posição do cavalo\n");
    scanf("%c%d", coluna, &linha);
    printf("Qnt de movimentos");
    scanf("%d" &qnt);
    if (coluna == 'a'){
    c = 1;
    }
    if (coluna == 'b'){
    c = 2;
    }
    if (coluna == 'c'){
    c = 3;
    }
    if (coluna == 'd'){
    c = 4;
    }
    if (coluna == 'e'){
    c = 5;
    }
    if (coluna == 'f'){
    c = 6;
    }
    if (coluna == 'g'){
    c = 7;
    }
    if (coluna == 'h'){
    c = 8;
    }
    if ((c %2 == 0)&&(l %2 == 0)){
        cor = 1;
        if (qnt %2 == 0)
            printf("Cor depois do movimentos é o preto");
        else
            printf("A cor depois do movimento final é branco");
    }
    if ((c %2 == 1)&&(l %2 == 1)){
        cor = 2;
        if (qnt %2 == 0)
            printf("Cor depois do movimentos é o preto");
        else
            printf("A cor depois do movimento final é branco");
    }


}

