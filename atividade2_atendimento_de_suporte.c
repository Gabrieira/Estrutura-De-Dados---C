#include <stdio.h>
#include <string.h>

#define MAX 5  
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
} Cliente;

typedef struct {
    Cliente fila[MAX];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int cheia(FilaCircular *f) {
    return f->quantidade == MAX;
}

int vazia(FilaCircular *f) {
    return f->quantidade == 0;
}

void entrar(FilaCircular *f) {
    if (cheia(f)) {
        printf("Fila cheia! Nao e possivel adicionar mais clientes.\n");
        return;
    }

    char nome[TAM_NOME];
    printf("Nome do cliente: ");
    scanf("%s", nome);

    strcpy(f->fila[f->fim].nome, nome);

    f->fim = (f->fim + 1) % MAX;
    f->quantidade++;

    printf("Cliente %s entrou na fila.\n", nome);
}

void atender(FilaCircular *f) {
    if (vazia(f)) {
        printf("Fila vazia! Nao ha clientes para atender.\n");
        return;
    }

    printf("Atendendo cliente: %s\n", f->fila[f->inicio].nome);

    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;
}

void listar(FilaCircular *f) {
    if (vazia(f)) {
        printf("Fila vazia. Nao ha clientes aguardando.\n");
        return;
    }

    printf("=== CLIENTES NA FILA ===\n");

    int i = f->inicio;
    for (int c = 0; c < f->quantidade; c++) {
        printf("%d - %s\n", c + 1, f->fila[i].nome);
        i = (i + 1) % MAX;
    }
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    int opcao;

    do {
        printf("\nMENU ATENDIMENTO SUPORTE\n");
        printf("1 - ENTRAR cliente\n");
        printf("2 - ATENDER cliente\n");
        printf("3 - LISTAR fila\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                entrar(&fila);
                break;
            case 2:
                atender(&fila);
                break;
            case 3:
                listar(&fila);
                break;
            case 4:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
