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
    printf("%d ", raiz->item);
    imprimir(raiz->direita);
    imprimir(raiz->esquerda);

  }
}
No *Add(No *raiz, int valor){
if(raiz == NULL){
  No *aux = (No*)malloc(sizeof(No));
  aux->item = valor;
  aux->direita = NULL;
  aux->esquerda = NULL;
  return aux;
}
else{
  if(valor > raiz->item){
    raiz->direita = Add(raiz->direita, valor);
  }
  else if(valor < raiz->item){
  raiz->esquerda = Add(raiz->esquerda, valor);
  }
}
return raiz;
}
int main(){
No *jurandir;
jurandir = inicializador();
jurandir = Add(jurandir, 10);
jurandir = Add(jurandir, 12);
jurandir = Add(jurandir, 11);
jurandir = Add(jurandir, 5);
jurandir = Add(jurandir, 6);
jurandir = Add(jurandir, 7);
jurandir = Add(jurandir, 20);
imprimir(jurandir);
freeno(jurandir);
  return 0;
}
