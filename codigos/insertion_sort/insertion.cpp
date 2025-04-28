#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>

typedef struct cel
{
    int conteudo;
    struct cel *prox;
    struct cel *ant;
} celula;

void iniciar_vetor(celula **head)
{
    celula *novo_item = (celula *)malloc(sizeof(celula));
    novo_item->ant = NULL;
    novo_item->prox = NULL;
    novo_item->conteudo = 0;

    if (*head == NULL)
    {

        novo_item->conteudo = (rand() % 100);
        *head = novo_item;
    }
    else
    {

        celula *aux = *head;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo_item;
        novo_item->ant = aux;
        novo_item->conteudo = (rand() % 100);
    }
    return;
}

void imprimir(celula *head)
{
    celula *aux = head;
    printf("\nLISTA\n");
    while (aux != NULL)
    {
        printf(" %d ->", aux->conteudo);
        aux = aux->prox;
    }
}

void trocar(celula *i, celula *j)
{
    int aux = i->conteudo;
    i->conteudo = j->conteudo;
    j->conteudo = aux;
}

void insertion_sort(celula *head)
{
      if(head == NULL) return;
    celula *lista = head->prox;

    while (lista != NULL)
    {

        celula *j = lista;
        while (j->ant != NULL && j->conteudo < j->ant->conteudo)
        {

            trocar(j, j->ant);
            j = j->ant;
        }
        lista = lista->prox;
    }
}

int main()
{

    int n = 10;

    celula *lista = NULL;

    for (int i = 0; i < n; i++)
    {
        iniciar_vetor(&lista);
    }

    imprimir(lista);
    insertion_sort(lista);
    imprimir(lista);
    return 0;
}
