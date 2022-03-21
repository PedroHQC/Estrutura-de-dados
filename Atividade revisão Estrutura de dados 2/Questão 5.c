#include <stdio.h>

int main(){
	int alunos, i, j;
	float nota_1[alunos], nota_2[alunos];
	printf("Quantos alunos?");
	scanf("%d", &alunos);
	for(i = 0; i<alunos; i++){
		printf("Digite as notas do %d aluno \n Primeira: ", i+1);
		scanf("%f", &nota_1[i]);
		printf("Segunda: ");
		scanf("%f", &nota_2[i]);
	}
	
	for(j = 0; j < alunos; j++){
	if((nota_1[j] == 50)||(nota_2[j] == 50)){
		return 0;
	}
	else if((nota_1[j] < 0) || (nota_1[j] > 10) || (nota_2[j] < 0)||(nota_2[j]>10)){
		printf("notas do %d aluno invalidas\n", j+1);
	}
	else{
	
		printf("a media do %d aluno e: %0.2f\n", j+1, (nota_1[j] + nota_2[j])/2);
	}
	}
	return 0;
}
