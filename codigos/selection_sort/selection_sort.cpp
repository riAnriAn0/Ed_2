#include <math.h>
#include <stdio.h>
#include <time.h>

#include <random>

void inicia_vetor(int *vetor, int n)
{
    srand(clock());
    for (int i = 0; i < n; i++)
    {
        vetor[i] = (abs(rand()) % 50);
    }
}

void imprimir(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", vetor[i]);
    }
    printf("FIM\n");
}

void trocar(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void selection_sort(int *vetor, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        int pos_menor = j;
        for (int i = j + 1; i < n; i++)
        {
            if (vetor[pos_menor] > vetor[i])
            {
                pos_menor = i;
            }
        }
        trocar(vetor, j, pos_menor);
    }

}

int main()
{
    int n = 5;
    int vetor[n];

    inicia_vetor(vetor, n);

    imprimir(vetor, n);
    selection_sort(vetor, n);
    imprimir(vetor, n);
    return 0;
}
