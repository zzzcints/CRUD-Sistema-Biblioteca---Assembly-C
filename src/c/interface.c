#include <stdio.h>

void menu();


void menu(){

    int opcao = 1;
    char nome[100];

    

    do{
        printf("------------------------------------------------------------------------------------");
        printf("\n                            Bem Vindo!                                            \n");
        printf("\n                              1- Cadastar Livro");
        printf("\n                              2- Listar Livros");
        printf("\n                              3- Buscar Livro");
        printf("\n                              4- Editar Livro");
        printf("\n                              5- Remover Livro");
        printf("\n                              0- Sair");


        switch (opcao)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
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