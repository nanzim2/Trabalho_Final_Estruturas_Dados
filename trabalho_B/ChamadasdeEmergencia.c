#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

typedef struct registro{
    int protocolo;
    char local[50];
    char tipo[30];
    char horario[20];

    struct registro *prox;
} Registro;

Registro *topo = NULL;
int protocoloAtual = 1000;

void registrarChamada()
{
    Registro *novo = (Registro*) malloc(sizeof(Registro));

    if(novo == NULL){
        printf("Erro de memoria!\n");
        return;
    }

    protocoloAtual++;
    novo->protocolo = protocoloAtual;

    printf("Protocolo %d\n", protocoloAtual);

    printf("Local: ");
    fgets(novo->local,50,stdin);
    novo->local[strcspn(novo->local,"\n")] = '\0';

    printf("Tipo (policia/samu/bombeiro): ");
    fgets(novo->tipo,30,stdin);
    novo->tipo[strcspn(novo->tipo,"\n")] = '\0';

    printf("Horario (hh:mm): ");
    fgets(novo->horario,20,stdin);
    novo->horario[strcspn(novo->horario,"\n")] = '\0';

    novo->prox = topo;
    topo = novo;

    printf("Chamada registrada!\n");
}

void atenderChamada()
{
    if(topo == NULL){
        printf("Nenhuma chamada registrada!\n");
        return;
    }

    Registro *aux = topo;

    printf("\n=== ATENDENDO ===\n");
    printf("Protocolo: %d\n", aux->protocolo);
    printf("Local: %s\n", aux->local);
    printf("Tipo: %s\n", aux->tipo);
    printf("Horario: %s\n", aux->horario);

    topo = topo->prox;

    free(aux);

    printf("\nChamada atendida!\n");
}

void consultarUltima()
{
    if(topo == NULL){
        printf("Pilha vazia!\n");
        return;
    }

    printf("\n=== ULTIMA CHAMADA ===\n");
    printf("Protocolo: %d\n", topo->protocolo);
    printf("Local: %s\n", topo->local);
    printf("Tipo: %s\n", topo->tipo);
    printf("Horario: %s\n", topo->horario);
}

void listar()
{
    Registro *aux = topo;

    if(aux == NULL){
        printf("Pilha vazia!\n");
        return;
    }

    while(aux != NULL){

        printf("\nProtocolo: %d\n", aux->protocolo);
        printf("Local: %s\n", aux->local);
        printf("Tipo: %s\n", aux->tipo);
        printf("Horario: %s\n", aux->horario);

        aux = aux->prox;
    }
}

void buscarProtocolo()
{
    int protocolo;
    Registro *aux = topo;

    printf("Digite o protocolo: ");
    scanf("%d",&protocolo);
    getchar();

    while(aux != NULL){

        if(aux->protocolo == protocolo){

            printf("\nEncontrado!\n");
            printf("Local: %s\n", aux->local);
            printf("Tipo: %s\n", aux->tipo);
            printf("Horario: %s\n", aux->horario);

            return;
        }

        aux = aux->prox;
    }

    printf("Protocolo nao encontrado!\n");
}

void salvarCSV()
{
    FILE *arq = fopen("chamadas.csv","w");

    printf("Tentando criar arquivo...\n");
    if(arq == NULL){
        perror("Erro");
        return;
    }

    if(arq == NULL){
        printf("Erro ao criar arquivo!\n");
        return;
    }

    Registro *aux = topo;

    fprintf(arq,"protocolo;local;tipo;horario\n");

    while(aux != NULL){

        fprintf(arq,"%d;%s;%s;%s\n",
            aux->protocolo,
            aux->local,
            aux->tipo,
            aux->horario);

        aux = aux->prox;
    }

    fclose(arq);

    printf("Arquivo salvo!\n");
}

void carregarCSV()
{
    FILE *arq = fopen("chamadas.csv","r");

    if(arq == NULL)
        return;

    char linha[200];

    fgets(linha,sizeof(linha),arq);

    while(fgets(linha,sizeof(linha),arq)){

        Registro *novo = (Registro*) malloc(sizeof(Registro));

        if(novo == NULL){
            printf("Erro de memoria!\n");
            fclose(arq);
            return;
        }

        sscanf(linha,"%d;%49[^;];%29[^;];%19[^\n]",
               &novo->protocolo,
               novo->local,
               novo->tipo,
               novo->horario);

        if(novo->protocolo > protocoloAtual)
            protocoloAtual = novo->protocolo;

        novo->prox = topo;
        topo = novo;
    }

    fclose(arq);
}

void liberarPilha()
{
    Registro *aux;

    while(topo != NULL){

        aux = topo;
        topo = topo->prox;

        free(aux);
    }
}

int main()
{
    int op;

    setlocale(LC_ALL, "Portuguese");

    carregarCSV();

    do{
        system("cls");

        printf("===== CHAMADAS DE EMERGENCIA =====\n");
        printf("1 - Registrar chamada\n");
        printf("2 - Atender chamada\n");
        printf("3 - Consultar ultima chamada\n");
        printf("4 - Listar chamadas\n");
        printf("5 - Buscar protocolo\n");
        printf("6 - Salvar arquivo CSV\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        system("cls");

        switch(op)
        {
            case 1:
                registrarChamada();
                break;

            case 2:
                atenderChamada();
                break;

            case 3:
                consultarUltima();
                break;

            case 4:
                listar();
                break;

            case 5:
                buscarProtocolo();
                break;

            case 6:
                salvarCSV();
                break;

            case 7:
                salvarCSV();
                liberarPilha();
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        if(op != 7)
        {
            printf("\n\nPressione ENTER para continuar...");
            getchar();
        }

    }while(op != 7);

    return 0;
}