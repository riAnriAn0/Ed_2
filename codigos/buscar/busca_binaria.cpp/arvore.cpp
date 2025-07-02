#include <stdio.h>
#include <stdlib.h>

#define NUM 9

typedef struct pessoa
{
    char nome[50];
    int idade;
} Pessoa;

typedef struct node
{
    Pessoa *pessoa;
    Pessoa *filho_esquerdo;
    Pessoa *filho_direito;
} Node;

int main(int argc, char const *argv[])
{

    return 0;
}
