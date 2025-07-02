#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int numero_elementos = 0;
    int numero_buscas = 0;
    int numero_comparacoes = 0;

    printf("--------------------------\n");
    printf("Numero de elementos da lista: ");
    scanf("%d", &numero_elementos); 
    printf("Numero de Buscas: ");
    scanf("%d", &numero_buscas);
    printf("--------------------------\n");

    int vet_comparacoes[numero_buscas] = {0};
    int vet_dados[numero_elementos] = {0};

    for (int i = 0; i < numero_elementos; i++){
        vet_dados[i] = rand() % numero_elementos;
    }

    for (int j = 0; j < numero_buscas; j++){

        numero_comparacoes = 0;
        
        int indice = rand() % numero_elementos;
        int elemento_buscado = vet_dados[indice];

        for (int i = 0; i < numero_elementos; i++){
            numero_comparacoes++;
            if (vet_dados[i] == elemento_buscado){
               break;
            }
        }
        vet_comparacoes[j] = numero_comparacoes;
    }

    // for (int j = 0; j < numero_buscas; j++){
    //     numero_comparacoes = 0;
    //     int elemento_buscado = rand() % numero_elementos;

    //     for (int i = 0; i < numero_elementos; i++){
    //         numero_comparacoes++;
    //         if (vet_dados[i] == elemento_buscado){
    //            break;
    //         }
    //     }
    //     vet_comparacoes[j] = numero_comparacoes;
    // }

    int soma = 0;

    for (int i = 0; i < numero_buscas; i++){
        soma += vet_comparacoes[i];
    }

    float media = (float)soma / numero_buscas;

    printf("\n-------------------------\n");
    printf("Numero de elementos da lista: %d\n", numero_elementos);
    printf("Numero de Buscas: %d\n", numero_buscas);
    printf("Media de comparacoes: %f\n", media);
    printf("\n-------------------------\n");

    return 0;
}