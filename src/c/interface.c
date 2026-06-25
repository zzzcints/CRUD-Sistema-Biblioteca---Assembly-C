#include <stdio.h>
#include "bridge.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include <ctype.h>

void menu();
int ler_inteiro();
void editar(const char *titulo);
void salvar_todos(void);
int validar_isbn(const char *isbn);
void ler_isbn(char *isbn, int tamanho);
void ler_autor(char *autor, int tamanho);
int validar_autor(const char *autor);



int main(){
    carregar_arquivo();
    menu();
    return 0;
}



void menu(){

    int opcao;
    

    do{
        printf("------------------------------------------------------------------------------------");
        printf("\n                            Bem Vindo!                                            \n");
        printf("\n                              1- Cadastar Livro");
        printf("\n                              2- Listar Livros");
        printf("\n                              3- Buscar Livro");
        printf("\n                              4- Editar Livro");
        printf("\n                              5- Remover Livro");
        printf("\n                              0- Sair");
        printf("\n\n                              Escolha: ");
        scanf("%d",&opcao);
        getchar();


        switch (opcao)
        {
    case 1: {
            book novo;
            printf("Título: ");
            fgets(novo.titulo, sizeof(novo.titulo), stdin);
            novo.titulo[strcspn(novo.titulo, "\n")] = 0;

            ler_autor(novo.autor, sizeof(novo.autor));
            ler_isbn(novo.isbn, sizeof(novo.isbn));

            novo.ano = ler_inteiro("Ano: ");
            novo.quantidade = ler_inteiro("Quantidade: ");

            cadastro(novo.titulo, novo.autor, novo.isbn, novo.ano, novo.quantidade);

            salvar_em_arquivo(novo);  
            printf("Cadastro concluído!\n");
            break;
        }
    case 2:
            listar_livros();
            break;
    case 3: {
        char titulo[64];
        printf("Digite o título do livro: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = 0; 
        buscar(titulo);                   
        break;
    }


    case 4: {
        char titulo[64];
        printf("Digite o título do livro a editar: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = 0;
        editar(titulo);
        break;
    }

    case 5: {
        char titulo[64];
        printf("Digite o título do livro a remover: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = 0;
        remover(titulo);
        break;
    }
    default:
            break;
    }


    }while (opcao != 0);

}

int ler_inteiro(const char *mensagem) {
    char buffer[32];
    int valido = 0;
    int valor = 0;

    while (!valido) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = 0; 

            valido = 1;
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (!isdigit((unsigned char)buffer[i])) {
                    valido = 0;
                    break;
                }
            }

            if (valido) {
                valor = atoi(buffer);
            } else {
                printf("Entrada inválida! Digite apenas números.\n");
            }
        }
    }
    return valor;
}

void editar(const char *titulo) {
    int encontrado = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].titulo, titulo) == 0) {
            printf("\nLivro encontrado. Informe os novos dados:\n");

            printf("Novo título: ");
            fgets(books[i].titulo, sizeof(books[i].titulo), stdin);
            books[i].titulo[strcspn(books[i].titulo, "\n")] = 0;

            printf("Novo autor: ");
            fgets(books[i].autor, sizeof(books[i].autor), stdin);
            books[i].autor[strcspn(books[i].autor, "\n")] = 0;

            printf("Novo ISBN: ");
            fgets(books[i].isbn, sizeof(books[i].isbn), stdin);
            books[i].isbn[strcspn(books[i].isbn, "\n")] = 0;

            books[i].ano = ler_inteiro("Novo ano: ");
            books[i].quantidade = ler_inteiro("Nova quantidade: ");

            printf("Livro atualizado com sucesso!\n");

            salvar_todos();
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nLivro não encontrado!\n");
    }
}

int validar_isbn(const char *isbn) {
    int digitos = 0;
    for (int i = 0; isbn[i] != '\0'; i++) {
        if (isdigit(isbn[i])) {
            digitos++;
        } else if (isbn[i] != '-') {
            return 0; 
        }
    }
    return (digitos == 10 || digitos == 13);
}

void ler_isbn(char *isbn, int tamanho) {
    do {
        printf("Digite o ISBN: ");
        fgets(isbn, tamanho, stdin);
        isbn[strcspn(isbn, "\n")] = 0;

        if (!validar_isbn(isbn)) {
            printf("ISBN inválido! Tente novamente.\n");
        } else {
            break; 
        }
    } while (1);
}

int validar_autor(const char *autor) {
    for (int i = 0; autor[i] != '\0'; i++) {
        if (!(isalpha((unsigned char)autor[i]) || isspace((unsigned char)autor[i]))) {
            return 0; 
        }
    }
    return 1; 
}

void ler_autor(char *autor, int tamanho) {
    do {
        printf("Digite o nome do autor:");
        fgets(autor, tamanho, stdin);
        autor[strcspn(autor, "\n")] = 0;

        if (!validar_autor(autor)) {
            printf("Autor inválido! Tente novamente.\n");
        } else {
            break; 
        }
    } while (1);
}



