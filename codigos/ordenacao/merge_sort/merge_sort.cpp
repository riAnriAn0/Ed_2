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
int *merge(int *vetor, int inicio1, int fim1, int inicio2, int fim2)
{
    int cont_1 = 0; 
    int cont_2 = 0; 

    for (int i = inicio1; i <= fim2; i++)
    {
        if (vetor[inicio1 + cont_1] < vetor[inicio2 + cont_2])
        {
            int temp = vetor[inicio1 + cont_1];
            
        }
    }
}

int *divdir(int *vetor, int start, int end)
{
    if (start == end)
    {
        printf("apenas 1 elemento: %d", vetor[start]);
        return;
    }

    if (end - start)
    {
        printf("caso 2 elementos: (%d, %d)", vetor[0], vetor[1]);
        return;
    }

    int meio = (start + end) / 2.0;
    divdir(vetor, start, meio);
    divdir(vetor, meio + 1, end);

    int *res = merge(vetor, start, meio, meio + 1, end);
    return res;
}

int main()
{
    int n = 10;
    int vetor[n];

    inicia_vetor(vetor, n);

    imprimir(vetor, n);
    return 0;
}
