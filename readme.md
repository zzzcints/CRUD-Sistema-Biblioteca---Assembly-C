# Sistema de Gerenciamento de Biblioteca (CRUD em C e Assembly)

## Descrição

Este projeto consiste em um sistema simples de gerenciamento de biblioteca desenvolvido utilizando as linguagens C e Assembly x86 (NASM). O sistema implementa as operações básicas de CRUD (Create, Read, Update e Delete) para cadastro e gerenciamento de livros.

A interface do usuário foi desenvolvida em C, enquanto parte da manipulação dos dados em memória foi implementada em Assembly, demonstrando a integração entre linguagens de alto e baixo nível.

Os dados dos livros são armazenados em memória durante a execução do programa e persistidos em um arquivo texto chamado `livros.txt`.

---

## Funcionalidades

* Cadastro de livros
* Listagem de livros cadastrados
* Busca de livros pelo título
* Edição de informações de um livro
* Remoção de livros
* Persistência dos dados em arquivo
* Validação de ISBN
* Validação do nome do autor
* Carregamento automático dos dados ao iniciar o programa

---

## Estrutura do Livro

Cada livro possui os seguintes atributos:

| Campo      | Tipo    |
| ---------- | ------- |
| Título     | String  |
| Autor      | String  |
| ISBN       | String  |
| Ano        | Inteiro |
| Quantidade | Inteiro |

---

## Estrutura do Projeto

```text
.
├── build/      # Arquivos de compilação
├── src/
│   ├── asm/    # Código Assembly (CRUD)
│   └── c/      # Interface e integração em C
├── makefile    # Compilação do projeto
```
---

## Tecnologias Utilizadas

* Linguagem C
* Assembly x86 (NASM)
* GCC
* Sistema de arquivos em texto

---

## Funcionamento

Ao iniciar o programa, os livros previamente cadastrados são carregados do arquivo `livros.txt`.

O usuário pode selecionar uma das opções do menu:

1. Cadastrar Livro
2. Listar Livros
3. Buscar Livro
4. Editar Livro
5. Remover Livro
6. Sair

As alterações realizadas são automaticamente refletidas no arquivo de armazenamento.

---

## Integração C e Assembly

A rotina de inserção dos livros é implementada em Assembly através da função:

```c
inserir(const char *titulo,
         const char *autor,
         const char *isbn,
         int ano,
         int quantidade);
```

Essa função é responsável por armazenar os dados na estrutura de memória compartilhada entre C e Assembly.

---


## Arquitetura

O sistema foi dividido em três camadas principais:

- Interface (C): interação com o usuário e validação de dados.
- Bridge (C): comunicação entre a interface e as rotinas Assembly.
- Núcleo (Assembly): gerenciamento da estrutura de livros em memória.


---


## Autores

Cíntia Gonçalves Dias
Projeto desenvolvido para a disciplina de Organização de Computadores e Linguagens de Montagem (UFC - Campus Quixadá).

Desenvolvido utilizando C e Assembly x86 (NASM).
