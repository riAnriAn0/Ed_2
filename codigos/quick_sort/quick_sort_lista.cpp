#include <math.h>
#include <stdio.h>
#include <time.h>
#include <random>

typedef struct elemento
{
    int cont;
    struct elemento *prox;
    struct elemento *ant;
} elemento;


elemento* final_lista2(elemento*lista){
    elemento *aux = lista;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    return aux;
}

void inicia_vetor(elemento **lista)
{
    elemento *novo_elemento = (elemento *)malloc(sizeof(elemento));
    novo_elemento->cont = (abs(rand()) % 50);
    novo_elemento->ant = NULL;
    novo_elemento->prox = NULL;

    if (*lista == NULL)
    {
        *lista = novo_elemento;
    }
    else
    {
        elemento *aux = *lista;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo_elemento;
        novo_elemento->ant = aux;
    }
    return;
}


void imprimir(elemento *lista)
{
    elemento *aux = lista;
    while (aux->prox != NULL)
    {
        printf("[%d] ->", aux->cont);
        aux = aux->prox;
    }
    printf("FIM.\n");
}

void trocar(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int particao(int *vetor, int left, int right)
{
    int pivo = vetor[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (vetor[j] <= pivo)
        {
            i++;
            trocar(vetor, i, j);
        }
    }
    trocar(vetor, i + 1, right);
    return i + 1;
}

void quick_sort(elemento *inicio, elemento *final)
{ // posição do pivô na lista
    if (inicio == final || inicio == NULL || final == NULL)
    {
        return;
    }

    elemento *pivo = inicio;

    bool run = true;

    while (run)
    {
        while (inicio->prox != final && inicio->cont < pivo->cont)
        {
            inicio = inicio->prox;
        }

        while (final->ant != inicio && final->cont > pivo->cont)
        {
            final = final->ant;
        }

        if (final->prox == inicio->ant)
        {
            run = false;
        }else{
            int temp = inicio->cont;
            inicio->cont = final->cont;
            final->cont = temp;
        }
    }

    elemento *temp = final;

    pivo->prox->ant = NULL;

    final->prox = pivo;
    pivo->ant = final;
    pivo->prox = temp->prox;
    temp->prox->ant = pivo;

    elemento *last = final(*lista);

    quick_sort(lista, *lista, final);
    quick_sort(lista,final->prox->prox,last);
   
}

int main()
{
    srand(clock());
    int n = 10;

    elemento *lista = NULL;
    for (int i = 0; i < n; i++)
    {
        inicia_vetor(&lista);
    }
    imprimir(lista);
    return 0;
}
