#include <stdio.h>
#include <time.h>
#include <random>
#include <stdlib.h>

typedef struct elemento{
    int cont;
    struct elemento *prox;
    struct elemento *ant;
} elemento;

typedef struct list{
    int tam = 0;
    elemento *cabeca;
    elemento *fim;
}List;

elemento *criaItem(){
    elemento *novo_elemento = (elemento *)malloc(sizeof(elemento));
    novo_elemento->cont = (abs(rand()) % 50);
    novo_elemento->ant = NULL;
    novo_elemento->prox = NULL;

    return novo_elemento;
}

void inicia_vetor(List **lista)
{
    elemento *item = criaItem();

    if ((*lista)->cabeca == NULL)
    {
        (*lista)->cabeca = item;
        (*lista)->fim = item;
    }
    else
    {
        elemento *aux = (*lista)->cabeca;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = item;
        item->ant = aux;
        (*lista)->fim = item;
    }
    (*lista)->tam++;
}

void imprimir(list *lista)
{
    elemento *aux = lista->cabeca;
    while (aux != NULL)
    {
        printf("[%d] <->", aux->cont);
        aux = aux->prox;
    }
    printf("NULL.\n");
}

void trocar(elemento **lista, elemento *item1, elemento *item2)
{
    if (item1 == item2)
        return;

    elemento *ant1 = item1->ant;
    elemento *prox1 = item1->prox;
    elemento *ant2 = item2->ant;
    elemento *prox2 = item2->prox;

    // Se são adjacentes
    if (item1->prox == item2)
    {
        item1->prox = prox2;
        item1->ant = item2;

        item2->prox = item1;
        item2->ant = ant1;

        if (ant1)
            ant1->prox = item2;
        if (prox2)
            prox2->ant = item1;
    }
    else if (item2->prox == item1)
    {
        // item2 antes de item1
        item2->prox = prox1;
        item2->ant = item1;

        item1->prox = item2;
        item1->ant = ant2;

        if (ant2)
            ant2->prox = item1;
        if (prox1)
            prox1->ant = item2;
    }
    else
    {
        // troca geral
        if (ant1)
            ant1->prox = item2;
        if (prox1)
            prox1->ant = item2;

        if (ant2)
            ant2->prox = item1;
        if (prox2)
            prox2->ant = item1;

        item1->ant = ant2;
        item1->prox = prox2;

        item2->ant = ant1;
        item2->prox = prox1;
    }

    // atualiza o ponteiro para a cabeça da lista, se necessário
    if (*lista == item1)
        *lista = item2;
    else if (*lista == item2)
        *lista = item1;
}

elemento *dividir(List *lista, elemento *inicio, elemento *fim) {
    elemento *pivo = fim;
    elemento *i = inicio->ant;

    for (elemento *j = inicio; j != fim; j = j->prox) {
        if (j->cont <= pivo->cont) {
            i = (i == NULL) ? inicio : i->prox;
            trocar(&lista->cabeca, i, j);
        }
    }

    i = (i == NULL) ? inicio : i->prox;
    trocar(&lista->cabeca, i, fim);
    return i;
}

void quicksort(List **lista, elemento *inicio, elemento *fim) {
    if (inicio != NULL && fim != NULL && inicio != fim && inicio != fim->prox) {
        elemento *corte = dividir(*lista, inicio, fim);
        quicksort(lista, inicio, corte->ant);
        quicksort(lista, corte->prox, fim);
    }
}

int main()
{
    srand(time(NULL));
    int n = 10;

    List *lista;
    
    lista->cabeca = NULL;
    lista->fim = NULL;
    lista->tam = 0;
    
    for (int i = 0; i < n; i++)
    {
        inicia_vetor(&lista);
    }
    imprimir(lista);
    
    quicksort(&lista, lista->cabeca, lista->fim);

    imprimir(lista);
    return 0;
}
