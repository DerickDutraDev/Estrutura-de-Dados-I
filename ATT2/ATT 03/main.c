#include <stdio.h>
#include <stdlib.h> // Necessário para o system("pause") se preferir
#include "vendas.h"

int main() {
    int id, cod;
    char nome[50];
    float preco;
    char continuar;

    printf("=== CADASTRO DE CLIENTE ===\n");
    printf("ID do Cliente: ");
    if(scanf("%d", &id) != 1) return 1; 

    printf("Nome do Cliente: ");
    scanf(" %[^\n]s", nome);

    Cliente c = criar_cliente(id, nome);
    Venda v = iniciar_venda(c);

    do {
        printf("\n--- Novo Produto ---\n");
        printf("Codigo: ");
        scanf("%d", &cod);
        
        printf("Nome: ");
        scanf(" %[^\n]s", nome);
        
        printf("Preco: ");
        scanf("%f", &preco);

        Produto p = criar_produto(cod, nome, preco);
        adicionar_produto(&v, p);

        printf("\nDeseja adicionar outro? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    exibir_venda(v);

    //PAUSA PARA NÃO FECHAR
    printf("\n----------------------------------\n");
    printf("Processo finalizado. Pressione qualquer tecla para sair.\n");
    system("pause");

    return 0;
}