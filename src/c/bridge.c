#include "bridge.h"
#include <stdio.h>

extern void inserir(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade);

extern void listar();

void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade) {
    FILE *f = fopen("livros.txt", "a");
    if (f) {
        fprintf(f,
            "------------------------------------------------------------\n"
            "| Título: %s\n"
            "| Autor: %s\n"
            "| ISBN: %s\n"
            "| Ano: %d\n"
            "| Quantidade: %d\n"
            "------------------------------------------------------------\n",
            titulo, autor, isbn, ano, quantidade);
        fclose(f);
    }
}


void listar_livros(){
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

}