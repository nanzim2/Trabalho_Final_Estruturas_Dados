# Trabalho Final - Estruturas de Dados

## Integrantes

* Íris Conceição Candido da Silva 
* Matheus Macedo Araújo
* Renan Pires Andrade
* Tailane de Santana Brito

## Turma

Turma: C

---

## Temas Escolhidos

### Trabalho A

Tema A1 — Playlist de Músicas

### Trabalho B

Tema B2 – Chamadas de Emergência

### Trabalho C

Tema: [Informar Tema Escolhido]

---

## Estrutura do Repositório

```text
Trabalho_Final_Estruturas_Dados/

README.md

Trabalho_A/
    playlist_musicas.c
    playlist.csv

Trabalho_B/
    ChamadasDeEmergencia.c
    chamadas.csv

Trabalho_C/
    trabalho_c.c
    dados_c.csv

relatorio.md
```
---

## Descrição dos Programas:

### Trabalho A — Playlist de Músicas

Sistema de gerenciamento de uma playlist de músicas utilizando uma Lista Duplamente Encadeada Dinâmica.

Cada música possui:

* ID único;
* Título;
* Artista;
* Duração (em segundos);
* Gênero musical.

---

### Funcionalidades implementadas

* Cadastrar música;
* Buscar música por ID;
* Editar informações da música;
* Excluir música da playlist;
* Listar todas as músicas cadastradas;
* Salvar dados em arquivo CSV;
* Carregar dados de arquivo CSV;
* Controle de limite máximo de registros;
* Validação de chave única (ID);
* Liberação de memória utilizando `free()` ao encerrar o programa.

---

### Estruturas e conceitos utilizados

* Structs;
* Ponteiros;
* Alocação dinâmica com `malloc()`;
* Liberação de memória com `free()`;
* Manipulação de arquivos CSV;
* Lista Duplamente Encadeada;
* Busca sequencial;
* Tratamento de erros e validação de entradas.

---

## Compilação

Para compilar o programa utilizando o GCC:

```bash
gcc playlist_musicas.c -o playlist
```
---

## Execução

Após a compilação, execute o programa no Linux com:

```bash
./playlist
```

No Windows:

```bash
playlist.exe
```
---

## Funcionamento

Ao iniciar, o sistema tenta carregar automaticamente os dados armazenados no arquivo `playlist.csv`.

O usuário interage com um menu contendo as opções de:

1. Cadastrar música;
2. Listar playlist;
3. Buscar música por ID;
4. Editar música;
5. Excluir música;
6. Salvar dados em CSV;
7. Encerrar programa.

Ao finalizar a execução, os dados são salvos automaticamente e toda a memória alocada dinamicamente é liberada.

---

## Arquivos CSV

O programa utiliza arquivos CSV para armazenamento permanente dos dados da playlist.

### Exemplo de arquivo utilizado no Trabalho A

```csv
id;titulo;artista;duracao;genero
1;Believer;Imagine Dragons;204;Rock
2;Shape of You;Ed Sheeran;233;Pop
3;Blinding Lights;The Weeknd;200;Pop
```
---

## Observações

* Os dados são carregados automaticamente ao iniciar o programa.
* Os dados podem ser salvos manualmente através da opção **"Salvar Dados (CSV)"** do menu.
* Ao encerrar o programa, os dados são salvos automaticamente no arquivo `playlist.csv`.
* Toda a memória alocada dinamicamente é liberada antes do encerramento do sistema.
* O programa utiliza uma **Lista Duplamente Encadeada Dinâmica** para armazenamento dos registros em memória.
* Cada música possui um **ID único**, impedindo cadastros duplicados.
  
### O sistema possui tratamento para:

* Estrutura vazia;
* Estrutura cheia (limite de 100 músicas);
* IDs duplicados;
* Entradas inválidas do usuário;
* Falhas de alocação de memória.
* As estruturas de dados foram implementadas manualmente, sem utilização de bibliotecas prontas de listas.
* Os dados permanecem disponíveis entre diferentes execuções do programa através do arquivo CSV.
---

## Dificuldades Encontradas

Durante o desenvolvimento, os principais desafios foram:

* Implementação correta da lista duplamente encadeada;
* Controle dos ponteiros de início e fim da lista;
* Tratamento das operações de remoção em diferentes posições da lista;
* Manipulação e persistência dos dados em arquivos CSV;
* Validação de entradas para evitar inconsistências nos registros;
* Garantia da liberação correta da memória para evitar vazamentos (memory leaks).
---


### Trabalho B – Chamadas de Emergência

Sistema de gerenciamento de chamadas de emergência utilizando uma Pilha Dinâmica (LIFO - Last In, First Out).

Cada chamada possui:

* Protocolo único;
* Local da ocorrência;
* Tipo da ocorrência;
* Horário da chamada.

Funcionalidades implementadas:

* Registrar chamada (empilhar);
* Atender chamada (desempilhar);
* Consultar última chamada registrada;
* Buscar chamada por protocolo;
* Listar todas as chamadas;
* Salvar dados em arquivo CSV;
* Carregar dados de arquivo CSV;
* Liberação de memória utilizando free() ao encerrar o programa.

Estruturas e conceitos utilizados:

* Structs;
* Ponteiros;
* Alocação dinâmica com malloc();
* Liberação de memória com free();
* Manipulação de arquivos CSV;
* Pilha dinâmica encadeada.

---

## Como Compilar

Exemplo utilizando GCC:

```bash
gcc ChamadasDeEmergencia.c -o ChamadasDeEmergencia
```

Ou pelo compilador configurado na IDE utilizada (Code::Blocks, Dev-C++, VS Code, etc.).

---

## Como Executar

Após a compilação:

Windows:

```bash
ChamadasDeEmergencia.exe
```

Linux:

```bash
./ChamadasDeEmergencia
```

---

## Arquivos CSV

Os programas utilizam arquivos CSV para armazenamento permanente dos dados.

Exemplo de arquivo utilizado no Trabalho B:

```csv
protocolo;local;tipo;horario
1001;Salvador;policia;14:30
1002;Itapua;samu;15:10
1003;Paralela;bombeiro;16:45
```

---

## Observações

* Os dados são carregados automaticamente ao iniciar o programa.
* Os dados podem ser salvos manualmente pelo menu.
* Ao encerrar o programa, os dados são salvos automaticamente.
* Toda a memória alocada dinamicamente é liberada antes do encerramento.
* As estruturas de dados foram implementadas manualmente, sem utilização de bibliotecas prontas.

---

## Testes Realizados

* Inserção em estrutura vazia;
* Inserção de múltiplos registros;
* Busca por registro existente;
* Busca por registro inexistente;
* Remoção de registros;
* Consulta do topo da pilha;
* Salvamento em CSV;
* Carregamento de CSV;
* Encerramento com liberação de memória.

---

## Dificuldades Encontradas

* Implementação das estruturas dinâmicas utilizando ponteiros;
* Manipulação de arquivos CSV;
* Controle de memória com malloc() e free();
* Validação das entradas do usuário;
* Integração entre persistência em arquivo e estruturas dinâmicas.
---

### Trabalho C

Programa desenvolvido para atender aos requisitos do Tema C da disciplina, utilizando estruturas de dados dinâmicas implementadas manualmente em linguagem C.
