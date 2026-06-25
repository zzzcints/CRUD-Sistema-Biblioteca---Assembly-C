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

void inserir(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade);
void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade);
void salvar_em_arquivo();
void listar_livros();
void buscar_livro(const char *titulo);
int buscar(const char *titulo);


#endif
