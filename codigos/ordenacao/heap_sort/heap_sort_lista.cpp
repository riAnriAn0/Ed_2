#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Item
{
    int num;
    struct Item *pai = nullptr;
    struct Item *filhoEsq = nullptr;
    struct Item *filhoDir = nullptr;
}Item;

typedef struct Arvore
{
    Item *raiz = nullptr;
    int numElementos;
}Arvore;

void inicializaArvore(Arvore *arvore, int numElementos)
{
    Item *novoItem = new Item;
    novoItem->num = (abs(rand()) % 100);

    if(arvore->raiz->filhoEsq == nullptr)
    {
        arvore->raiz->filhoEsq = novoItem;
        novoItem->pai = arvore->raiz;
        return; 
    }else if(arvore->raiz->filhoDir == nullptr)
    {
        arvore->raiz->filhoDir = novoItem;
        novoItem->pai = arvore->raiz;
        return; 
    }
}