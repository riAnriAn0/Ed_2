#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int numero_elementos = 0;

    printf("Numeros de elementos do vetor 1 a 10: ");
    scanf("%d", &numero_elementos);

    int vet[numero_elementos] = {0};

    for (int i = 0; i < numero_elementos; i++)
    {
        vet[i] = rand() % numero_elementos;
    }

    for (int j = 0; j < numero_elementos; j++)
    {
        for (int i = 0; i < numero_elementos; i++)
        {

            if ((vet[i] > vet[i + 1]) && (i + 1 != numero_elementos))
            {
                int aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }

    for (int i = 0; i < numero_elementos; i++)
    {
        printf("%d - ", vet[i]);
    }

    return 0;
}
