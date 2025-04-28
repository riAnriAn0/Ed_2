#include <math.h>
#include <stdio.h>
#include <time.h>

#include <random>

void inicia_vetor(int *vetor, int n)
{
    srand(clock());
    for (int i = 0; i < n; i++)
    {
        vetor[i] = (abs(rand()) % 100);
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

int sort_otimizado(int *vetor, int n)
{
    int comparacoes = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        bool troca = false;
        for (int j = 0; j < (n - 1 - i); j++) // reduz o numero de comparações cada vez que um item é ordenado
        {
            comparacoes++;
            if ((vetor[j] > vetor[j + 1]))
            {
                trocar(vetor, j, (j + 1));
                troca = true;
            }
        }
        if (!(troca)) // finaliza a execução caso esteja tudo em ordem
        {
            return comparacoes;
        }
    }
    return comparacoes;
}

int main()
{
    int n = 10;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    inicia_vetor(vetor, n);

    printf("Vetor:\n");
    imprimir(vetor, n);

    int comp = sort_otimizado(vetor, n);
    printf("***Comparacoes: %d\n\n", comp);

    printf("Vetor Ordenado:\n");
    imprimir(vetor, n);
    return 0;
}
