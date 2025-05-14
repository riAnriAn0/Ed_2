#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item
{
    struct item *prox;
    struct item *ant;
    int cont;
} Item;

void trocar(Item **lista, Item *item1, Item *item2) {
    if (item1 == item2) return;

    Item *ant1 = item1->ant;
    Item *prox1 = item1->prox;
    Item *ant2 = item2->ant;
    Item *prox2 = item2->prox;

    // Se são adjacentes
    if (item1->prox == item2) {
        item1->prox = prox2;
        item1->ant = item2;

        item2->prox = item1;
        item2->ant = ant1;

        if (ant1) ant1->prox = item2;
        if (prox2) prox2->ant = item1;
    } else if (item2->prox == item1) {
        // item2 antes de item1
        item2->prox = prox1;
        item2->ant = item1;

        item1->prox = item2;
        item1->ant = ant2;

        if (ant2) ant2->prox = item1;
        if (prox1) prox1->ant = item2;
    } else {
        // troca geral
        if (ant1) ant1->prox = item2;
        if (prox1) prox1->ant = item2;

        if (ant2) ant2->prox = item1;
        if (prox2) prox2->ant = item1;

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

void imprimir(Item *lista)
{
    Item *aux = lista;
    while (aux != NULL)
    {
        printf("[%d] <-> ", aux->cont);
        aux = aux->prox;
    }
    printf("FIM.\n");
}

void inicia_vetor(Item **lista)
{
    Item *novo_Item = (Item *)malloc(sizeof(Item));
    novo_Item->cont = (abs(rand()) % 50);
    novo_Item->ant = NULL;
    novo_Item->prox = NULL;

    if (*lista == NULL)
    {
        *lista = novo_Item;
    }
    else
    {
        Item *aux = *lista;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo_Item;
        novo_Item->ant = aux;
    }
    return;
}

int main()
{

    srand(time(NULL));

    Item *lista_teste = NULL;
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        inicia_vetor(&lista_teste);
    }

    imprimir(lista_teste);

    printf("%d\n", lista_teste->cont);
    printf("%d\n", lista_teste->prox->cont);

    trocar(&lista_teste, lista_teste->prox->prox->prox, lista_teste);

    imprimir(lista_teste);
    return 0;
}