#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int num;
    struct node *filho_eqr;
    struct node *filho_drt;
} No;

No *criar_no(int num)
{
    No *novo_no = new No;

    if (novo_no == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    novo_no->num = num;
    novo_no->filho_eqr = NULL;
    novo_no->filho_drt = NULL;
    return novo_no;
}

void inserir_no(No *node, No *novo_no)
{
    if (node == NULL || novo_no == NULL)
    {
        printf("Erro\n");
        return;
    }

    if (node->num == novo_no->num)
    {
        printf("Numero ja existe\n");
        return;
    }

    if (novo_no->num <= node->num)
    { 
        if (node->filho_eqr == NULL)
        {
            node->filho_eqr = novo_no;
        }
        else
        {
            inserir_no(node->filho_eqr, novo_no);
        }
    }
    else
    { 
        if (node->filho_drt == NULL)
        {
            node->filho_drt = novo_no;
        }
        else
        {
            inserir_no(node->filho_drt, novo_no);
        }
    }
}

void imprime_arvore(No *node, int tab)
{
    if (node == NULL)
    {
        return;
    }

    imprime_arvore(node->filho_eqr, tab + 1);

    for (int i = 0; i < tab; i++)
    {
        printf("    ");
    }
    printf("%d\n", node->num);

    imprime_arvore(node->filho_drt, tab + 1);
}

No *buscar(No *node, int num)
{
    if (node == NULL)
    {
        printf("Arvore vazian\n");
        return NULL;
    }

    if (node->num == num)
    {
        return node;
    }
    else if (num < node->num)
    {
        return buscar(node->filho_eqr, num);
    }
    else
    {
        return buscar(node->filho_drt, num);
    }

    return NULL;
}

No *maior(No *node)
{
    if (node == NULL)
        return NULL;
    if (node->filho_drt == NULL)
        return node;
    return maior(node->filho_drt);
}

No *menor(No *node)
{
    if (node == NULL)
        return NULL;
    if (node->filho_eqr == NULL)
        return node;
    return menor(node->filho_eqr);
}

No *buscar_pai(No *node, int num)
{
    if(node == NULL || node->num == num) return NULL;

    if(node->filho_drt != NULL && node->filho_drt-> num == num) return node;
    if(node->filho_eqr != NULL && node->filho_eqr-> num == num) return node;

    if (num > node->num){
        return buscar_pai(node->filho_drt, num);
    }else{
        return buscar_pai(node->filho_eqr, num);
    }
}

int qntNo(No *node){
    if (node == NULL){
        return 0;
    }
    return (1 + qntNo(node->filho_drt) + qntNo(node->filho_eqr));
}

bool eh_folha(No *node){
    if(node == NULL) return false;

    if(node->filho_eqr == NULL && node->filho_drt == NULL)return true;
}


void remover_no(No **node, int num){
    if(*node == NULL) return;

    No *pai_no = buscar_pai(*node, num);
    No *no = buscar(*node, num);

    // remover folha
    if(eh_folha(no) && pai_no != NULL){
        if (pai_no->filho_drt == no){
            pai_no->filho_drt = NULL;
        }else if (pai_no->filho_eqr == no){
            pai_no->filho_eqr = NULL;
        }
    }

    //remover raiz
    if(pai_no == NULL){
        No *menor_drt = menor((*node)->filho_drt);

        if(menor_drt != NULL){
            No *pai_menor = buscar_pai((*node), menor_drt->num);
            pai_menor->filho_eqr = NULL;
            menor_drt->filho_drt = (*node)->filho_drt;
            menor_drt->filho_eqr = (*node)->filho_eqr;
            (*node) = menor_drt;
        }else{
            printf("Erro: menor a direita nao encontrado!!!");
        }
    }

    //remover nó com dois filhos
}

int main()
{
    int n = 10;
    No *raiz = NULL;

    // for (int i = 0; i < n; i++)
    // {
    //     int num = rand() % 100;
    //     No *novo_no = criar_no(num);
    //     if (i == 0)
    //     {
    //         raiz = novo_no;
    //         printf("Raiz: %d\n", raiz->num);
    //     }
    //     else
    //     {
    //         inserir_no(raiz, novo_no);
    //     }
    // }

    
    int numeros[] = {5,4,7,2,3,1,6,8,10,9};
    for (int i = 0; i < n; i++)
    {
        No *novo_no = criar_no(numeros[i]);
        if (i == 0)
        {
            raiz = novo_no;
            printf("Raiz: %d\n", raiz->num);
        }
        else
        {
            inserir_no(raiz, novo_no);
        }
    }

    imprime_arvore(raiz, 0);

    remover_no(&raiz, 5);

    imprime_arvore(raiz, 0);

    return 0;
}