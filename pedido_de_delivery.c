#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 100
#define TAM_NOME 50

typedef struct {
    int id;
    char cliente[TAM_NOME];
} Pedido;

int procurarPedido(Pedido lista[], int tamanho, int id) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i].id == id) {
            return i;
        }
    }
    return -1;
}

void cadastrarPedido(Pedido lista[], int *tamanho) {
    if (*tamanho >= MAX_PEDIDOS) {
        printf("Lista de pedidos cheia!\n");
        return;
    }

    Pedido p;
    printf("ID do pedido: ");
    scanf("%d", &p.id);
    getchar(); 

    if (procurarPedido(lista, *tamanho, p.id) != -1) {
        printf("Ja existe um pedido com esse ID.\n");
        return;
    }

    printf("Nome do cliente: ");
    fgets(p.cliente, TAM_NOME, stdin);
    p.cliente[strcspn(p.cliente, "\n")] = '\0';

    lista[*tamanho] = p;
    (*tamanho)++;

    printf("Pedido cadastrado com sucesso!\n");
}

void marcarEntregue(Pedido lista[], int *tamanho) {
    if (*tamanho == 0) {
        printf("Nao ha pedidos pendentes.\n");
        return;
    }

    int id;
    printf("ID do pedido entregue: ");
    scanf("%d", &id);

    int idx = procurarPedido(lista, *tamanho, id);
    if (idx == -1) {
        printf("Pedido nao encontrado.\n");
        return;
    }

    for (int i = idx; i < *tamanho - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*tamanho)--;

    printf("Pedido %d marcado como entregue e removido da lista.\n", id);
}

void listarPendentes(Pedido lista[], int tamanho) {
    if (tamanho == 0) {
        printf("Nao ha pedidos pendentes.\n");
        return;
    }

    printf("=== PEDIDOS PENDENTES ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d | Cliente: %s\n", lista[i].id, lista[i].cliente);
    }
}

int main() {
    Pedido lista[MAX_PEDIDOS];
    int tamanho = 0;
    int opcao;

    do {
        printf("\nMENU PEDIDOS DELIVERY\n");
        printf("1 - Cadastrar pedido\n");
        printf("2 - Marcar pedido como entregue\n");
        printf("3 - Listar pedidos pendentes\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                cadastrarPedido(lista, &tamanho);
                break;
            case 2:
                marcarEntregue(lista, &tamanho);
                break;
            case 3:
                listarPendentes(lista, tamanho);
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
