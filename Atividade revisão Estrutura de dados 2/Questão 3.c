#include <stdio.h>

int main(){
	float valor, inflacao;
	printf(" Digite o pre�o do produto \npre�o: ");
	scanf("%f", &valor);
	if(valor < 100){
		inflacao = (valor * 10)/100;
		valor = valor + inflacao;
		printf("Produto inflacionado em 10%% \nNovo pre�o: %0.2f ", valor);
	}
	else if(valor >= 100){
		inflacao = (valor * 20)/100;
		valor = valor + inflacao;
		printf("Produto inflacionado em 20% \nNovo pre�o: %0.2f ", valor);
	}
	
	
	return 0;
}
