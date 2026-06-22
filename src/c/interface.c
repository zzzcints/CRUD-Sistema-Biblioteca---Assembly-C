#include <stdio.h>
#include "bridge.h"

void menu();


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

        switch (opcao)
        {
        case 1: {
            

            printf("Título: ");
            scanf("%63s",titulo);
            getchar();

            printf("Autor: ");
            scanf("%63s",autor);
            getchar();

            printf("ISBN: ");
            scanf("%63s",isbn);
            getchar();

            printf("Ano: ");
            scanf("%d", &ano);
            getchar(); 

            printf("Quantidade: ");
            scanf("%d", &quantidade);
            getchar();

            cadastro(titulo, autor, isbn, ano, quantidade);
            
            break;
        }

        case 2:
            listar_livros();
            break;
        case 3:
            /* code */
            break;
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

int main(){
    menu();
    return 0;
}