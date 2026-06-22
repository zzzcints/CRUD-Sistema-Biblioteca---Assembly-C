#include <bridge.h>

extern void inserir(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade);
void cadastro(const char *titulo, const char *autor, const char *isbn, int ano, int quantidade) {
    inserir(titulo, autor, isbn, ano, quantidade);
}

