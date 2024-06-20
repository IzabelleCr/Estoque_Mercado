#include <stdio.h>
#include "produto.h"

void menu() {
    int opcao;
    do {
        printf("\n-------------------------\n");
        printf("         MENU            \n");
        printf("-------------------------\n");
        printf("1 - Carregar dados\n");
        printf("2 - Registrar compra\n");
        printf("3 - Registrar venda\n");
        printf("4 - Consultar produto\n");
        printf("5 - Listar estoque\n");
        printf("9 - Sair\n");
        printf("-------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarDados();
                break;
            case 2:
                registrarCompra();
                break;
            case 3:
                registrarVenda();
                break;
            case 4:
                consultarProduto();
                break;
            case 5:
                listarEstoque();
                break;
            case 9:
                salvarEstoque();
                printf("Encerrando o programa e salvando o estoque...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 9);
}

int main() {
    menu();
    return 0;
}
