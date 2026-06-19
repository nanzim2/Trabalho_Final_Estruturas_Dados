#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_CSV "playlist.csv"
#define MAX_MUSICAS 100


typedef struct Musica {
    int id;
    char titulo[50];
    char artista[50];
    int duracao; // em segundos
    char genero[30];
} Musica;

// Definição do Nó da Lista Duplamente Encadeada 
typedef struct Node {
    Musica dado;
    struct Node* anterior;
    struct Node* proximo;
} Node;

int qtdMusicas = 0;

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

// Função para buscar uma música pelo ID
Node* buscarPorId(Node* inicio, int id) {
    Node* atual = inicio;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Inserção no fim da lista com controle de limite máximo
void inserirNoFim(Node** inicio, Node** fim, Musica novaMusica) {
    // Tratamento de Estrutura Cheia 
    if (qtdMusicas >= MAX_MUSICAS) {
        printf("\n[ERRO] Estrutura Cheia! Limite de %d musicas atingido.\n", MAX_MUSICAS);
        return;
    }

    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("\n[ERRO] Falha na alocacao de memoria!\n");
        return;
    }
    novoNo->dado = novaMusica;
    novoNo->proximo = NULL;

    if (*inicio == NULL) {
        novoNo->anterior = NULL;
        *inicio = novoNo;
        *fim = novoNo;
    } else {
        novoNo->anterior = *fim;
        (*fim)->proximo = novoNo;
        *fim = novoNo;
    }
    qtdMusicas++; // Incrementa contador
}

// 1. Cadastrar Música (Com verificação de chave duplicada e estrutura cheia)
void inserirMusica(Node** inicio, Node** fim) {
    // Tratamento prévio de Estrutura Cheia
    if (qtdMusicas >= MAX_MUSICAS) {
        printf("\n[ERRO] Não é possível cadastrar. A playlist está cheia (%d/%d).\n", qtdMusicas, MAX_MUSICAS);
        return;
    }

    Musica m;
    printf("\n--- Cadastrar Nova Musica (%d/%d) ---\n", qtdMusicas, MAX_MUSICAS);
    printf("Digite o ID unico: ");
    if (scanf("%d", &m.id) != 1) {
        printf("\n[ERRO] Entrada invalida de ID.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    // Validação de ID único
    if (buscarPorId(*inicio, m.id) != NULL) {
        printf("\n[ERRO] Já existe uma música cadastrada com o ID %d!\n", m.id);
        return;
    }

    printf("Titulo: ");
    fgets(m.titulo, 50, stdin);
    m.titulo[strcspn(m.titulo, "\n")] = '\0';

    printf("Artista: ");
    fgets(m.artista, 50, stdin);
    m.artista[strcspn(m.artista, "\n")] = '\0';

    printf("Duracao (em segundos): ");
    if (scanf("%d", &m.duracao) != 1 || m.duracao <= 0) {
        printf("\n[ERRO] Entrada invalida de duração.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Genero: ");
    fgets(m.genero, 30, stdin);
    m.genero[strcspn(m.genero, "\n")] = '\0';

    inserirNoFim(inicio, fim, m);
    printf("\n[SUCESSO] Música \"%s\" cadastrada com sucesso!\n", m.titulo);
}

// 2. Listar todas as músicas (Tratamento de estrutura vazia)
void listarPlaylist(Node* inicio) {
    // Tratamento de Estrutura Vazia
    if (inicio == NULL || qtdMusicas == 0) {
        printf("\n[AVISO] A playlist esta vazia (0/%d musicas).\n", MAX_MUSICAS);
        return;
    }

    printf("\n==================== PLAYLIST (%d/%d) ====================\n", qtdMusicas, MAX_MUSICAS);
    Node* atual = inicio;
    while (atual != NULL) {
        int min = atual->dado.duracao / 60;
        int seg = atual->dado.duracao % 60;
        
        printf("ID: %d | %s - %s [%02d:%02d] | Genero: %s\n", 
               atual->dado.id, atual->dado.titulo, atual->dado.artista, min, seg, atual->dado.genero);
        atual = atual->proximo;
    }
    printf("==================================================\n");
}

// 3. Buscar e exibir dados de uma música específica
void buscarMusica(Node* inicio) {
    if (inicio == NULL) {
        printf("\n[AVISO] A estrutura esta vazia. Não há o que buscar.\n");
        return;
    }

    int id;
    printf("\nDigite o ID da musica que deseja buscar: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[ERRO] Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    Node* encontrado = buscarPorId(inicio, id);
    if (encontrado == NULL) {
        printf("\n[AVISO] Música com ID %d não encontrada.\n", id);
    } else {
        int min = encontrado->dado.duracao / 60;
        int seg = encontrado->dado.duracao % 60;
        printf("\n--- Música Encontrada ---\n");
        printf("ID: %d\n", encontrado->dado.id);
        printf("Titulo: %s\n", encontrado->dado.titulo);
        printf("Artista: %s\n", encontrado->dado.artista);
        printf("Duracao: %02d:%02d\n", min, seg);
        printf("Genero: %s\n", encontrado->dado.genero);
    }
}

// 4. Editar dados de uma música (Campos não-chave)
void editarMusica(Node* inicio) {
    if (inicio == NULL) {
        printf("\n[AVISO] A estrutura está vazia. Não há o que editar.\n");
        return;
    }

    int id;
    printf("\nDigite o ID da musica que deseja editar: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[ERRO] Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    Node* encontrado = buscarPorId(inicio, id);
    if (encontrado == NULL) {
        printf("\n[AVISO] Música com ID %d não encontrada.\n", id);
        return;
    }

    printf("\n--- Editando: %s ---\n", encontrado->dado.titulo);

    printf("Novo Titulo: ");
    fgets(encontrado->dado.titulo, 50, stdin);
    encontrado->dado.titulo[strcspn(encontrado->dado.titulo, "\n")] = '\0';

    printf("Novo Artista: ");
    fgets(encontrado->dado.artista, 50, stdin);
    encontrado->dado.artista[strcspn(encontrado->dado.artista, "\n")] = '\0';

    printf("Nova Duracao (em segundos): ");
    if (scanf("%d", &encontrado->dado.duracao) != 1 || encontrado->dado.duracao <= 0) {
        printf("\n[ERRO] Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    printf("Novo Genero: ");
    fgets(encontrado->dado.genero, 30, stdin);
    encontrado->dado.genero[strcspn(encontrado->dado.genero, "\n")] = '\0';

    printf("\n[SUCESSO] Dados atualizados com sucesso!\n");
}

// 5. Excluir Música da playlist (Tratamento de estrutura vazia)
void excluirMusica(Node** inicio, Node** fim) {
    if (*inicio == NULL) {
        printf("\n[AVISO] A estrutura esta vazia. Não há o que remover.\n");
        return;
    }

    int id;
    char confirmacao;

    printf("\nDigite o ID da musica que deseja excluir: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[ERRO] Entrada invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    Node* deletar = buscarPorId(*inicio, id);
    if (deletar == NULL) {
        printf("\n[AVISO] Música com ID %d não encontrada.\n", id);
        return;
    }

    printf("Tem certeza que deseja excluir a música \"%s\"? (S/N): ", deletar->dado.titulo);
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao != 'S' && confirmacao != 's') {
        printf("\nExclusão cancelada.\n");
        return;
    }

    if (deletar == *inicio && deletar == *fim) {
        *inicio = NULL;
        *fim = NULL;
    }
    else if (deletar == *inicio) {
        *inicio = deletar->proximo;
        (*inicio)->anterior = NULL;
    }
    else if (deletar == *fim) {
        *fim = deletar->anterior;
        (*fim)->proximo = NULL;
    }
    else {
        deletar->anterior->proximo = deletar->proximo;
        deletar->proximo->anterior = deletar->anterior;
    }

    free(deletar);
    qtdMusicas--; // Decrementa contador (Controle da estrutura)
    printf("\n[SUCESSO] Música removida da playlist.\n");
}

// 6. Salvar dados em formato CSV
void salvarCSV(Node* inicio) {
    FILE* arquivo = fopen(ARQUIVO_CSV, "w");
    if (arquivo == NULL) {
        printf("\n[ERRO] Não foi possivel abrir o arquivo para salvar os dados!\n");
        return;
    }

    fprintf(arquivo, "id;titulo;artista;duracao;genero\n");

    Node* atual = inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%d;%s;%s;%d;%s\n", 
                atual->dado.id, 
                atual->dado.titulo, 
                atual->dado.artista, 
                atual->dado.duracao, 
                atual->dado.genero);
        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("\n[SUCESSO] Dados salvos com sucesso em \"%s\"!\n", ARQUIVO_CSV);
}

// 7. Carregar dados a partir do arquivo CSV
void carregarCSV(Node** inicio, Node** fim) {
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
        // Valida se o arquivo não vai estourar o limite máximo configurado
        if (qtdMusicas >= MAX_MUSICAS) {
            printf("[AVISO] Limite maximo atingido ao carregar o arquivo CSV.\n");
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

        inserirNoFim(inicio, fim, m);
    }

    fclose(arquivo);
    printf("[SISTEMA] Playlist anterior carregada com sucesso (%d musicas)!\n", qtdMusicas);
}

// Liberação de memória ao fechar o programa
void liberarLista(Node* inicio) {
    Node* atual = inicio;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    qtdMusicas = 0;
}

int main() {
    Node* playlistInicio = NULL;
    Node* playlistFim = NULL;
    int opcao;

    carregarCSV(&playlistInicio, &playlistFim);

    do {
        printf("\n======= MENU PLAYLIST =======\n");
        printf("1. Cadastrar Música\n");
        printf("2. Listar Playlist\n");
        printf("3. Buscar por ID\n");
        printf("4. Editar Musica\n");
        printf("5. Excluir Musica\n");
        printf("6. Salvar Dados (CSV)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Por favor, digite um número.\n");
            limparBuffer();
            pausarELimpar();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                inserirMusica(&playlistInicio, &playlistFim);
                pausarELimpar();
                break;
            case 2:
                listarPlaylist(playlistInicio);
                pausarELimpar();
                break;
            case 3:
                buscarMusica(playlistInicio);
                pausarELimpar();
                break;
            case 4:
                editarMusica(playlistInicio);
                pausarELimpar();
                break;
            case 5:
                excluirMusica(&playlistInicio, &playlistFim);
                pausarELimpar();
                break;
            case 6:
                salvarCSV(playlistInicio);
                pausarELimpar();
                break;
            case 0:
                printf("\nSalvando alterações pendentes...\n");
                salvarCSV(playlistInicio);
                printf("Encerrando o programa e liberando mémoria...\n");
                liberarLista(playlistInicio);
                break;
            default:
                printf("\n[ERRO] Opção inválida!\n");
                pausarELimpar();
        }
    } while (opcao != 0);

    return 0;
}