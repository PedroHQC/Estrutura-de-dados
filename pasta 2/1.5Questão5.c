#include <stdio.h>
#include <stdlib.h>

int tamanho = 0;
struct numerospares{
int numeros;
struct numerospares *prox;
};
typedef struct numerospares ponteiros;
ponteiros *primeiro, *listaaux;
void barra(){
printf("=====================\n");

}
void addstart(int n){
ponteiros *aux=malloc(sizeof(ponteiros));
aux->numeros = n;
aux->prox = listaaux;
listaaux = aux;
}
void addstart2(int n){
ponteiros *aux2=malloc(sizeof(ponteiros));
aux2->numeros = n;
aux2->prox = primeiro;
primeiro = aux2;
tamanho++;
}
void imprimir(ponteiros *p){
  if(p != NULL){
    printf("Numero: %i\n", p->numeros);
    imprimir(p->prox);
  }
}
ponteiros *analise(ponteiros *p){
  if(p != NULL){
    if(p->numeros >= 0){
      addstart2(p->numeros);
      analise(p->prox);
    }
    else{
    analise(p->prox);
    }
  }
  return primeiro;
}
int main(){
    int op, num, i;
    printf("Quantos numeros deseja adicionar? ");
    scanf("%d", &op);
    for(i=0; i<op; i++){
    printf("Digite o %dº numero.", i+1);
    scanf("%d", &num);
    addstart(num);
    }
    printf("Numeros adicionados!\n");
    barra();
    imprimir(listaaux);
    barra();
    analise(listaaux);
    printf("Negativos removidos!\n");
    barra();
    imprimir(primeiro);
    barra();
return 0;
}
