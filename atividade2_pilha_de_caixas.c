#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM_NOME 50

typedef struct {
    char caixas[MAX][TAM_NOME];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;   // pilha vazia
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p) {
    if (cheia(p)) {
        printf("Pilha cheia! Nao e possivel empilhar mais caixas.\n");
        return;
    }

    char nome[TAM_NOME];
    printf("Nome da caixa: ");
    scanf("%s", nome);

    p->topo++;
    strcpy(p->caixas[p->topo], nome);

    printf("Caixa %s empilhada com sucesso!\n", nome);
}

void desempilhar(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia! Nao ha caixas para remover.\n");
        return;
    }

    printf("Desempilhando caixa: %s\n", p->caixas[p->topo]);
    p->topo--;
}

void mostrarTopo(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia! Nenhuma caixa no topo.\n");
        return;
    }

    printf("Caixa no topo: %s\n", p->caixas[p->topo]);
}

void listar(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia. Nao ha caixas armazenadas.\n");
        return;
    }

    printf("=== CAIXAS NA PILHA (TOPO -> BASE) ===\n");

    for (int i = p->topo; i >= 0; i--) {
        printf("%s\n", p->caixas[i]);
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    int opcao;

    do {
        printf("\nMENU - PILHA DE CAIXAS\n");
        printf("1 - Empilhar caixa\n");
        printf("2 - Desempilhar caixa\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Listar caixas\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                empilhar(&pilha);
                break;
            case 2:
                desempilhar(&pilha);
                break;
            case 3:
                mostrarTopo(&pilha);
                break;
            case 4:
                listar(&pilha);
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
