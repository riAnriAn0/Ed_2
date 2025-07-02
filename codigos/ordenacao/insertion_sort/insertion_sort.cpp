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
        printf("[%d] -> ", vetor[i]);
    }
    printf("FIM\n");
}


void insertion_sort(int *vetor, int n)
{
    for (int j = 1; j < n; j++)
    {
        int index = j;
        int elemento_atual = vetor[j];

        while (index > 0 && vetor[index - 1] > elemento_atual)
        {
            vetor[index] = vetor[index - 1];
            index--;
        }

        vetor[index] = elemento_atual;

    }   
}

int main()
{
    int n = 20;
    int vetor[n] = {};

    inicia_vetor(vetor, n);

    imprimir(vetor, n);
    insertion_sort(vetor, n);
    imprimir(vetor, n);
    return 0;
}
