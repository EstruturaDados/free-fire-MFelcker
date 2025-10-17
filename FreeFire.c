#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct que representa um item da mochila
struct Item {
    char nome[50];
    char tipo[20];
    int quantidade;
};

// Vetor para armazenar os itens da mochila
struct Item mochila[10];
int totalItens = 0;

// Listar itens da mochila
void listarItens(void) {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }
    printf(" || Itens da mochila || \n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Inserir um novo item na mochila
void inserirItem(void) {
    if (totalItens >= 10) {
        printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
        return;
    }

    struct Item novo;
    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("Item adicionado com sucesso!\n");
}

// Buscar item por nome
int buscarItem(char* nome) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return i;
        }
    }
    return -1;
}

// Remover um item
void removerItem(void) {
    if (totalItens == 0) {
        printf("A mochila está vazia. Não há itens para remover.\n");
        return;
    }

    char nomeRemover[50];
    printf("Digite o nome do item a ser removido: ");
    scanf("%s", nomeRemover);

    int indice = buscarItem(nomeRemover);
    if (indice == -1) {
        printf("Item não encontrado na mochila.\n");
        return;
    }

    for (int i = indice; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;
    printf("Item removido com sucesso!\n");
}

int main() {
    int opcao;
    do {
        printf("\n=== Menu da Mochila ===\n");
        printf("1. Listar Itens\n");
        printf("2. Inserir Item\n");
        printf("3. Remover Item\n");
        printf("4. Buscar Item por nome\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarItens();
                break;
            case 2:
                inserirItem();
                break;
            case 3:
                removerItem();
                break;
            case 4: {
                char nomeBusca[50];
                printf("Digite o nome do item a buscar: ");
                scanf("%s", nomeBusca);
                int indice = buscarItem(nomeBusca);
                if (indice == -1) {
                    printf("Item não encontrado.\n");
                }
                break;
            }
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}