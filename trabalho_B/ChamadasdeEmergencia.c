#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

#define MAX 10

// PILHAS DINAMICAS LIFO = Última chamada a entrar será a primeira a sair
/*=============================================================
    |   CAMPO    |   TIPO     |        DESCRIÇÂO          |
    |------------|------------|---------------------------|
    |  protocolo |    int     |  Número único da chamada  |
    |   local    |  char[50]  |  local da emergência      |
    |   tipo     |  chat[30]  |  Tipo da ocorrência       |
    |  horario   |  char[20]  |  Horário da chamada       |

==============================================================*/
struct registro{
    int protocolo;  // começa do 1001
    char local[50]; // cidade
    char tipo[30]; // polia - samu - bombeiro
    char horario[20]; // hh/mm
};

struct registro rg[MAX];

int topo = -1;
int protocoloAtual = 1000;


void inicializarPilha(){
    topo = -1;
    protocoloAtual = 1000;
}

void strLower(char *str){
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
    
}

void imprimir(struct registro r[], int topo, int idc){
    // verificar lista cheia
    if(topo == -1){
        printf("Nenhuma chamada registrada!\n");
        Sleep(2000);
        return;
    }
    
    // imprimir 1 ou toda a lista
    if (idc >= 0){
        printf("Protocolo: %d\n", r[idc].protocolo);
        printf("Local: %s\n", r[idc].local);
        printf("Tipo: %s\n", r[idc].tipo);
        printf("Horario: %s\n", r[idc].horario);
    }else {
        system("cls");
        for (int i = 0; i <= topo; i++){
            printf("Protocolo: %d\n", r[i].protocolo);
            printf("Local: %s\n", r[i].local);
            printf("Tipo: %s\n", r[i].tipo);
            printf("Horario: %s\n", r[i].horario);
            printf("-------------------\n");
        }
        system("pause");
    }
    return;
}

void registrarChamada(struct registro r[], int *topo){
    system("cls");
    struct registro novo;
    bool pass = false;

    printf("=== Registro de Chamadas ===\n");

    //verificar se a pilha esta cheia
    if(*topo == MAX -1){
        printf("Registro cheio!\n");
        Sleep(2000);
        return;
    }

    // Protocolo
    protocoloAtual++;
    novo.protocolo = protocoloAtual;
    printf("Protocolo: %d\n", novo.protocolo);

    // local
    do{
        printf("Digite o local: ");
        fgets(novo.local, sizeof(novo.local), stdin);
        novo.local[strcspn(novo.local, "\n")] = '\0'; // substitui o \n pelo \0
        strLower(novo.local);

        // verificar se ficou vazio
        if(novo.local[0] == '\0'){
            printf("Nenhum local informado!\n");
            Sleep(2000);
            pass = false;
        } else{
            pass = true;
        }
    } while (pass == false);

    // Tipo
    do{
        printf("Digite o tipo da emergência(policia, samu, bombeiro): ");
        fgets(novo.tipo, sizeof(novo.tipo), stdin);
        novo.tipo[strcspn(novo.tipo, "\n")] = '\0'; // substitui o \n pelo \0
        strLower(novo.tipo);

        // verificar tipo valido
        if(strcmp(novo.tipo, "policia") != 0 &&
           strcmp(novo.tipo, "samu") != 0 &&
           strcmp(novo.tipo, "bombeiro") != 0){
            printf("Tipo inválido\n");
            Sleep(2000);
            pass = false;
        } else{
            pass = true;
        }
    } while (pass == false);

    // horario
    int hora, minuto;
    do{
        pass = false;

        printf("digite o horario(hh:mm): ");
        fgets(novo.horario, sizeof(novo.horario), stdin);

        //verificar se digitou certo
        if (sscanf(novo.horario, "%d:%d", &hora, &minuto) == 2){
            if (hora >= 0 && hora <= 23 &&
                minuto >= 0 && minuto <= 59)
            {
                pass = true;
            }
        }

        if (!pass){
            printf("Horario invalido! Use o formato hh:mm\n");
        }

    } while (pass == false);

    // Empilhar
    (*topo)++;
    r[*topo] = novo;
    printf("Registro realizado com sucesso!\n");
    Sleep(2000);
       
}

void atenderChamada(struct registro r[], int *topo){
    system("cls");
    //verificar se esta vazia
    if(*topo == -1){
        printf("Nenhuma chamada registrada!\n");
        Sleep(2000);
        return;
    }

    printf("==== Atendendo protocolo ====\n ");
    imprimir(r, *topo, *topo);

    (*topo)--;
    system("pause");
    return;
}

int main(){
    int op;
    system("cls");
    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("=== Chamadas de Emergência ===\n");
        printf("1. Registrar chamada\n");
        printf("2. Atender chamada\n");
        printf("3. Consultar última chamada\n");
        printf("4. Mostrar todas as chamadas\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar(); //limpar buffet do teclado

        switch(op){
        case 1:
            registrarChamada(rg, &topo);
            break;
        case 2:
            atenderChamada(rg, &topo);
            break;
        case 3:
            imprimir(rg, topo, topo);
            break;
        case 4:
            imprimir(rg, topo, -1);
            break;
        case 5:
            printf("Saindo...\n");
            Sleep(1000);
            break;
        default:
            printf("Opção invalida!\n");
            Sleep(1500);
            break;
        }
    } while (op != 5);
    return 0;
}