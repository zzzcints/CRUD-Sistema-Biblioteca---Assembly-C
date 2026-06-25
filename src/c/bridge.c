#include <stdio.h>
#include "bridge.h"

void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade) {
    inserir(titulo, autor, isbn, ano, quantidade);
}

void salvar_em_arquivo() {
    FILE *f = fopen("livros.txt", "w");
    if (f) {
        for (int i = 0; i < book_count; i++) {
            printf("book_count = %d\n", book_count);

            fprintf(f,
                "------------------------------------------------------------\n"
                "| Título: %s\n"
                "| Autor: %s\n"
                "| ISBN: %s\n"
                "| Ano: %d\n"
                "| Quantidade: %d\n"
                "------------------------------------------------------------\n",
                books[i].titulo, books[i].autor, books[i].isbn,
                books[i].ano, books[i].quantidade);
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



