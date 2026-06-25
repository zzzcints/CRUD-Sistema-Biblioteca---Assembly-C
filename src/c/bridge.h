#ifndef BRIDGE_H
#define BRIDGE_H

typedef struct {
    char titulo[64];
    char autor[64];
    char isbn[20];
    int ano;
    int quantidade;
} Livro;

extern Livro books[100];   
extern int book_count;

extern void inserir(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade);

// C
void carregar_arquivo();
void cadastro();
void salvar_em_arquivo();
void listar_livros();
void buscar(const char *titulo);
void remover(const char *titulo);
void salvar_todos();

#endif
