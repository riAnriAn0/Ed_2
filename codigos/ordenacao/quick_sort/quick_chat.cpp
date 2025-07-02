#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento {
    int cont;
    struct elemento *prox;
    struct elemento *ant;
} elemento;

typedef struct list {
    int tam;
    elemento *cabeca;
    elemento *fim;
} List;

elemento *criaItem() {
    elemento *novo_elemento = (elemento *)malloc(sizeof(elemento));
    novo_elemento->cont = abs(rand() % 50);
    novo_elemento->ant = NULL;
    novo_elemento->prox = NULL;
    return novo_elemento;
}

void inicia_vetor(List *lista) {
    elemento *item = criaItem();

    if (lista->cabeca == NULL) {
        lista->cabeca = item;
        lista->fim = item;
    } else {
        lista->fim->prox = item;
        item->ant = lista->fim;
        lista->fim = item;
    }

    lista->tam++;
}

void imprimir(List *lista) {
    elemento *aux = lista->cabeca;
    while (aux != NULL) {
        printf("[%d] <-> ", aux->cont);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void trocar_valores(elemento *a, elemento *b) {
    int temp = a->cont;
    a->cont = b->cont;
    b->cont = temp;
}

elemento *dividir(List *lista, elemento *inicio, elemento *fim) {
    int pivo = fim->cont;
    elemento *i = inicio->ant;

    for (elemento *j = inicio; j != fim; j = j->prox) {
        if (j->cont <= pivo) {
            i = (i == NULL) ? inicio : i->prox;
            trocar_valores(i, j);
        }
    }

    i = (i == NULL) ? inicio : i->prox;
    trocar_valores(i, fim);
    return i;
}

void quicksort(List *lista, elemento *inicio, elemento *fim) {
    if (inicio != NULL && fim != NULL && inicio != fim && inicio != fim->prox) {
        elemento *corte = dividir(lista, inicio, fim);
        quicksort(lista, inicio, corte->ant);
        quicksort(lista, corte->prox, fim);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;

    List *lista = (List *)malloc(sizeof(List));
    lista->cabeca = NULL;
    lista->fim = NULL;
    lista->tam = 0;

    for (int i = 0; i < n; i++) {
        inicia_vetor(lista);
    }

    printf("Antes da ordenação:\n");
    imprimir(lista);

    quicksort(lista, lista->cabeca, lista->fim);

    printf("Depois da ordenação:\n");
    imprimir(lista);

    return 0;
}
