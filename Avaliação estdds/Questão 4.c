#include <stdio.h>
#include <stdlib.h>

struct no{
int item;
struct no *direita;
struct no *esquerda;
};
typedef struct no No;

No *inicializador(){
  return NULL;
}

void freeno(No *raiz){
  if(raiz != NULL){
    freeno(raiz->direita);
    freeno(raiz->esquerda);
    free(raiz);
  }
}

void imprimir(No *raiz){
  if(raiz != NULL){

    imprimir(raiz->esquerda);
   printf("%d ", raiz->item);
    imprimir(raiz->direita);
  }
}
/*variaveis globais*/
int quantidade;
int altura = 0;
int auxiliar = 0;
/*vb*/
No *Add(No *raiz, int valor){

if(raiz == NULL){

  No *aux = (No*)malloc(sizeof(No));
  aux->item = valor;
  aux->direita = NULL;
  aux->esquerda = NULL;
  quantidade++;
  return aux;
}
else{
  if(valor > raiz->item){
    auxiliar++;
    raiz->direita = Add(raiz->direita, valor);
  }
  else if(valor < raiz->item){
    auxiliar++;
    raiz->esquerda = Add(raiz->esquerda, valor);
  }
}
if(auxiliar > altura){
  altura = auxiliar;

}
auxiliar = 0;
return raiz;
}

void *remover(No *raiz, int valor){
  No *filho = raiz;
	No *pai;
	do{
		pai = filho;
		if(valor < filho->item)
			filho = filho->esquerda;
		else if(valor > filho->item)
			filho = filho->direita;
  }
  while(filho!=NULL &&  filho->item != valor);
  if(filho != NULL){
    if(filho->direita == NULL && filho->esquerda == NULL){
      if(pai->esquerda == filho) pai->esquerda = NULL;
      if(pai->direita == filho) pai->direita = NULL;
    }
    else if(filho->esquerda != NULL && filho->direita == NULL){
      if(pai->esquerda == filho) pai->esquerda = filho->esquerda;
      if(pai->direita == filho) pai->direita = filho->esquerda;
    }
    else if(filho->direita != NULL && filho->esquerda == NULL){
      if(pai->esquerda == filho) pai->esquerda = filho->direita;
      if(pai->direita == filho) pai->direita = filho->direita;
    }
    else if(filho->esquerda != NULL && filho->direita != NULL){
      if(filho->esquerda->direita == NULL){
        filho->item = filho->esquerda->item;
        filho->esquerda = NULL;
      }
      else{
        No *aux1 = filho->esquerda;
        No *aux2 = aux1;
        while(aux1->direita != NULL){
          aux2 = aux1;
          aux1 = aux1->direita;
        }
        aux2->direita = NULL;
        filho->item = aux1->item;
      }
    }
  }
  quantidade--;
  return 0;
}
void procurarmaior(No *raiz){
  while(raiz->direita != NULL){
    raiz = raiz->direita;
  }
  printf("\nO maior valor da arvore e: %i\n", raiz->item);
}
int main(){
  No *jurandir;
  jurandir = inicializador();
  jurandir = Add(jurandir, 10);
  jurandir = Add(jurandir, 1);
  jurandir = Add(jurandir, 2);
  jurandir = Add(jurandir, 3);
  jurandir = Add(jurandir, 12);
  jurandir = Add(jurandir, 11);
  jurandir = Add(jurandir, 5);
  jurandir = Add(jurandir, 6);
  jurandir = Add(jurandir, 25);
  jurandir = Add(jurandir, 20);
  jurandir = Add(jurandir, 8);
  jurandir = Add(jurandir, 22);

  printf("quantidade: %i\n", quantidade);
  printf("altura: %i\n", altura);
  imprimir(jurandir);
  procurarmaior(jurandir);
  remover(jurandir, 11);
  printf("quantidade: %i\n", quantidade);

  imprimir(jurandir);
  freeno(jurandir);
  return 0;
}
