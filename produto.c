#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto *listaProdutos = NULL;

Compra* adicionarCompraFila(Compra *fila, const char *data, int quantidade, int inicial) {
    Compra *novaCompra = (Compra *)malloc(sizeof(Compra));
    strcpy(novaCompra->data, data);
    novaCompra->quantidade = quantidade;
    novaCompra->inicial = inicial;
    novaCompra->prox = NULL;

    if (fila == NULL) {
        return novaCompra;
    } else {
        Compra *temp = fila;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novaCompra;
        return fila;
    }
}

Produto* adicionarCompra(Produto *lista, int codigo, const char *descricao, float preco, int quantidade, const char *dataCompra, int inicial) {
    Produto *produto = buscarProduto(lista, codigo);
    if (produto == NULL) {
        Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
        novoProduto->codigo = codigo;
        strcpy(novoProduto->descricao, descricao);
        novoProduto->preco = preco;
        novoProduto->quantidadeTotal = quantidade;
        novoProduto->compras = adicionarCompraFila(NULL, dataCompra, quantidade, inicial);
        novoProduto->prox = NULL;

        if (lista == NULL) {
            return novoProduto;
        } else {
            Produto *temp = lista;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novoProduto;
            return lista;
        }
    } else {
        produto->quantidadeTotal += quantidade;
        produto->compras = adicionarCompraFila(produto->compras, dataCompra, quantidade, inicial);
        return lista;
    }
}

Produto* buscarProduto(Produto *lista, int codigo) {
    Produto *produto = lista;
    while (produto != NULL && produto->codigo != codigo) {
        produto = produto->prox;
    }
    return produto;
}

void carregarDados() {
    int codigo;
    char descricao[MAX_DESC];
    float preco;
    int quantidade;
    char dataCompra[11];

    printf("\n-------------------------\n");
    printf("  Carregar dados dos produtos\n");
    printf("-------------------------\n");
    printf("Digite o codigo do produto (0 para finalizar): ");
    scanf("%d", &codigo);

    while (codigo != 0) {
        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]", descricao);
        printf("Digite o preco do produto: ");
        scanf("%f", &preco);
        printf("Digite a quantidade total disponivel: ");
        scanf("%d", &quantidade);
        printf("Digite a data da compra (dd/mm/yyyy): ");
        scanf("%s", dataCompra);

        listaProdutos = adicionarCompra(listaProdutos, codigo, descricao, preco, quantidade, dataCompra, 1);

        printf("Digite o codigo do proximo produto (0 para finalizar): ");
        scanf("%d", &codigo);
    }
    printf("Dados carregados com sucesso!\n");
}

void registrarCompra() {
    int codigo, quantidade;
    char dataCompra[11];

    printf("\n-------------------------\n");
    printf("  Registrar compra\n");
    printf("-------------------------\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    Produto *produto = buscarProduto(listaProdutos, codigo);

    if (produto != NULL) {
        printf("Digite a data da compra (dd/mm/yyyy): ");
        scanf("%s", dataCompra);
        printf("Digite a quantidade comprada: ");
        scanf("%d", &quantidade);

        produto->compras = adicionarCompraFila(produto->compras, dataCompra, quantidade, 0);
        produto->quantidadeTotal += quantidade;
        printf("Compra registrada com sucesso!\n");
    } else {
        char descricao[MAX_DESC];
        float preco;

        printf("Produto nao encontrado! Insira os dados para cadastrar um novo produto.\n");
        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]", descricao);
        printf("Digite o preco do produto: ");
        scanf("%f", &preco);
        printf("Digite a data da compra (dd/mm/yyyy): ");
        scanf("%s", dataCompra);
        printf("Digite a quantidade comprada: ");
        scanf("%d", &quantidade);

        listaProdutos = adicionarCompra(listaProdutos, codigo, descricao, preco, quantidade, dataCompra, 0);
        printf("Produto e compra registrados com sucesso!\n");
    }
}

void registrarVenda() {
    int codigo, quantidade;
    printf("\n-------------------------\n");
    printf("  Registrar venda\n");
    printf("-------------------------\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Digite a quantidade vendida: ");
    scanf("%d", &quantidade);

    Produto *produto = buscarProduto(listaProdutos, codigo);
    if (produto != NULL) {
        if (quantidade > produto->quantidadeTotal) {
            printf("Quantidade vendida maior que a quantidade disponivel!\n");
        } else {
            int quantidadeRestante = quantidade;
            Compra *compra = produto->compras;
            Compra *anterior = NULL;

            while (compra != NULL && quantidadeRestante > 0) {
                if (quantidadeRestante >= compra->quantidade) {
                    quantidadeRestante -= compra->quantidade;
                    if (anterior == NULL) {
                        produto->compras = compra->prox;
                    } else {
                        anterior->prox = compra->prox;
                    }
                    Compra *temp = compra;
                    compra = compra->prox;
                    free(temp);
                } else {
                    compra->quantidade -= quantidadeRestante;
                    quantidadeRestante = 0;
                }
            }

            produto->quantidadeTotal -= quantidade;
            printf("Venda registrada com sucesso!\n");
        }
    } else {
        printf("Produto nao encontrado!\n");
    }
}

void consultarProduto() {
    int codigo;
    printf("\n-------------------------\n");
    printf("  Consultar produto\n");
    printf("-------------------------\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    Produto *produto = buscarProduto(listaProdutos, codigo);
    if (produto != NULL) {
        printf("Codigo: %d\n", produto->codigo);
        printf("Descricao: %s\n", produto->descricao);
        printf("Preco: %.2f\n", produto->preco);
        printf("Quantidade total disponivel: %d\n", produto->quantidadeTotal);

        Compra *compra = produto->compras;
        while (compra != NULL) {
            if (compra->inicial) {
                printf("Produto em estoque: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            } else {
                printf("Data da compra: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            }
            compra = compra->prox;
        }
    } else {
        printf("Produto nao encontrado!\n");
    }
}

void listarEstoque() {
    printf("\n-------------------------\n");
    printf("  Listar estoque\n");
    printf("-------------------------\n");

    Produto *produto = listaProdutos;
    while (produto != NULL) {
        printf("Codigo: %d, Descricao: %s, Quantidade total disponivel: %d\n", produto->codigo, produto->descricao, produto->quantidadeTotal);

        Compra *compra = produto->compras;
        while (compra != NULL) {
            if (compra->inicial) {
                printf("Produto em estoque: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            } else {
                printf("Data da compra: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            }
            compra = compra->prox;
        }

        produto = produto->prox;
    }
}

void salvarEstoque() {
    FILE *arquivo = fopen("estoque.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o estoque.\n");
        return;
    }

    Produto *produto = listaProdutos;
    while (produto != NULL) {
        fprintf(arquivo, "Codigo: %d, Descricao: %s, Quantidade total disponivel: %d\n", produto->codigo, produto->descricao, produto->quantidadeTotal);

        Compra *compra = produto->compras;
        while (compra != NULL) {
            if (compra->inicial) {
                fprintf(arquivo, "Produto em estoque: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            } else {
                fprintf(arquivo, "Data da compra: %s, Quantidade: %d\n", compra->data, compra->quantidade);
            }
            compra = compra->prox;
        }
        fprintf(arquivo, "---------------------------------\n"); // Indicador do fim das compras para um produto

        produto = produto->prox;
    }

    fclose(arquivo);
    printf("Estoque salvo com sucesso!\n");
}
