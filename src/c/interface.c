#include <stdio.h>
#include "bridge.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void menu();
int ler_inteiro();


void menu(){

    int opcao;
    char titulo[64], autor[64], isbn[20];
    int ano, quantidade;
    

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
            printf("Título: ");
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = 0;

            printf("Autor: ");
            fgets(autor, sizeof(autor), stdin);
            autor[strcspn(autor, "\n")] = 0;

            printf("ISBN: ");
            fgets(isbn, sizeof(isbn), stdin);
            isbn[strcspn(isbn, "\n")] = 0;

            ano = ler_inteiro("Ano: ");
            quantidade = ler_inteiro("Quantidade: ");

            cadastro(titulo, autor, isbn, ano, quantidade);
            salvar_em_arquivo();
            break;
        }
        case 2:
            listar_livros();
            break;
        case 3: {
            char titulo[64];
            printf("Digite o título do livro: ");
            scanf(" %[^\n]", titulo);

            buscar_livro(titulo);   
            break;
        }

        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
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
            buffer[strcspn(buffer, "\n")] = 0; // remove \n

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


int main(){
    carregar_arquivo();
    menu();
    return 0;
}

