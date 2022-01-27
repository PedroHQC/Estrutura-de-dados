#include <stdio.h>
#include <stdlib.h>


struct numerospares{
int numeros;
struct numerospares *prox;
};
typedef struct numerospares ponteiros;
ponteiros *lista1;
ponteiros *lista2;

void barra(){
printf("=====================\n");

}

void addstart_lista1(int n){
ponteiros *aux=malloc(sizeof(ponteiros));
aux->numeros = n;
aux->prox = lista1;
lista1 = aux;
}
void addstart_lista2(int n){
ponteiros *aux=malloc(sizeof(ponteiros));
aux->numeros = n;
aux->prox = lista2;
lista2 = aux;
}

void imprimir(ponteiros *p){
  if(p != NULL){
    printf("Numero: %i\n", p->numeros);
    imprimir(p->prox);
  }
}
void concatenar(ponteiros *p1, ponteiros *p2){
ponteiros *aux;
aux = p1;
while(p2->prox != NULL){
  p2 = p2->prox;
}
p2->prox=aux;
}


int main(){

addstart_lista1(0);
addstart_lista1(2);
addstart_lista1(4);
addstart_lista1(6);
addstart_lista1(8);
addstart_lista2(10);
addstart_lista2(12);
addstart_lista2(14);
addstart_lista2(16);
addstart_lista2(18);
addstart_lista2(20);
printf("Numeros adicionados!\n");
barra();
imprimir(lista1);
barra();
imprimir(lista2);
barra();
concatenar(lista1, lista2);
printf("Concatenando\n");
barra();
imprimir(lista2);
return 0;
}
