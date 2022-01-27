#include <stdio.h>
#include <string.h>

struct contato{
char nome[20];
char email[20];
char rua[30];
char bairro[30];
char numero_casa[10];
char cep[9];
char cidade[30];
char estado[20];
char observacoes[40];
char ddd[2];
char numero_telefone[10];
char nasc_mes[2];
char nasc_ano[4];
char nasc_dia[2];
char pais[15];
char complemento[30];
struct contato *prox;

};
struct contato agenda;
int aux, aux2;
char procurador_nome[20];
typedef struct contato ponteiro;
ponteiro *primeiro;
void addStart(){
    ponteiro *p = malloc(sizeof (ponteiro));
    printf("Digite as informacoes do novo contato SEM O USO DE ESPAÇOS!: \n");

                printf("Nome:");
                scanf("%s", agenda.nome);
                p-> nome;
                printf("==========Data de nascimento==========\n");
                printf("Dia: ");
                scanf("%s", agenda.nasc_dia);
                p->nasc_dia;
                printf("Mes: ");
                scanf("%s", agenda.nasc_mes);
                p->nasc_mes;
                printf("Ano: ");
                scanf("%s", agenda.nasc_ano);
                p->nasc_ano;
                printf("==========Telefone==========\n");
                printf("DDD: ");
                scanf("%s", agenda.ddd);
                p->ddd;
                printf("Numero: ");
                scanf("%s", agenda.numero_telefone);
                p->numero_telefone;
                printf("==========Endereço==========\n");
                printf("CEP: ");
                scanf("%s", agenda.cep);
                p->cep;
                printf("Pais: ");
                scanf("%s", agenda.pais);
                p->pais;
                printf("Estado: ");
                scanf("%s", agenda.estado);
                p->estado;
                printf("Cidade: ");
                scanf("%s", agenda.cidade);
                p->cidade;
                printf("Bairro: ");
                scanf("%s", agenda.bairro);
                p->bairro;
                printf("Rua: ");
                scanf("%s", agenda.rua);
                p->rua;
                printf("Numero residencial: ");
                scanf("%s", agenda.numero_casa);
                p->numero_casa;
                printf("Complemento: ");
                scanf("%s", agenda.complemento);
                p->complemento;
                printf("Observacao especial: ");
                scanf("%s", agenda.observacoes);
                p->observacoes;
                printf("CONTATO REGISTRADO!!!\n");
                p->prox =primeiro;
                primeiro = p;
}
void imprimir(char x[20]){
    ponteiro *aux5 = primeiro;
    if(aux5!=NULL)
                    {
                        aux =strcmp(procurador_nome,agenda.nome);
                        if(aux == 0){
                            printf("==============================\n");
                            printf("Nome: %s\n", agenda.nome);
                            printf("Data de nascimento: %s/%s/%s\n", agenda.nasc_dia,agenda.nasc_mes,agenda.nasc_ano);
                            printf("Telefone/E-mail: (%s)%s/%s\n", agenda.ddd, agenda.numero_telefone, agenda.email);
                            printf("Endereco: %s, %s, %s, Nu:%s\n", agenda.cidade, agenda.bairro, agenda.rua, agenda.numero_casa);
                            printf("Complemento: %s\n", agenda.complemento);
                            printf("Estado: %s, %s\n", agenda.estado, agenda.pais);
                            printf("CEP: %s\n", agenda.cep);
                            printf("Observacoes: %s\n", agenda.observacoes);
                            printf("==============================\n");
                            aux2 = -2001;
                            aux5= aux5->prox;
                        }
                        else if(aux != 0){
                            aux5= aux5->prox;
                            aux2++;
                        }
}
aux2 = 0;
}
void imprimirtodos(ponteiro *p){

if(p != NULL){
    printf("==============================\n");
    printf("Nome: %s\n", agenda.nome);
                            printf("Data de nascimento: %s/%s/%s\n", agenda.nasc_dia,agenda.nasc_mes,agenda.nasc_ano);
                            printf("Telefone/E-mail: (%s)%s/%s\n", agenda.ddd, agenda.numero_telefone, agenda.email);
                            printf("Endereco: %s, %s, %s, Nu:%s\n", agenda.cidade, agenda.bairro, agenda.rua, agenda.numero_casa);
                            printf("Complemento: %s\n", agenda.complemento);
                            printf("Estado: %s, %s\n", agenda.estado, agenda.pais);
                            printf("CEP: %s\n", agenda.cep);
                            printf("Observacoes: %s\n", agenda.observacoes);
                            printf("==============================\n");

imprimirtodos(p->prox);
}
}
int main(){
    int op, moderador = 0;
    char  procurador_mes[2], procurador_dia[2];
    do{
            imprimirtodos(primeiro);

    printf("==========MENU==========\n""O que deseja fazer?\n""1 - Procurar contato.\n""2 - Adicionar contato.\n""3 - Fechar agenda.\n""========================\n""Opcao: ");
    scanf("%i", &op);
    switch(op){
        case 1:{
                    int i = 0;
                    printf("Digite o nome desejado: ");
                    scanf("%s", procurador_nome);
                    imprimir(procurador_nome);

                    if(aux2 > 0)
                        printf("Nome nao encontrado.\n");
                        }
                break;
            case 2:{
                addStart();
            }
                break;
                case 3:{
                moderador = -1;
            }
            break;
            }


        }


        while(moderador != -1);



    return 0;

}
