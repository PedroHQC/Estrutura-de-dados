#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numerador = 0;

struct contaface{
	char nome[50];
	int idade;
  int id;
	struct contaface *prox;
	struct contaface *amigos;
};

typedef struct contaface ponteiros;
ponteiros *primeiro;

void barra(){
	printf("================================\n");
}

void cadastro(){
	ponteiros *conta = malloc(sizeof(ponteiros));
	printf("Nome: ");
  fgets(conta->nome , 50 , stdin);

	printf("Idade: ");
	scanf("%i", &conta->idade);
	getchar();

  numerador = numerador +1;
  conta->id = numerador;

	conta->prox = NULL;

	if(primeiro == NULL){
		primeiro = conta;
	}
	else{
		ponteiros *aux = primeiro;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = conta;
	}


}

void imprimir(ponteiros *p){
  printf("%s\n%s\n", p->nome, p->amigos->nome);

}
void procurar(char nome[50], ponteiros *p){
  if(strcmp(nome,p->nome)==0){
    barra();
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Id: %d\n", p->id);
    barra();
  }
  else{
    procurar(nome, p->prox);
  }
}

void addfriend(int a1, int a2, ponteiros *p){
  ponteiros *aux2 = primeiro;
  aux2 = p;
  if(p == NULL){
    printf("Sem contas disponiveis, cadastre-se antes de adicionar um amigo.\n");
    exit(0);
  }
  else{
  while(a1 != aux2->id){
    aux2 = aux2->prox;
  }
  if(a1 == aux2->id){
    ponteiros *aux3 = primeiro;
    while(a2 != aux3->id && aux3->prox != NULL){
      aux3 = aux3->prox;
    }
    if(a2 == aux3->id){
      ponteiros *aux = aux2;
      while(aux->amigos != NULL){
        aux = aux->amigos;
      }
      aux->amigos = aux3;
    }
    else{
      int valor;
      printf("Nao foi possivel encontrar o seu amigo, deseja cadastra-lo?\n1-Sim.\n2-Nao.\n");
      scanf("%i", &valor);
      getchar();
      if(valor == 1){
        cadastro();
        addfriend(a1,a2,p);
      }
      else{
        printf("Retornando ao menu\n");
      }
    }
  }
  else{
    printf("impossivel cadastrar alguem em uma conta inexistente. Tente novamente com outro id\n");
  }
  }
  printf("\nAgora %s e %s sao amigos!!", aux2->nome, aux2->amigos->nome);
}


int main(){
  	int i=0, op, moderador = 0;
    do{
  	printf(" 1-Cadastrar\n 2-Procurar pessoa por nome\n 3-Adicionar amigo\n 4-Sair\n Escolha: ");
  	scanf("%d", &op);
    getchar();
	  switch(op){
    case 1:{
      		cadastro();
        }
     break;
    case 2:{
      char nome[50];
      fgets(nome, 50, stdin);
      procurar(nome, primeiro);

    }
    break;
    case 3:{
      int v1, v2;
      printf("digite o seu id e em seguida o id de seu amigo: ");
      scanf("%i\n%i", &v1, &v2);
      addfriend(v1,v2,primeiro);
    }
    break;
    case 4:{
      barra();
      printf("Fechando!\n");
      barra();
      moderador = -1;
    }
    break;
    default:
    barra();
    printf("Escolha invalida!\n");
    barra();
    }
    }
    while(moderador != -1);
return 0;
}
