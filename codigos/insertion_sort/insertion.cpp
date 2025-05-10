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

void insertion_sort(celula *head)
{
    if (head == NULL)
        return;

    celula *aux = head;

    while (aux->prox != NULL)
    {
        int elemanto_atual = aux->prox->conteudo;
        celula *indice = aux->prox;

        while (indice->ant != NULL && indice->ant->conteudo >= elemanto_atual)
        {
            indice->conteudo = indice->ant->conteudo;
            indice = indice->ant;
        }

        indice->conteudo = elemanto_atual;
        
        aux = aux->prox;
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
