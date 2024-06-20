# Gestão de Estoque de Supermercado

Este repositório contém um projeto de gestão de estoque de supermercado desenvolvido em linguagem C. O objetivo do projeto é fornecer uma ferramenta eficiente para gerenciar o inventário de produtos, facilitando o controle de entradas, saídas e consultas de itens no estoque.

## Funcionalidades

- Adicionar Produtos: Permite a inserção de novos produtos no estoque, incluindo detalhes como nome, código, quantidade e preço.
- Atualizar Produtos: Possibilita a atualização das informações dos produtos já cadastrados.
- Remover Produtos: Permite a remoção de produtos do estoque.
- Consulta de Produtos: Busca e exibe informações detalhadas de produtos específicos.
- Listagem de Estoque: Exibe todos os produtos disponíveis no estoque com suas respectivas informações.
- Relatórios: Gera relatórios de movimentação e estado atual do estoque.

## Estrutura do Projeto
- main.c - Ponto de entrada do programa, responsável pelo menu principal e navegação entre as funcionalidades.
- produto.c - Implementação das funções relacionadas aos produtos, como adicionar, buscar e registrar compras e vendas.
- produto.h - Declaração das funções e estruturas utilizadas para os produtos.
- estoque.txt - Arquivo gerado para salvar o estado atual do estoque.

## Como Executar

### Clone o repositório:
- git clone https://github.com/IzabelleCr/Estoque_Mercado

### Navegue até o diretório do projeto:
- cd Estoque_Mercado

### Compile o projeto:
- gcc -o estoque main.c produto.c

### Execute o programa:

- ./estoque




