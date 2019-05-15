	#include<stdio.h>
	#define T 10
	int main(){
		int v[T];
		int i;
		
		for(i=0;i<T;i=i+1){
			printf("Informe um numero: ");
			scanf("%d", &v[i]);
		}
		for(i=T-1;i>=0;i=i-1)
			printf("%d -", v[i]);
		
	}