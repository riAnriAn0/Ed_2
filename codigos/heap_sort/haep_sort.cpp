#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % 100;
    }
}

void imprime(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[ %d ] ", vetor[i]);
    }
    printf("\n");
}

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pai(int i)
{
    return (i - 1) / 2;
}

int filho_esquerdo(int i)
{
    return 2 * i + 1;
}

int filho_direito(int i)
{
    return 2 * i + 2;
}

void maxHeap(int *vetor, int n){
    int i = n/2 -1; // inicia pelo ultimo elemento pai
    for (int j = i; j >= 0; j--)
    {
        int maior = j;
        int esquerda = filho_esquerdo(j);
        int direita = filho_direito(j);

        if (esquerda < n && vetor[esquerda] > vetor[maior])
        {
            maior = esquerda;
        }
        if (direita < n && vetor[direita] > vetor[maior])
        {
            maior = direita;
        }
        if (maior != j)
        {
            trocar(&vetor[j], &vetor[maior]);
            j = maior; // reinicia o loop para verificar a nova posição
        }
    }
    
}

void minHeap(int *vetor, int n){
    int i = n/2 -1; // inicia pelo ultimo elemento pai
    for (int j = i; j >= 0; j--)
    {
        int menor = j;
        int esquerda = filho_esquerdo(j);
        int direita = filho_direito(j);

        if (esquerda < n && vetor[esquerda] < vetor[menor])
        {
            menor = esquerda;
        }
        if (direita < n && vetor[direita] < vetor[menor])
        {
            menor = direita;
        }
        if (menor != j)
        {
            trocar(&vetor[j], &vetor[menor]);
            j = menor; // reinicia o loop para verificar a nova posição
        }
    }
}

void heapSort(int *vetor, int n)
{
    // Construir o max heap
    maxHeap(vetor, n);

    // Extrair elementos do heap
    for (int i = n - 1; i > 0; i--)
    {
        trocar(&vetor[0], &vetor[i]); // Move o maior elemento para o final
        maxHeap(vetor, i); // Reconstroi o max heap para os elementos restantes
    }
}

int main()
{
    
    srand(time(NULL));
    int n;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Tamanho do vetor deve ser maior que zero.\n");
        return 1;
    }
    
    int vetor[n];

    inicializa(vetor, n);
    printf("Vetor inicial:");
    imprime(vetor, n);

    heapSort(vetor, n);

    printf("Vetor ordenado:");
    imprime(vetor, n);

    return 0;
}
