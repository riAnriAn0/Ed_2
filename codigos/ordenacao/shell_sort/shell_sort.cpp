#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void iniciar_vetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = abs(rand() % 101);
    }
}

void print_vetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] -> ", vetor[i]);
    }
}

void trocar(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void shellSort(int *vetor, int n)
{
    int gap = (n/ 2);

    while (gap >= 1)
    {
        for (int j = 0; j <= gap; j++)
        {
            for (int i = gap; i + gap < n; i += gap)
            {
                int atual = vetor[i];
                int index = i;
                while(index > 0 && vetor[index - gap] > atual){
                    vetor[index] = vetor[index - gap];
                    index -= gap;
                }
                vetor[index] = atual;
            }
        }
        gap /= 2;
    }
}

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    int tam = 5;
    int lista[tam];

    iniciar_vetor(lista, tam);

    printf("Lista Desordenada\n");
    print_vetor(lista, tam);

    shellSort(lista, tam);

    printf("\n\nLista Ordenada\n");
    print_vetor(lista, tam);

    return 0;
}