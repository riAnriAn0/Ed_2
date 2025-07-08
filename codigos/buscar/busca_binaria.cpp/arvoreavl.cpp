#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

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
    if (node == NULL || node->num == num)
        return NULL;

    if (node->filho_drt->num == num)
        return node;
    if (node->filho_eqr->num == num)
        return node;

    if (num > node->filho_drt->num)
    {
        return buscar_pai(node, node->filho_drt->num);
    }

    if (num < node->filho_eqr->num)
    {
        return buscar_pai(node, node->filho_eqr->num);
    }

    return NULL;
}

bool eh_folha(No *node)
{
    if(node == NULL) return false;

    if(node->filho_eqr == NULL && node->filho_drt == NULL)return true;
}


int qntNo(No *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        1 + qntNo(node->filho_drt) + qntNo(node->filho_eqr);
    }
    return 0;
}

void rotacao_simples_esq(No *raiz){
    if(raiz == NULL) return;    
    
    No *pai_raiz = buscar_pai(raiz, raiz->num);
    pai_raiz->filho_drt = raiz->filho_drt;
}

int altura(No *node)
{
    if (node == NULL) return 0;

    return 1 + fmax(altura(node->filho_eqr), altura(node->filho_drt));
}

int main()
{
    int n = 20;
    No *raiz = NULL;

    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        No *novo_no = criar_no(num);
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

    No *no_buscado = buscar(raiz, 5);

    printf("NO buscado: ");
    if (no_buscado != NULL)
    {
        printf("%d\n", no_buscado->num);
        printf("filiho_eqr: %d\n", no_buscado->filho_eqr ? no_buscado->filho_eqr->num : NULL);
        printf("filiho_drt: %d\n", no_buscado->filho_drt ? no_buscado->filho_drt->num : NULL);
    }
    else
    {
        printf("Nao encontrado\n");
    }

    printf("qnt elemetos: ");
    int qnt = qntNo(raiz);
    printf("%d", qnt);

    return 0;
}
