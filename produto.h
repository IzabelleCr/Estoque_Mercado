#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_DESC 50

typedef struct Compra {
    char data[11]; // formato dd/mm/yyyy
    int quantidade;
    int inicial; 
    struct Compra *prox;
} Compra;

typedef struct Produto {
    int codigo;
    char descricao[MAX_DESC];
    float preco;
    int quantidadeTotal;
    Compra *compras;
    struct Produto *prox;
} Produto;

extern Produto *listaProdutos;

Produto* adicionarCompra(Produto *lista, int codigo, const char *descricao, float preco, int quantidade, const char *dataCompra, int inicial);
Compra* adicionarCompraFila(Compra *fila, const char *data, int quantidade, int inicial);
Produto* buscarProduto(Produto *lista, int codigo);
void carregarDados();
void registrarCompra();
void registrarVenda();
void consultarProduto();
void listarEstoque();
void salvarEstoque();

#endif
