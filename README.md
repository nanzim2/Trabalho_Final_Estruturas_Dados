# Trabalho Final - Estruturas de Dados

## Integrantes

* Íris Conceição Candido da Silva 
* Matheus Macedo Araújo
* Renan Pires Andrade
* Tailane de Santana Brito

## Turma

Turma: C

---

# Temas Escolhidos

## Trabalho A

<<<<<<< HEAD
Tema: Playlist de música
=======
Tema A1 — Playlist de Músicas
>>>>>>> 9f27717dcb8179efa5412a81d09a3440f85d842b

## Trabalho B

Tema B2 – Chamadas de Emergência

## Trabalho C

Tema: [Informar Tema Escolhido]

---

<<<<<<< HEAD
# Descrição dos Programas

## Trabalho A

Programa desenvolvido para atender aos requisitos do Tema A utilizando estruturas de dados implementadas em linguagem C.
=======
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

---

### Estruturas e conceitos utilizados

* Structs;
* Ponteiros;
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
---

>>>>>>> 9f27717dcb8179efa5412a81d09a3440f85d842b

## Trabalho B – Chamadas de Emergência

Sistema de gerenciamento de chamadas de emergência utilizando uma Pilha Simples (LIFO – Last In, First Out).

Cada chamada possui:

* Protocolo único;
* Local da ocorrência;
* Tipo da ocorrência;
* Horário da chamada.

Funcionalidades implementadas:

* Registrar chamada;
* Atender chamada;
* Consultar última chamada registrada;
* Listar todas as chamadas;
* Validação de dados informados pelo usuário;
* Controle de pilha cheia;
* Controle de pilha vazia;
* Salvamento dos dados em arquivo CSV;
* Carregamento automático dos dados salvos em CSV.

Estruturas e conceitos utilizados:

* Structs;
* Vetor de registros;
* Pilha simples;
* Ponteiros;
* Manipulação de arquivos CSV;
* Manipulação de strings;
* Validação de entrada de dados.

<<<<<<< HEAD
## Trabalho C

Programa desenvolvido para atender aos requisitos do Tema C utilizando estruturas de dados implementadas em linguagem C.

---

# Estrutura do Repositório

```text
Trabalho_Final_Estruturas_Dados/

README.md

Trabalho_A/
    trabalho_a.c

Trabalho_B/
    ChamadasDeEmergencia.c

Trabalho_C/
    trabalho_c.c

relatorio.md
```

---

# Como Compilar
=======
---

## Como Compilar
>>>>>>> 9f27717dcb8179efa5412a81d09a3440f85d842b

Exemplo utilizando GCC:

```bash
gcc ChamadasDeEmergencia.c -o ChamadasDeEmergencia
```

Ou utilizando a IDE de preferência:

* Code::Blocks
* Dev-C++
* Visual Studio Code
* Visual Studio

---

# Como Executar

Após compilar:

Windows:

```bash
ChamadasDeEmergencia.exe
```

Linux:

```bash
./ChamadasDeEmergencia
```

---

# Funcionamento do Trabalho B

A pilha segue a lógica LIFO (Last In, First Out).

Isso significa que a última chamada registrada será a primeira chamada atendida.

Exemplo:

1. Registrar protocolo 1001
2. Registrar protocolo 1002
3. Registrar protocolo 1003

Ao atender:

1. Protocolo 1003
2. Protocolo 1002
3. Protocolo 1001

---

# Testes Realizados

* Inserção em pilha vazia;
* Inserção de vários registros;
* Consulta da última chamada;
* Atendimento de chamadas;
* Tentativa de atendimento com pilha vazia;
* Validação do horário;
* Validação do tipo da ocorrência;
* Controle de pilha cheia;
* Listagem de todos os registros;
* Salvamento em arquivo CSV;
* Carregamento de dados a partir do CSV.

---

# Observações

* Os registros podem ser armazenados no arquivo chamadas.csv.
* Os dados são carregados automaticamente ao iniciar o programa.
* O topo da pilha é controlado por uma variável inteira.
* O arquivo CSV permite manter os registros entre diferentes execuções do sistema.
* O programa foi desenvolvido em linguagem C.

---

# Dificuldades Encontradas

<<<<<<< HEAD
* Implementação da lógica de pilha.
* Validação das entradas do usuário.
* Manipulação de strings utilizando funções da biblioteca padrão da linguagem C.
* Organização das funções para manter o código legível e modularizado.
=======
* Implementação das estruturas dinâmicas utilizando ponteiros;
* Manipulação de arquivos CSV;
* Validação das entradas do usuário;
* Integração entre persistência em arquivo e estruturas dinâmicas.
---

### Trabalho C

Programa desenvolvido para atender aos requisitos do Tema C da disciplina, utilizando estruturas de dados dinâmicas implementadas manualmente em linguagem C.
>>>>>>> 9f27717dcb8179efa5412a81d09a3440f85d842b
