#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, i=0, j;
    float k = 0, *p;
    printf("quantas alunos precisa? ");
    scanf("%d", &n);
    p = (float *) malloc(n * sizeof(float));

    printf("digite as notas dos alunos:\n");

    for(i=0; i < n;i++){
        printf("aluno %i: ", i+1);
        scanf("%f",(p+i) );
    }

    for(j = 0; j < n; j++){
        k = k + *(p+j);

        }
    printf("a media e: %0.2f", k/n);
    free(p);
    return 0;
}






