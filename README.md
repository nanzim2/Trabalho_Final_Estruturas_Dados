# Trabalho Final - Estruturas de Dados

## Integrantes

- Íris Conceição Candido da Silva
- Matheus Macedo Araújo
- Renan Pires Andrade
- Tailane de Santana Brito

## Turma

Turma: C

---

# Temas Escolhidos

## Trabalho A

Tema A1 – Playlist de Músicas

## Trabalho B

Tema B2 – Chamadas de Emergência

## Trabalho C

Tema C1 – Atendimento Bancário

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
    atendimento_bancario.c
    atendimento.csv

relatorio.md
```

---

# Descrição dos Programas

## Trabalho A – Playlist de Músicas

Sistema de gerenciamento de uma playlist de músicas.

Cada música possui:

- ID único;
- Título;
- Artista;
- Duração;
- Gênero musical.

### Funcionalidades implementadas

- Cadastrar música;
- Buscar música por ID;
- Editar informações da música;
- Excluir música;
- Listar músicas cadastradas;
- Salvar dados em arquivo CSV;
- Carregar dados de arquivo CSV;
- Validação de ID único.

### Estruturas e conceitos utilizados

- Structs;
- Ponteiros;
- Manipulação de arquivos CSV;
- Lista de registros;
- Busca sequencial;
- Validação de entradas.

---

## Trabalho B – Chamadas de Emergência

Sistema de gerenciamento de chamadas de emergência utilizando uma Pilha Simples (LIFO – Last In, First Out).

Cada chamada possui:

- Protocolo único;
- Local da ocorrência;
- Tipo da ocorrência;
- Horário da chamada.

### Funcionalidades implementadas

- Registrar chamada;
- Atender chamada;
- Consultar última chamada registrada;
- Listar todas as chamadas;
- Validação de dados informados pelo usuário;
- Controle de pilha cheia;
- Controle de pilha vazia;
- Salvamento dos dados em arquivo CSV;
- Carregamento automático dos dados salvos em CSV.

### Estruturas e conceitos utilizados

- Structs;
- Vetor de registros;
- Pilha simples;
- Ponteiros;
- Manipulação de arquivos CSV;
- Manipulação de strings;
- Validação de entrada de dados.

---

## Trabalho C – Atendimento Bancário

Sistema de gerenciamento de atendimento bancário utilizando fila simples e fila circular.

Cada senha possui:

- Senha única;
- Tipo da senha (normal ou preferencial);
- Horário de chegada.

### Funcionalidades implementadas

- Gerar senha;
- Inserir senha normal na fila simples;
- Inserir senha preferencial na fila circular;
- Chamar próximo cliente;
- Consultar próxima senha sem remover;
- Listar senhas cadastradas nas duas filas;
- Buscar senha;
- Cancelar senha;
- Configurar proporção de prioridade;
- Salvar dados em arquivo CSV;
- Carregar dados do arquivo CSV;
- Exibir estatísticas de atendimento;
- Exibir relatório simples de atendimentos;
- Validação de dados informados pelo usuário;
- Liberação correta da memória.

### Estruturas e conceitos utilizados

- Structs;
- Ponteiros;
- Nós encadeados;
- Alocação dinâmica com malloc;
- Liberação de memória com free;
- Fila simples;
- Fila circular;
- Manipulação de arquivos CSV;
- Busca sequencial;
- Validação de entrada;
- Menu interativo;
- Interface textual (TUI) com cores e mensagens amigáveis.

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

## Trabalho C

```bash
gcc atendimento_bancario.c -o atendimento_bancario
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

## Trabalho C

Windows:

```bash
atendimento_bancario.exe
```

Linux:

```bash
./atendimento_bancario
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

### Trabalho C

```text
atendimento.csv
```

---

# Testes Realizados

## Trabalho A

- Cadastro de músicas;
- Busca por ID existente;
- Busca por ID inexistente;
- Edição de registros;
- Exclusão de registros;
- Salvamento em CSV;
- Carregamento de CSV.

## Trabalho B

- Inserção em pilha vazia;
- Inserção de vários registros;
- Consulta da última chamada;
- Atendimento de chamadas;
- Tentativa de atendimento com pilha vazia;
- Validação do horário;
- Validação do tipo da ocorrência;
- Controle de pilha cheia;
- Listagem dos registros;
- Salvamento em arquivo CSV;
- Carregamento de dados a partir do CSV.

## Trabalho C

- Inserção de senhas normais;
- Inserção de senhas preferenciais;
- Atendimento respeitando prioridades;
- Consulta da próxima senha;
- Busca de senhas cadastradas;
- Cancelamento de senhas;
- Salvamento em CSV;
- Carregamento de CSV;
- Exibição de estatísticas;
- Exibição de relatórios de atendimento.

---

# Observações

- Os dados são carregados automaticamente ao iniciar os programas.
- Os registros podem ser salvos em arquivos CSV.
- Os dados permanecem disponíveis entre diferentes execuções.
- Os programas foram desenvolvidos em linguagem C.
- As estruturas de dados foram implementadas manualmente conforme os requisitos da disciplina.
- Os trabalhos utilizam os conceitos estudados em listas, pilhas e filas.

---

# Dificuldades Encontradas

- Implementação das estruturas de dados;
- Manipulação de arquivos CSV;
- Validação das entradas do usuário;
- Manipulação de strings;
- Organização e modularização do código;
- Integração entre memória e persistência em arquivos;
- Controle da lógica de prioridade entre filas normais e preferenciais.