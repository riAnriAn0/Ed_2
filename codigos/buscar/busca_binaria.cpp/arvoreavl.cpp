#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

typedef struct node
{
    int num;
    int altura;
    struct node *filho_eqr;
    struct node *filho_drt;
} No;

No *criar_no(int num)
{
    No *novo_no = new No;

    if (novo_no == nullptr)
    {
        printf("Erro ao alocar memoria\n");
        return nullptr;
    }
    novo_no->num = num;
    novo_no->filho_eqr = nullptr;
    novo_no->filho_drt = nullptr;
    return novo_no;
}

void inserir_no(No *node, No *novo_no)
{
    if (node == nullptr || novo_no == nullptr){
        printf("Erro\n");
        return;
    }

    if (node->num == novo_no->num){
        printf("Numero ja existe\n");
        return;
    }

    if (novo_no->num <= node->num){ 
        if (node->filho_eqr == nullptr){
            node->filho_eqr = novo_no;
        }else{
            inserir_no(node->filho_eqr, novo_no);
        }
    }else{ 
        if (node->filho_drt == nullptr){
            node->filho_drt = novo_no;
        }else{
            inserir_no(node->filho_drt, novo_no);
        }
    }
}


void imprime_arvore(No *node, int tab){
    if (node == nullptr)
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

No *buscar(No *node, int num){
    if (node == nullptr){
        printf("Arvore vazian\n");
        return nullptr;
    }

    if (node->num == num){
        return node;
    }
    else if (num < node->num){
        return buscar(node->filho_eqr, num);
    }
    else{
        return buscar(node->filho_drt, num);
    }

    return nullptr;
}

No *maior(No *node)
{
    if (node == nullptr)
        return nullptr;
    if (node->filho_drt == nullptr)
        return node;
    return maior(node->filho_drt);
}

No *menor(No *node)
{
    if (node == nullptr)
        return nullptr;
    if (node->filho_eqr == nullptr)
        return node;
    return menor(node->filho_eqr);
}

No *buscar_pai(No *node, int num)
{
    if(node == nullptr) return nullptr;

    if(node->filho_drt != nullptr && node->filho_drt-> num == num) return node;
    if(node->filho_eqr != nullptr && node->filho_eqr-> num == num) return node;

    if (num > node->num){
        return buscar_pai(node->filho_drt, num);
    }else{
        return buscar_pai(node->filho_eqr, num);
    }
}


bool eh_folha(No *node)
{
    if(node == nullptr) return false;

    if(node->filho_eqr == nullptr && node->filho_drt == nullptr)return true;
}


int qntNo(No *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return (1 + qntNo(node->filho_drt) + qntNo(node->filho_eqr));
}

int altura(No *node){
    if (node == NULL) return -1;
    return (1 + fmax(altura(node->filho_eqr), altura(node->filho_drt)));
}

int fb(No *node){
    if (node == nullptr) return NULL;
    return (altura(node->filho_eqr) - altura(node->filho_drt));
}

void rs_esq(No **raiz, No *node) {
    if (node == nullptr || node->filho_drt == nullptr) return;

    No *filho_drt = node->filho_drt;
    node->filho_drt = filho_drt->filho_eqr;
    filho_drt->filho_eqr = node;

    No *pai_node = buscar_pai(*raiz, node->num);
    if (pai_node == nullptr) {
        *raiz = filho_drt;
    } else if (pai_node->filho_eqr == node) {
        pai_node->filho_eqr = filho_drt;
    } else {
        pai_node->filho_drt = filho_drt;
    }
}

void rs_drt(No **raiz, No *node) {
    if (node == nullptr || node->filho_eqr == nullptr) return;

    No *filho_eqr = node->filho_eqr;
    node->filho_eqr = filho_eqr->filho_drt;
    filho_eqr->filho_drt = node;

    No *pai_node = buscar_pai(*raiz, node->num);
    if (pai_node == nullptr) {
        *raiz = filho_eqr;
    } else if (pai_node->filho_drt == node) {
        pai_node->filho_drt = filho_eqr;
    } else {
        pai_node->filho_eqr = filho_eqr;
    }
}


int main()
{
    int n = 9;
    No *raiz = nullptr;

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

    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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


    printf("Arvore: \n");
    imprime_arvore(raiz, 0);

    printf("FB 4: %d", fb(buscar(raiz,4)));
   
    return 0;
}
