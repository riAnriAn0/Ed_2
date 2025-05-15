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

elemento *meio_lista(elemento *inicio) {
    if (inicio == NULL || inicio->prox == NULL)
        return inicio;

    elemento *lento = inicio;
    elemento *rapido = inicio->prox;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    return lento;
}

elemento *mesclar(elemento *esq, elemento *dir) {
    if (!esq) return dir;
    if (!dir) return esq;

    elemento *resultado = NULL;

    if (esq->cont <= dir->cont) {
        resultado = esq;
        resultado->prox = mesclar(esq->prox, dir);
        if (resultado->prox)
            resultado->prox->ant = resultado;
        resultado->ant = NULL;
    } else {
        resultado = dir;
        resultado->prox = mesclar(esq, dir->prox);
        if (resultado->prox)
            resultado->prox->ant = resultado;
        resultado->ant = NULL;
    }

    return resultado;
}

elemento *mergeSort(elemento *cabeca) {
    if (!cabeca || !cabeca->prox)
        return cabeca;

    elemento *meio = meio_lista(cabeca);
    elemento *metade = meio->prox;
    meio->prox = NULL;
    if (metade) metade->ant = NULL;

    elemento *esq = mergeSort(cabeca);
    elemento *dir = mergeSort(metade);

    return mesclar(esq, dir);
}


void ordenar_merge(List *lista) {
    lista->cabeca = mergeSort(lista->cabeca);

    elemento *atual = lista->cabeca;
    while (atual && atual->prox != NULL) {
        atual = atual->prox;
    }
    lista->fim = atual;
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

    ordenar_merge(lista);

    printf("Depois da ordenação:\n");
    imprimir(lista);

    return 0;
}
