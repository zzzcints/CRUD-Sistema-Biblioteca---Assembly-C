#include <stdio.h>
#include "bridge.h"

void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade) {
    inserir(titulo, autor, isbn, ano, quantidade);
}

void salvar_em_arquivo() {
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


void listar_livros() {
    FILE *f = fopen("livros.txt", "r");
    if (!f) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }
    fclose(f);
}

void buscar_livro(const char *titulo) {
    int idx = buscar(titulo);
    if (idx >= 0) {
        printf("Livro encontrado:\n");
        printf("Título: %s\nAutor: %s\nISBN: %s\nAno: %d\nQuantidade: %d\n",
               books[idx].titulo, books[idx].autor, books[idx].isbn,
               books[idx].ano, books[idx].quantidade);
    } else {
        printf("Livro não encontrado.\n");
    }
}

void carregar_arquivo() {
    FILE *f = fopen("livros.txt", "r");
    if (!f) return; 

    book_count = 0;
    while (book_count < 100 &&
           fscanf(f, "%63[^\n]\n%63[^\n]\n%19[^\n]\n%d\n%d\n",
                  books[book_count].titulo,
                  books[book_count].autor,
                  books[book_count].isbn,
                  &books[book_count].ano,
                  &books[book_count].quantidade) == 5) {
        book_count++;
    }
    fclose(f);
}



