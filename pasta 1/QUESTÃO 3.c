#include <stdio.h>
#include <stdlib.h>

int ponteiro_vetorizado(int b){
    int *p;
    p = (int *) malloc(b * sizeof(int));
    printf("=====================================\n""Foi criado o vetor p com %i elementos.\n""=====================================\n", b);
    return p;
}
int mostrar_vetor(int *q, int c){
    int i;
    for(i = 0; i < c; i++){
        printf("o valor na posicao de numero %i eh %i: \n", i+1, *(q+i));
    }
    return 0;
}
int criador(int a){
int j, *e;
e = ponteiro_vetorizado(a);
for(j = 0; j < a; j++){
    printf("digite o valor de numero %i: \n", j+1);
    scanf("%i", (e+j));
    }
    mostrar_vetor(e, a);

free(e);
return 0;
}
int main(){
    int aux;
  printf("Digite o tamanho do vetor: ");
  scanf("%i", &aux);
  criador(aux);
    return 0;
}






