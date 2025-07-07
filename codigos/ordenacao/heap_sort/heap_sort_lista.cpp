#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Item
{
    int num;
    struct Item *pai = nullptr;
    struct Item *filhoEsq = nullptr;
    struct Item *filhoDir = nullptr;
} Item;

typedef struct Arvore
{
    Item *raiz = nullptr;
    int numElementos;
} Arvore;

Item *criarItem(int num)
{
    Item *novoItem = new Item;
    novoItem->num = num;
    novoItem->pai = nullptr;
    novoItem->filhoEsq = nullptr;
    novoItem->filhoDir = nullptr;
    return novoItem;
}

void maxHaep(Item *node, Item *novoItem)
{

    if (node == nullptr || novoItem == nullptr)
    {
        printf("Erro ao inicializar a árvore ou criar o item.\n");
        return;
    }

    if (node->num < novoItem->num)
    {
        int temp = node->num;
        node->num = novoItem->num;
        novoItem->num = temp;

        if (node->pai != nullptr)
            maxHaep(node->pai, node);
    }
    
}

void imprimirArvore(Item *raiz, int nivel = 0)
{
    if (raiz == nullptr)
        return;

    imprimirArvore(raiz->filhoEsq, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("   ");

    printf("%d\n", raiz->num);

    imprimirArvore(raiz->filhoDir, nivel + 1);
}

int main()
{
    srand(time(NULL));
    int n = 10;
    Arvore arvore;
    arvore.numElementos = n;

    arvore.raiz = criarItem(rand() % 100);
    printf("Raiz: %d\n", arvore.raiz->num);

    for (int i = 1; i < n; i++)
    {
        Item *novoItem = criarItem(rand() % 100);
        maxHaep(arvore.raiz, novoItem);
    }

    printf("Arvore:\n");
    imprimirArvore(arvore.raiz);

    return 0;
}