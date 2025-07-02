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

    if(novo_no == NULL){
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
    if(node == NULL || novo_no == NULL){
        printf("Erro\n");
        return;
    }

    if(node->num == novo_no->num){
        printf("Numero ja existe\n");
        return;
    }

    if(novo_no->num <= node->num){   // Se o novo numero for menor ou igual, insere na subárvore esquerda
        if(node->filho_eqr == NULL){
            node->filho_eqr = novo_no;
        } else {
            inserir_no(node->filho_eqr, novo_no);
        }
    } else {                        // Se o novo numero for maior, insere na subárvore direita
        if(node->filho_drt == NULL){
            node->filho_drt = novo_no;
        } else {
            inserir_no(node->filho_drt, novo_no);
        }
    }

}

void imprime_arvore(No *node, int tab)
{
    if(node == NULL){
        return;
    }

    imprime_arvore(node->filho_eqr, tab + 1);

    for(int i = 0; i < tab; i++){
        printf("    ");
    }
    printf("%d\n", node->num);

    imprime_arvore(node->filho_drt, tab + 1);
}

No *buscar(No *node,int num){
    if(node == NULL){
        printf("Arvore vazian\n");
        return NULL;
    }

    if(node->num == num)
    {
        return node;
    }else if(num < node->num)
    {
        return buscar(node->filho_eqr, num);

    }else
    {
        return buscar(node->filho_drt, num);
    }

    return NULL;
    
}

int main(int argc, char const *argv[])
{
    int n = 20;
    No *raiz = NULL;

    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100; 
        No *novo_no = criar_no(num);
        if (i == 0) {
            raiz = novo_no; 
            printf("Raiz: %d\n", raiz->num);
        } else {
            inserir_no(raiz, novo_no);
        }
    }
    
    imprime_arvore(raiz, 0);
    
    No *no_buscado = buscar(raiz, 5);

    printf("NO buscado: ");
    if (no_buscado != NULL) {
        printf("%d\n", no_buscado->num);
        printf("filiho_eqr: %d\n", no_buscado->filho_eqr ? no_buscado->filho_eqr->num : NULL);
        printf("filiho_drt: %d\n", no_buscado->filho_drt ? no_buscado->filho_drt->num : NULL);
    } else {
        printf("Nao encontrado\n");
    }

    return 0;
}