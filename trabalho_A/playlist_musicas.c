#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

#define ARQUIVO_CSV "playlist.csv"
#define MAX_MUSICAS 100

// Definições de cores ANSI simples
#define ANSI_RED     "\033[1;31m"
#define ANSI_GREEN   "\033[1;32m"
#define ANSI_RESET   "\033[0m"

typedef struct Musica {
    int id;
    char titulo[50];
    char artista[50];
    int duracao;
    char genero[30];
} Musica;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausarELimpar() {
    printf("\nPressione [ENTER] para continuar...");
    limparBuffer();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int buscarPorId(Musica playlist[], int qtd, int id) {
    for (int i = 0; i < qtd; i++) {
        if (playlist[i].id == id) {
            return i; 
        }
    }
    return -1;
}

// 1. Cadastro de Música
void inserirMusica(Musica playlist[], int *qtd) {
    if (*qtd >= MAX_MUSICAS) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Não foi possível cadastrar. A playlist está cheia (%d/%d).\n", *qtd, MAX_MUSICAS);
        return;
    }

    Musica m;
    printf("\n--- Cadastrar Nova Música (%d/%d) ---\n", *qtd, MAX_MUSICAS);
    printf("Digite o ID único: ");
    if (scanf("%d", &m.id) != 1) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida de ID.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    if (buscarPorId(playlist, *qtd, m.id) != -1) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Já existe uma música cadastrada com o ID %d!\n", m.id);
        return;
    }

    printf("Título: ");
    fgets(m.titulo, 50, stdin);
    m.titulo[strcspn(m.titulo, "\n")] = '\0';

    printf("Artista: ");
    fgets(m.artista, 50, stdin);
    m.artista[strcspn(m.artista, "\n")] = '\0';

    printf("Duração (em segundos): ");
    if (scanf("%d", &m.duracao) != 1 || m.duracao <= 0) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida de duração.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Gênero: ");
    fgets(m.genero, 30, stdin);
    m.genero[strcspn(m.genero, "\n")] = '\0';

    playlist[*qtd] = m;
    (*qtd)++; 

    printf("\n" ANSI_GREEN "[SUCESSO]" ANSI_RESET " Música \"%s\" cadastrada com sucesso!\n", m.titulo);
}

// 2. Listagem de todas as músicas 
void listarPlaylist(Musica playlist[], int qtd) {
    if (qtd == 0) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " A playlist está vazia (0/%d músicas).\n", MAX_MUSICAS);
        return;
    }

    printf("\n==================== PLAYLIST (%d/%d) ====================\n", qtd, MAX_MUSICAS);
    for (int i = 0; i < qtd; i++) {
        int min = playlist[i].duracao / 60;
        int seg = playlist[i].duracao % 60;
        
        printf("ID: %d | %s - %s [%02d:%02d] | Gênero: %s\n", 
               playlist[i].id, playlist[i].titulo, playlist[i].artista, min, seg, playlist[i].genero);
    }
    printf("==================================================\n");
}

// 3. Buscar e exibir dados de uma música específica
void buscarMusica(Musica playlist[], int qtd) {
    if (qtd == 0) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " A estrutura está vazia. Não há o que buscar.\n");
        return;
    }

    int id;
    printf("\nDigite o ID da música que deseja buscar: ");
    if (scanf("%d", &id) != 1) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int pos = buscarPorId(playlist, qtd, id);
    if (pos == -1) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " Música com ID %d não encontrada.\n", id);
    } else {
        int min = playlist[pos].duracao / 60;
        int seg = playlist[pos].duracao % 60;
        printf("\n--- Música Encontrada ---\n");
        printf("ID: %d\n", playlist[pos].id);
        printf("Título: %s\n", playlist[pos].titulo);
        printf("Artista: %s\n", playlist[pos].artista);
        printf("Duração: %02d:%02d\n", min, seg);
        printf("Gênero: %s\n", playlist[pos].genero);
    }
}

// 4. Editar dados de uma música
void editarMusica(Musica playlist[], int qtd) {
    if (qtd == 0) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " A estrutura está vazia. Não há o que editar.\n");
        return;
    }

    int id;
    printf("\nDigite o ID da música que deseja editar: ");
    if (scanf("%d", &id) != 1) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int pos = buscarPorId(playlist, qtd, id);
    if (pos == -1) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " Música com ID %d não encontrada.\n", id);
        return;
    }

    printf("\n--- Editando: %s ---\n", playlist[pos].titulo);

    printf("Novo Título: ");
    fgets(playlist[pos].titulo, 50, stdin);
    playlist[pos].titulo[strcspn(playlist[pos].titulo, "\n")] = '\0';

    printf("Novo Artista: ");
    fgets(playlist[pos].artista, 50, stdin);
    playlist[pos].artista[strcspn(playlist[pos].artista, "\n")] = '\0';

    printf("Nova Duração (em segundos): ");
    if (scanf("%d", &playlist[pos].duracao) != 1 || playlist[pos].duracao <= 0) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Novo Gênero: ");
    fgets(playlist[pos].genero, 30, stdin);
    playlist[pos].genero[strcspn(playlist[pos].genero, "\n")] = '\0';

    printf("\n" ANSI_GREEN "[SUCESSO]" ANSI_RESET " Dados atualizados com sucesso!\n");
}

// 5. Excluir Música 
void excluirMusica(Musica playlist[], int *qtd) {
    if (*qtd == 0) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " A estrutura está vazia. Não há o que remover.\n");
        return;
    }

    int id;
    char confirmacao;

    printf("\nDigite o ID da música que deseja excluir: ");
    if (scanf("%d", &id) != 1) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Entrada inválida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    int pos = buscarPorId(playlist, *qtd, id);
    if (pos == -1) {
        printf("\n" ANSI_RED "[AVISO]" ANSI_RESET " Música com ID %d não encontrada.\n", id);
        return;
    }

    printf("Tem certeza que deseja excluir a música \"%s\"? (S/N): ", playlist[pos].titulo);
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao != 'S' && confirmacao != 's') {
        printf("\nExclusão cancelada.\n");
        return;
    }

    for (int i = pos; i < (*qtd) - 1; i++) {
        playlist[i] = playlist[i + 1];
    }
    
    (*qtd)--; 
    printf("\n" ANSI_GREEN "[SUCESSO]" ANSI_RESET " Música removida da playlist.\n");
}

void salvarCSV(Musica playlist[], int qtd) {
    FILE* arquivo = fopen(ARQUIVO_CSV, "w");
    if (arquivo == NULL) {
        printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Não foi possível abrir o arquivo para salvar os dados!\n");
        return;
    }

    fprintf(arquivo, "id;titulo;artista;duracao;genero\n");

    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%d;%s;%s;%d;%s\n", 
                playlist[i].id, 
                playlist[i].titulo, 
                playlist[i].artista, 
                playlist[i].duracao, 
                playlist[i].genero);
    }

    fclose(arquivo);
    printf("\n" ANSI_GREEN "[SUCESSO]" ANSI_RESET " Dados salvos com sucesso em \"%s\"!\n", ARQUIVO_CSV);
}

// 6. Carregar dados a partir do arquivo CSV
void carregarCSV(Musica playlist[], int *qtd) {
    FILE* arquivo = fopen(ARQUIVO_CSV, "r");
    if (arquivo == NULL) {
        return; 
    }

    char linha[200];
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (*qtd >= MAX_MUSICAS) {
            printf(ANSI_RED "[AVISO]" ANSI_RESET " Limite máximo atingido ao carregar o arquivo CSV.\n");
            break;
        }

        Musica m;
        char* token = strtok(linha, ";");
        if (token != NULL) m.id = atoi(token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(m.titulo, token);

        token = strtok(NULL, ";");
        if (token != NULL) strcpy(m.artista, token);

        token = strtok(NULL, ";");
        if (token != NULL) m.duracao = atoi(token);

        token = strtok(NULL, ";\n");
        if (token != NULL) strcpy(m.genero, token);

        if (buscarPorId(playlist, *qtd, m.id) == -1) {
            playlist[*qtd] = m;
            (*qtd)++;
        } else {
            printf(ANSI_RED "[AVISO]" ANSI_RESET " ID duplicado encontrado no CSV (%d). Registro ignorado.\n", m.id);
        }
    }

    fclose(arquivo);
    printf("[SISTEMA] Playlist anterior carregada com sucesso (%d músicas)!\n", *qtd);
}

// 7. Estatísticas da playlist
void mostrarEstatisticas(Musica playlist[], int qtd) {
    if (qtd == 0) {
        printf("\nPlaylist vazia.\n");
        return;
    }

    int tempoTotal = 0;
    for (int i = 0; i < qtd; i++) {
        tempoTotal += playlist[i].duracao;
    }

    printf("\n===== ESTATÍSTICAS =====\n");
    printf("Total de músicas cadastradas: %d/%d\n", qtd, MAX_MUSICAS);
    printf("Tempo total de reprodução: %d minutos e %d segundos\n",
           tempoTotal / 60,
           tempoTotal % 60);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Musica playlist[MAX_MUSICAS];
    int qtdMusicas = 0; 
    int opcao;

    carregarCSV(playlist, &qtdMusicas);

    do {
        // Menu Playlist
        printf("\n");
        printf("     ;;;;;;;;;;;;;;;;;;;    ======= MENU PLAYLIST =======\n");
        printf("     ;;;;;;;;;;;;;;;;;;;    |1. Cadastrar Música        |\n");   
        printf("     ;                 ;    |2. Listar Playlist         |\n");
        printf("     ;                 ;    |3. Buscar por ID           |\n");
        printf("     ;                 ;    |4. Editar Música           |\n");
        printf("     ;                 ;    |5. Excluir Música          |\n");
        printf("     ;                 ;    |6. Salvar Dados (CSV)      |\n");
        printf("     ;                 ;    |7. Estatísticas            |\n");
        printf("     ;                 ;    |0. Sair                    |\n");
        printf(",;;;;;            ,;;;;;    =============================\n");
        printf(";;;;;;            ;;;;;;\n");
        printf("`;;;;'            `;;;;'\n");
        printf("                             Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Por favor, digite um número.\n");
            limparBuffer();
            pausarELimpar();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                inserirMusica(playlist, &qtdMusicas);
                pausarELimpar();
                break;
            case 2:
                listarPlaylist(playlist, qtdMusicas);
                pausarELimpar();
                break;
            case 3:
                buscarMusica(playlist, qtdMusicas);
                pausarELimpar();
                break;
            case 4:
                editarMusica(playlist, qtdMusicas);
                pausarELimpar();
                break;
            case 5:
                excluirMusica(playlist, &qtdMusicas);
                pausarELimpar();
                break;
            case 6:
                salvarCSV(playlist, qtdMusicas);
                pausarELimpar();
                break;
            case 7:
                mostrarEstatisticas(playlist, qtdMusicas);
                pausarELimpar();
                break;
            case 0:
                printf("\nSalvando alterações pendentes no arquivo CSV...\n");
                salvarCSV(playlist, qtdMusicas);
                printf("Encerrando o programa com segurança.\n");
                break;
            default:
                printf("\n" ANSI_RED "[ERRO]" ANSI_RESET " Opção inválida!\n");
                pausarELimpar();
        }
    } while (opcao != 0);

    return 0;
}
