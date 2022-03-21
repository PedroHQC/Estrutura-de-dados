#include <stdio.h>

int main(){
	int valor, valor_2, a, b, c;
	printf(" Digite dois valores \nvalor 1: ");
	scanf("%d", &valor);
	printf("valor 2: ");
	scanf("%d", &valor_2);
	if(valor > valor_2){
		printf("lista de valores: %d %d", valor, valor_2);
	}
	else if(valor < valor_2){
		printf("lista de valores: %d %d", valor, valor_2);
	}
	else{
		printf("valores iguais");
	}
	
	return 0;
}
