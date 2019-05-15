#include<stdio.h>
#include<stdlib.h>
int main(){
    int m[3][3]={1,2,3,4,5,6,7,8,9};
    int l,c;
    for (l=0;l<3;l=l+1){
        for (c=0;c<3;c=c+1)
            printf("%d ",m[l][c]);
        printf("\n");
    }
    printf("\n\n");
    for (c=0;c<3;c=c+1){
        for (l=3-1;l>=0;l=l-1t)
            printf("%d ",m[l][c]);
        printf("\n");
    }

}
