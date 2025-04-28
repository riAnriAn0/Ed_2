#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>

typedef struct cel
{
    int conteudo;
    struct cel *prox;
} celula;

void inicia_vetor(celula **vetor, int n)
{
    srand(clock());
    celula *aux = *vetor;
    for (int i = 0; i < n; i++)
    {
        celula *item = (celula *)malloc(sizeof(celula));
        if (item = NULL)
        {
            return;
        }

        item->prox = NULL;
        item->conteudo = (abs(rand()) % 100);

        if ((*vetor) == NULL)
        {
            (*vetor)->prox = item;
        }

    }
}

void imprimir(celula *vetor, int n)
{
    printf("======================\n");
    celula *aux = vetor;
    while (aux != NULL)
    {
        printf("Conteudo: %d\n", aux->conteudo);
        printf("======================\n");

        aux = aux->prox;
    }
}

void trocar(celula *item_1, celula *item_2)
{
    celula *aux = item_1;
    item_1 = item_2;
    item_2 = aux;
}

int bubble_sort(celula **vetor, int n)
{
    int comparacoes = 0;
    celula *aux = *vetor;

    for (int i = 0; i < (n - 1); i++)
    {
        bool troca = false;
        for (int j = 0; j < (n - 1 - i); j++) // reduz o numero de comparações cada vez que um item é ordenado
        {
            comparacoes++;
            if ((aux->conteudo) > (aux->prox->conteudo))
            {
                celula *prox = aux->prox;
                trocar((aux), (aux->prox));
                troca = true;
            }
            aux = aux->prox;
        }
        if (!(troca)) // finaliza a execução caso esteja tudo em ordem
        {
            return comparacoes;
        }
    }
    return comparacoes;
}
