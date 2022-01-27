#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct noDaLista
{
char titulo[51];
char autor[51];
int ano;
int quantidade;
struct noDaLista *prox;
};
typedef struct noDaLista ponteiros;
ponteiros *primeiro;
void barra(){
	printf("===============================\n");


}
void adicionarlivro(){
	ponteiros *aux = malloc(sizeof(ponteiros));

  printf("Digite o titulo do livro: ");
	scanf("%s", aux->titulo);
	printf("Digite o nome do autor: ");
	scanf("%s", aux->autor);

	printf("Digite o ano de lançamento: ");
	scanf("%d", &aux->ano);

	printf("Quantidade do livro: ");
	scanf("%d", &aux->quantidade);
	aux->prox = primeiro;
	primeiro = aux;

}


int quantoslivros(ponteiros *p){
	int soma=0;
	while (p != NULL){
		soma = soma + p->quantidade;
    	p= p->prox;
	}
	printf("\n Livros no acervo: %d\n", soma);
	return 0;
}
void procurar_ano(ponteiros *p, int ano){

	if(p !=NULL){
		if(ano==p->ano){

			barra();
			printf("Titulo: %s\n", p->titulo);
			printf("Autor: %s\n", p->autor);
			printf("Ano de lancamento: %d\n", p->ano);
			printf("Quantidade disponivel: %d\n", p->quantidade);
			procurar_ano(p->prox, ano);

		}


		procurar_ano(p->prox, ano);
	}

}

int main(){
  int i=0, op, j2;
  do{
  quantoslivros(primeiro);
  printf(" 1-Procurar livro por ano de lançamento\n 2-Adicionar livro\n 3-Sair\n Escolha: ");
  scanf("%d", &op);
  switch(op){
    case 1:{
      int aux1;
      printf("Digite o ano de lancamento do livro: ");
      scanf("%d", &aux1);
      procurar_ano(primeiro,aux1);


    }
    break;
    case 2:{
      adicionarlivro();

    }
    break;
    case 3:{
      i =1;

    }
    break;
    default:{
    	barra();
    	printf(" Opcao invalida\n");
		barra();
    }
  }
  }
	while(i<1);

barra();
}
