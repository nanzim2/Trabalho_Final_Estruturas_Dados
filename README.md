# Trabalho Final - Estruturas de Dados

## Integrantes

* Íris Conceição Candido da Silva 
* Matheus macedo araújo
* Renan Pires Andrade
* Tailane de Santana Brito

## Turma

Turma: C

---

# Temas Escolhidos

## Trabalho A

Tema: Playlist de música

## Trabalho B

Tema B2 – Chamadas de Emergência

## Trabalho C

Tema: [Informar Tema Escolhido]

---

# Descrição dos Programas

## Trabalho A

Programa desenvolvido para atender aos requisitos do Tema A utilizando estruturas de dados implementadas em linguagem C.

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
* Controle de pilha vazia.

Estruturas e conceitos utilizados:

* Structs;
* Vetor de registros;
* Pilha simples;
* Ponteiros;
* Funções;
* Manipulação de strings;
* Validação de entrada de dados.

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
* Listagem de todos os registros.

---

# Observações

* O protocolo é gerado automaticamente.
* O programa utiliza um vetor de estruturas para armazenar as chamadas.
* O topo da pilha é controlado por uma variável inteira.
* O sistema segue a lógica LIFO (Last In, First Out).
* O programa foi desenvolvido em linguagem C.

---

# Dificuldades Encontradas

* Implementação da lógica de pilha.
* Validação das entradas do usuário.
* Manipulação de strings utilizando funções da biblioteca padrão da linguagem C.
* Organização das funções para manter o código legível e modularizado.
