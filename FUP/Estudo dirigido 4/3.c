#include<stdio.h>
int main(){
	char resposta, sexo;
	int i, qtdSim =0, qtdNao=0, qtdFeminoSim=0;
	float porcentagemFeminina;
	for(i=0;i<=5;i=i+1){
		printf("Informe seu sexo (F/M): ");
		scanf("%c", &sexo);
		fflush(stdin);//limpando o buffer
		
		printf("Informe se gostou do novo produto(s/n): ");
		scanf("%c", &resposta);
		fflush(stdin);//limpando o buffer
		
		switch(resposta){
			case 's':
				qtdSim = qtdSim+1;
				if(sexo=='f')
					qtdFeminoSim = qtdFeminoSim+1;
				break;
			case 'n':
				qtdNao = qtdNao+1;
				break;
			default:
				printf("Resposta invalida, digite s ou n");
		}
	}
	printf("%d pessoas gostaram do produto\n", qtdSim);
	printf("%d pessoas nao gostaram do produto", qtdNao);
	porcentagemFeminina = qtdFeminoSim*100/qtdSim;
	printf("%.2f eh a porcentagem de mulheres que responderam sim", porcentagemFeminina);
}
