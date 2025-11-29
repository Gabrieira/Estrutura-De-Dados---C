#include <stdio.h>
#include <string.h>

#define MAX_ITENS 100
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int quantidade;
} Item;

int procurarItem(Item lista[], int tamanho, const char *nome) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            return i; 
        }
    }
    return -1; 
}

void adicionarItem(Item lista[], int *tamanho) {
    if (*tamanho >= MAX_ITENS) {
        printf("Lista cheia!\n");
        return;
    }

    char nome[TAM_NOME];
    int quantidade;

    printf("Nome do item: ");
    scanf("%s", nome);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    int idx = procurarItem(lista, *tamanho, nome);
    if (idx >= 0) {
        lista[idx].quantidade += quantidade;
    } else {
        strcpy(lista[*tamanho].nome, nome);
        lista[*tamanho].quantidade = quantidade;
        (*tamanho)++;
    }

    printf("Item adicionado/atualizado com sucesso!\n");
}

void removerItem(Item lista[], int *tamanho) {
    if (*tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    char nome[TAM_NOME];
    int quantidade;

    printf("Nome do item a remover: ");
    scanf("%s", nome);

    printf("Quantidade a remover: ");
    scanf("%d", &quantidade);

    int idx = procurarItem(lista, *tamanho, nome);
    if (idx < 0) {
        printf("Item nao encontrado.\n");
        return;
    }

    lista[idx].quantidade -= quantidade;
    if (lista[idx].quantidade <= 0) {
        for (int i = idx; i < *tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*tamanho)--;
        printf("Item removido da lista.\n");
    } else {
        printf("Quantidade atualizada. Novo total de %s: %d\n",
               lista[idx].nome, lista[idx].quantidade);
    }
}

void listarItens(Item lista[], int tamanho) {
    if (tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("=== ITENS NA LISTA DE COMPRAS ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s: %d\n", lista[i].nome, lista[i].quantidade);
    }
}

int main() {
    Item lista[MAX_ITENS];
    int tamanho = 0;
    int opcao;

    do {
        printf("\nMENU LISTA DE COMPRAS\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(lista, &tamanho);
                break;
            case 2:
                removerItem(lista, &tamanho);
                break;
            case 3:
                listarItens(lista, tamanho);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}