#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>

typedef struct item
{
    int cont;
    struct item *prox;
    struct item *ant;
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


void iniciar_vetor(Item **head)
{
    Item *novo_item = (Item *)malloc(sizeof(Item));
    novo_item->ant = NULL;
    novo_item->prox = NULL;
    novo_item->cont = 0;

    if (*head == NULL)
    {

        novo_item->cont = (rand() % 100);
        *head = novo_item;
    }
    else
    {

        Item *aux = *head;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo_item;
        novo_item->ant = aux;
        novo_item->cont = (rand() % 100);
    }
    return;
}

void imprimir(Item *head)
{
    Item *aux = head;
    printf("\nLISTA\n");
    while (aux != NULL)
    {
        printf(" [%d] <-> ", aux->cont);
        aux = aux->prox;
    }
}

void insertion_sort(Item **head)
{
    if (*head == NULL)
        return;

    Item *current = (*head)->prox;

    while (current != NULL)
    {
        Item *next = current->prox;
        Item *temp = current;

        while (temp->ant != NULL && temp->cont < temp->ant->cont)
        {
            trocar(head, temp->ant, temp);
        }

        current = next;
    }
}


int main()
{

    int n = 10;
    Item *lista = NULL;

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        iniciar_vetor(&lista);
    }

    imprimir(lista);
    insertion_sort(&lista);
    imprimir(lista);
    return 0;
}
