# Trabalho Final - Estruturas de Dados

## Integrantes

* [Nome Completo 1]
* [Nome Completo 2]
* [Nome Completo 3]

## Turma

Turma: C

---

## Temas Escolhidos

### Trabalho A

Tema: [Informar Tema Escolhido]

### Trabalho B

Tema B2 – Chamadas de Emergência

### Trabalho C

Tema: [Informar Tema Escolhido]

---

## Descrição dos Programas

### Trabalho A

Programa desenvolvido para atender aos requisitos do Tema A da disciplina, utilizando estruturas de dados dinâmicas implementadas manualmente em linguagem C.

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

### Trabalho C

Programa desenvolvido para atender aos requisitos do Tema C da disciplina, utilizando estruturas de dados dinâmicas implementadas manualmente em linguagem C.

---

## Estrutura do Repositório

```text
Trabalho_Final_Estruturas_Dados/

README.md

Trabalho_A/
    trabalho_a.c
    dados_a.csv

Trabalho_B/
    ChamadasDeEmergencia.c
    chamadas.csv

Trabalho_C/
    trabalho_c.c
    dados_c.csv

relatorio.md
```

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