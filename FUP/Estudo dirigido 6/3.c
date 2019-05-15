	#include<stdio.h>
	int main(){
		char codVenda='K';
		float valor, mediaPrazo, somaVendaPrazo=0;
		int qtdVista=0, qtdPrazo=0, totalCompras;

		while(codVenda != 's'){
			system("clear");
			printf("Informe o codigo para pagamento (p ou v), ou s para sair:\n ");

			scanf("%c", &codVenda);

			switch(codVenda){
				case 'p':{
					printf("Informe o valor da compra a prazo: ");
					scanf("%f", &valor);
					somaVendaPrazo = somaVendaPrazo + valor;
					qtdPrazo = qtdPrazo+1;
					break;
				}
				case 'v':{
					printf("Informe o valor da compra a vista: ");
					scanf("%f", &valor);
					qtdVista = qtdVista+1;
					break;
				}
				case 's': {
					printf("FIM DO PROGRAMA");
					totalCompras = qtdPrazo+qtdVista;
					mediaPrazo = somaVendaPrazo/qtdPrazo;

					printf("\n Quantidade de compras a vista: %d", qtdVista);
					printf("\n Media de vendas a prazo: R$ %.2f", mediaPrazo);
					printf("\n Total de compras efetuadas: %d", totalCompras);
					break;
				}
				default: printf("Informacao incorreta, tente outra vez");
			}
			fflush(stdin);
		}
	}
