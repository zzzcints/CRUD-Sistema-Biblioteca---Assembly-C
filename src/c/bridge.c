#include <stdio.h>
#include "bridge.h"
#include "book.h"
#include <string.h>

void salvar_todos(void);


void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade) {
    inserir(titulo, autor, isbn, ano, quantidade);
}

void salvar_em_arquivo(book novo) {
    FILE *f;

    f = fopen("livros.txt", "r");
    if (f == NULL) {
        f = fopen("livros.txt", "w");
    } else {
        fclose(f);
        f = fopen("livros.txt", "a");
    }

    if (f) {
        fprintf(f, "%s\n%s\n%s\n%d\n%d\n",
                novo.titulo,
                novo.autor,
                novo.isbn,
                novo.ano,
                novo.quantidade);
        fclose(f);
    }
}

void listar_livros() {
    FILE *f = fopen("livros.txt", "r");
    if (!f) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    char linha[256];
    int contador = 0;

    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
        contador++;
        if (contador % 5 == 0) {
            printf("\n");
        }
    }

    fclose(f);
}

void buscar(const char *titulo) {
    int encontrado = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].titulo, titulo) == 0) {
            printf("\nLivro encontrado:\n");
            printf("Título: %s\n", books[i].titulo);
            printf("Autor: %s\n", books[i].autor);
            printf("ISBN: %s\n", books[i].isbn);
            printf("Ano: %d\n", books[i].ano);
            printf("Quantidade: %d\n", books[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nLivro não encontrado!\n");
    }
}

void carregar_arquivo() {
    FILE *f = fopen("livros.txt", "r");
    if (f == NULL) {
      
        book_count = 0;
        return;
    }

    book_count = 0;
    while (fscanf(f, "%63[^\n]\n%63[^\n]\n%19[^\n]\n%d\n%d\n",
                  books[book_count].titulo,
                  books[book_count].autor,
                  books[book_count].isbn,
                  &books[book_count].ano,
                  &books[book_count].quantidade) == 5) {
        book_count++;
    }

    fclose(f);
}

void remover(const char *titulo) {
    int encontrado = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].titulo, titulo) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1]; // desloca os livros
            }
            book_count--;
            printf("Livro removido com sucesso!\n");

            salvar_todos();
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nLivro não encontrado!\n");
    }
}

void salvar_todos() {
    FILE *f = fopen("livros.txt", "w"); 
    if (f) {
        for (int i = 0; i < book_count; i++) {
            fprintf(f, "%s\n%s\n%s\n%d\n%d\n",
                    books[i].titulo,
                    books[i].autor,
                    books[i].isbn,
                    books[i].ano,
                    books[i].quantidade);
        }
        fclose(f);
    }
}


