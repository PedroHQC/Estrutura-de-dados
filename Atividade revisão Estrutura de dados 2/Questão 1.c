#include <stdio.h>

int main(){
	int valor, valor_2, a, b, c;
	printf(" Digite dois valores \nvalor 1: ");
	scanf("%d", &valor);
	printf("valor 2: ");
	scanf("%d", &valor_2);
	a = valor + valor_2;
	b = valor * (valor_2 * valor_2);
	c = valor * valor;
	printf(" A)A soma dos valores é: %d \n B)O produto do primeiro pelo quadrado do segundo valor é: %d \n C)O quadrado do primeiro valor é: %d ", a, b ,c);
	
	
	return 0;
}
