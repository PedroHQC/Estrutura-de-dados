#include <stdio.h>

int main(){
	float valor, inflacao;
	printf(" Digite o preço do produto \npreço: ");
	scanf("%f", &valor);
	if(valor < 100){
		inflacao = (valor * 10)/100;
		valor = valor + inflacao;
		printf("Produto inflacionado em 10%% \nNovo preço: %0.2f ", valor);
	}
	else if(valor >= 100){
		inflacao = (valor * 20)/100;
		valor = valor + inflacao;
		printf("Produto inflacionado em 20% \nNovo preço: %0.2f ", valor);
	}
	
	
	return 0;
}
