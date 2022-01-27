#include <stdio.h>
#include <stdlib.h>


int main(){
    int *p, n, i=0, j, k;
    printf("quantas pessoas voce deseja cadastrar? ");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));

    printf("digite as idades das pessoas:\n");

    while(i < n){

        scanf("%i", (p+i));
        i++;
    }

    for(j = 0; j < n; j++){
        if(p[j] >= 18){
            printf("a %i pessoa e maior de idade, com %i anos de idade.\n", j+1, *(p+j));
        }
        else{
          k++;
        }
    if(k == n){
      printf("nao ha pessoas maiores de idade");

    }
    }
    free(p);
    return 0;
}






