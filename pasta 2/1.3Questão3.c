#include <stdio.h>
#include <stdlib.h>
struct numerospares{
int numeros;
struct numerospares *prox;
};
typedef struct numerospares ponteiros;
ponteiros *primeiro;
ponteiros *lista;

void barra(){
printf("=====================\n");

}


void addstart(int n){
ponteiros *aux=malloc(sizeof(ponteiros));
aux->numeros = n;
aux->prox = primeiro;
primeiro = aux;
}
void imprimir(ponteiros *p){
  if(p != NULL){
    printf("Numero: %i\n", p->numeros);
    imprimir(p->prox);
  }
}
ponteiros *inverte(ponteiros *p){
  ponteiros *ant, *atu, *seg;
  ant = NULL;
  atu = p;
  while(atu != NULL){
    seg = atu->prox;
    atu->prox = ant;
    ant = atu;
    atu = seg;

  }
  return ant;
}

int main(){



addstart(0);
addstart(2);
addstart(4);
addstart(6);
addstart(8);
addstart(10);
addstart(12);
addstart(14);
addstart(16);
addstart(18);
addstart(20);
printf("Numeros adicionados!\n");
barra();
imprimir(primeiro);
barra();
printf("Invertendo os numeros\n");
lista = inverte(primeiro);
barra();
printf("Nova ordem numerica!\n");
barra();
imprimir(lista);
barra();
return 0;
}
