#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Item
{
    int num;
    struct Item *filhoEsq;
    struct Item *filhoDir;
} Item;

typedef struct Arvore
{
    Item *raiz;
    int numElementos;
} Arvore;

Item *criarItem(int num)
{
    Item *novoItem = new Item;

    if (novoItem == nullptr)
    {
        printf("Erro ao alocar memoria\n");
        return nullptr;
    }

    novoItem->num = num;
    novoItem->filhoEsq = nullptr;
    novoItem->filhoDir = nullptr;
    return novoItem;
}

void addItem(Item *node, Item *novoItem)
{
    if (node == nullptr || novoItem == nullptr)
    {
        printf("Erro ao adicionar item\n");
        return;
    }

    if (node->num >= novoItem->num)
    {
        if (node->filhoEsq == nullptr)
        {
            node->filhoEsq = novoItem;
        }
        else
        {
            addItem(node->filhoEsq, novoItem);
        }
    }
    else 
    {
        if (node->filhoDir == nullptr)
        {
            node->filhoDir = novoItem;
        }
        else
        {
            addItem(node->filhoDir, novoItem);
        }
    }
}

void imprimirArvore(Item *raiz, int nivel = 0)
{
    if (raiz == nullptr)
    {
        return;
    }

    imprimirArvore(raiz->filhoEsq, nivel + 1);
    for (int i = 0; i < nivel; i++)
    {
        printf("  ");
    }
    printf("%d\n", raiz->num);
    imprimirArvore(raiz->filhoDir, nivel + 1);
}

int main()
{
    srand(time(0));
    Arvore arvore;
    arvore.raiz = nullptr;
    arvore.numElementos = 0;

    int n = 20;
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        Item *novoItem = criarItem(num);
        if (arvore.raiz == nullptr)
        {
            arvore.raiz = novoItem;
        }
        else
        {
            addItem(arvore.raiz, novoItem);
        }
        arvore.numElementos++;
    }

    printf("Arvore Binaria:\n");
    imprimirArvore(arvore.raiz);

    return 0;
}
