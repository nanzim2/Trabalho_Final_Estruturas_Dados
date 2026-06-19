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

Tema A1 – Playlist de Músicas

## Trabalho B

Tema B2 – Chamadas de Emergência

## Trabalho C

Tema: A definir

---

# Estrutura do Repositório

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

relatorio.md
```

---

# Descrição dos Programas

## Trabalho A – Playlist de Músicas

Sistema de gerenciamento de uma playlist de músicas.

Cada música possui:

* ID único;
* Título;
* Artista;
* Duração;
* Gênero musical.

### Funcionalidades implementadas

* Cadastrar música;
* Buscar música por ID;
* Editar informações da música;
* Excluir música;
* Listar músicas cadastradas;
* Salvar dados em arquivo CSV;
* Carregar dados de arquivo CSV;
* Validação de ID único.

### Estruturas e conceitos utilizados

* Structs;
* Ponteiros;
* Manipulação de arquivos CSV;
* Lista de registros;
* Busca sequencial;
* Validação de entradas.

---

## Trabalho B – Chamadas de Emergência

Sistema de gerenciamento de chamadas de emergência utilizando uma Pilha Simples (LIFO – Last In, First Out).

Cada chamada possui:

* Protocolo único;
* Local da ocorrência;
* Tipo da ocorrência;
* Horário da chamada.

### Funcionalidades implementadas

* Registrar chamada;
* Atender chamada;
* Consultar última chamada registrada;
* Listar todas as chamadas;
* Validação de dados informados pelo usuário;
* Controle de pilha cheia;
* Controle de pilha vazia;
* Salvamento dos dados em arquivo CSV;
* Carregamento automático dos dados salvos em CSV.

### Estruturas e conceitos utilizados

* Structs;
* Vetor de registros;
* Pilha simples;
* Ponteiros;
* Manipulação de arquivos CSV;
* Manipulação de strings;
* Validação de entrada de dados.

---

## Trabalho C

Tema ainda não definido.

---

# Como Compilar

## Trabalho A

```bash
gcc playlist_musicas.c -o playlist
```

## Trabalho B

```bash
gcc ChamadasDeEmergencia.c -o ChamadasDeEmergencia
```

---

# Como Executar

## Trabalho A

Windows:

```bash
playlist.exe
```

Linux:

```bash
./playlist
```

## Trabalho B

Windows:

```bash
ChamadasDeEmergencia.exe
```

Linux:

```bash
./ChamadasDeEmergencia
```

---

# Arquivos CSV

Os programas utilizam arquivos CSV para armazenamento permanente dos dados.

### Trabalho A

```text
playlist.csv
```

### Trabalho B

```text
chamadas.csv
```

---

# Testes Realizados

## Trabalho A

* Cadastro de músicas;
* Busca por ID existente;
* Busca por ID inexistente;
* Edição de registros;
* Exclusão de registros;
* Salvamento em CSV;
* Carregamento de CSV.

## Trabalho B

* Inserção em pilha vazia;
* Inserção de vários registros;
* Consulta da última chamada;
* Atendimento de chamadas;
* Tentativa de atendimento com pilha vazia;
* Validação do horário;
* Validação do tipo da ocorrência;
* Controle de pilha cheia;
* Listagem dos registros;
* Salvamento em arquivo CSV;
* Carregamento de dados a partir do CSV.

---

# Observações

* Os dados são carregados automaticamente ao iniciar os programas.
* Os registros podem ser salvos em arquivos CSV.
* Os dados permanecem disponíveis entre diferentes execuções.
* Os programas foram desenvolvidos em linguagem C.
* As estruturas de dados foram implementadas manualmente conforme os requisitos da disciplina.

---

# Dificuldades Encontradas

* Implementação das estruturas de dados;
* Manipulação de arquivos CSV;
* Validação das entradas do usuário;
* Manipulação de strings;
* Organização e modularização do código;
* Integração entre memória e persistência em arquivos.
