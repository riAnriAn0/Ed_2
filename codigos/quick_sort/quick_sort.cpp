#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void inicia_vetor(int *vetor, int n)
{
    srand(clock());
    for (int i = 0; i < n; i++)
    {
        vetor[i] = abs(rand()) % 50;
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

int particao(int *vetor, int left, int right)
{
    int pivo = vetor[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (vetor[j] < pivo) 
        {
            i++;
            trocar(vetor, i, j);
        }
    }
    trocar(vetor, i + 1, right);
    return i + 1;
}

void quick_sort(int *vetor, int left, int right)
{
    if (left >= right) return;

    int p_pivo = particao(vetor, left, right);
    quick_sort(vetor, left, p_pivo - 1);
    quick_sort(vetor, p_pivo + 1, right);
}

int main()
{
    int n = 15;
    int vetor[n];

    inicia_vetor(vetor, n);

    printf("Vetor original:\n");
    imprimir(vetor, n);

    quick_sort(vetor, 0, n - 1);

    printf("Vetor ordenado:\n");
    imprimir(vetor, n);

    return 0;
}
