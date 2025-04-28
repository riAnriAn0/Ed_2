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

int n_trocas = 0;
int voltas = 0;

void insertion_sort(int *vetor, int n)
{
    for (int j = 1; j < n; j++)
    {   
        bool ordenado = true;
        int i = j;
        while (i > 0 && vetor[i] < vetor[i - 1])
        {
            trocar(vetor, i, i - 1);
            ordenado = false;
            n_trocas++;
            i--;
        }
        voltas++;
        if(ordenado) return;
    }
}

int main()
{
    int n = 10;
    int vetor[n];

    inicia_vetor(vetor, n);

    imprimir(vetor, n);
    insertion_sort(vetor, n);
    imprimir(vetor, n);
    printf("\nNumero de trocas: %d\n", n_trocas);
    printf("Numero de voltas: %d\n", voltas);
    return 0;
}
