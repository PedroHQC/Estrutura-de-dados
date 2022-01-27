#include <stdio.h>
#include <stdlib.h>
struct jogador{
  char nome[50];
  int numero;
  struct jogador *esquerda;
  struct jogador *direita;
  struct jogador *prox;
};
typedef struct jogador No;
No *primeiro;
No *inicializador(){
  return NULL;
}
void imprimiremord(No *raiz){
  if(raiz != NULL){
    imprimiremord(raiz->esquerda);
    printf("Nome: %s\n", raiz->nome);
    printf("Numero: %i\n", raiz->numero);
    imprimiremord(raiz->direita);
  }
}
void imprimirposord(No *raiz){
  if(raiz != NULL){
    imprimiremord(raiz->esquerda);
    imprimiremord(raiz->direita);
    printf("Nome: %s\n", raiz->nome);
    printf("Numero: %i\n", raiz->numero);
    
  }
}
No *procurar(No *pont,int valor){
  while(valor != pont->numero){
    procurar(pont->prox,valor);
}
return pont;
}
void Addstart(){
  No *aux = malloc(sizeof(No));
  scanf("%i", &aux->numero);
  getchar();
  fgets(aux->nome, 50, stdin);
  aux->prox = primeiro;
  primeiro = aux;
}
int Quantidade;
No *AddNarvore(No *raiz, int valor){
  
  if(raiz == NULL){
    Quantidade++;
  No *aux = (No*)malloc(sizeof(No));
  aux->numero = valor;
  aux->direita = NULL;
  aux->esquerda = NULL;
  
  return aux;
}
else{
  if(valor > raiz->numero){
    
    raiz->direita = AddNarvore(raiz->direita, valor);
  }
  else if(valor < raiz->numero){
    
    raiz->esquerda = AddNarvore(raiz->esquerda, valor);
  }
}
return 0;
}
void *remover(No *raiz, int valor){
  No *filho = raiz;
	No *pai;
	do{
		pai = filho;
		if(valor < filho->numero)
			filho = filho->esquerda;
		else if(valor > filho->numero)
			filho = filho->direita;
  }
  while(filho!=NULL &&  filho->numero != valor);
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
        filho->numero = filho->esquerda->numero;
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
        filho->numero = aux1->numero;
      }
    }
  }
  return 0;
}
int main(){
  No *root;
  int op, operador;
  do{
    printf("Escolha a opcao:\n 1- adicionar jogador ao total\n 2- adicionar jogado ao time\n 3- trocar jogador\n 4- imprimir os jogadores em rodem \n 5- imprimir os jogadores em pos ordem\n 6- sair\n ");
    scanf("%i", &op);
    switch(op){
      case 1:{
        printf("digite o numero e em seguida o nome do jogador");
        Addstart();
      }
      break;
      case 2:{
        if(Quantidade < 11){
          int jogador = 0;
          printf("digite o numero do jogado a ser adifionado  ");
          scanf("%i", &jogador);
          AddNarvore(root, jogador);
        }
        else{
          printf("time cheio");
        }
      }
      break;
    case 3:{
      int remov = 0, novo = 0;;
      printf("digite o numero do jogador a ser removido");
      scanf("%i", &remov);
      remover(root, remov);
      printf("digite o numero do novo jogador a ser adicionado");
      scanf("%i", &novo);
      AddNarvore(root, novo);
    }
    break;
    case 4:{
      imprimiremord(root);
    }
    break;
    case 5:{
      imprimirposord(root);
    }
    break;
    case 6:{
      operador = -1;
    }
    break;
    default:{
      printf("opção invalida");
    }
    }
  }
  while(operador != -1);
}
