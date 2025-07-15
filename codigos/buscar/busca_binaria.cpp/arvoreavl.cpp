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

void imprime_arvore(No *node, int tab)
{
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

No *buscar(No *node, int num)
{
    if (node == nullptr)
    {
        printf("Item não encontrado\n");
        return nullptr;
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
    if (node == nullptr)
        return nullptr;

    if (node->filho_drt != nullptr && node->filho_drt->num == num)
        return node;
    if (node->filho_eqr != nullptr && node->filho_eqr->num == num)
        return node;

    if (num > node->num)
    {
        return buscar_pai(node->filho_drt, num);
    }
    else
    {
        return buscar_pai(node->filho_eqr, num);
    }
}

bool eh_folha(No *node)
{
    if (node == nullptr)
        return false;

    if (node->filho_eqr == nullptr && node->filho_drt == nullptr)
        return true;
    return false;
}

int qntNo(No *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return (1 + qntNo(node->filho_drt) + qntNo(node->filho_eqr));
}

int altura(No *node)
{
    if (node == NULL)
        return -1;
    return (1 + fmax(altura(node->filho_eqr), altura(node->filho_drt)));
}

int fb(No *node)
{
    if (node == nullptr)
        return 0;
    return (altura(node->filho_eqr) - altura(node->filho_drt));
}

void rs_esq(No **raiz, No *node)
{
    if (node == nullptr || node->filho_drt == nullptr)
        return;

    No *filho_drt = node->filho_drt;
    node->filho_drt = filho_drt->filho_eqr;
    filho_drt->filho_eqr = node;

    No *pai_node = buscar_pai(*raiz, node->num);
    if (pai_node == nullptr)
    {
        *raiz = filho_drt;
    }
    else if (pai_node->filho_eqr == node)
    {
        pai_node->filho_eqr = filho_drt;
    }
    else
    {
        pai_node->filho_drt = filho_drt;
    }
}

void rs_drt(No **raiz, No *node)
{
    if (node == nullptr || node->filho_eqr == nullptr)
        return;

    No *filho_eqr = node->filho_eqr;
    node->filho_eqr = filho_eqr->filho_drt;
    filho_eqr->filho_drt = node;

    No *pai_node = buscar_pai(*raiz, node->num);
    if (pai_node == nullptr)
    {
        *raiz = filho_eqr;
    }
    else if (pai_node->filho_drt == node)
    {
        pai_node->filho_drt = filho_eqr;
    }
    else
    {
        pai_node->filho_eqr = filho_eqr;
    }
}

void remover_no(No **raiz, int num)
{
    if (*raiz == nullptr)
        return;

    No *no_remover = buscar(*raiz, num);
    if (no_remover == nullptr)
    {
        printf("Numero %d nao encontrado para remocao.\n", num);
        return;
    }

    No *pai_no = buscar_pai(*raiz, num);

    // Caso 1: Nó é folha
    if (eh_folha(no_remover))
    {
        if (pai_no == nullptr)
        { // nó é raiz
            *raiz = nullptr;
        }
        else if (pai_no->filho_eqr == no_remover)
        {
            pai_no->filho_eqr = nullptr;
        }
        else
        {
            pai_no->filho_drt = nullptr;
        }
        delete no_remover;
        return;
    }

    // Caso 2: Nó tem apenas um filho
    if (no_remover->filho_eqr == nullptr || no_remover->filho_drt == nullptr)
    {
        No *filho = (no_remover->filho_eqr != nullptr) ? no_remover->filho_eqr : no_remover->filho_drt;

        if (pai_no == nullptr)
        { // nó é raiz
            *raiz = filho;
        }
        else if (pai_no->filho_eqr == no_remover)
        {
            pai_no->filho_eqr = filho;
        }
        else
        {
            pai_no->filho_drt = filho;
        }
        delete no_remover;
        return;
    }

    // Caso 3: Nó tem dois filhos
    if (no_remover->filho_eqr != nullptr && no_remover->filho_drt != nullptr)
    {
        No *sucessor = menor(no_remover->filho_drt);
        int valor_sucessor = sucessor->num;

        // Remove o sucessor recursivamente
        remover_no(raiz, valor_sucessor);

        // Substitui o valor do nó a ser removido pelo valor do sucessor
        no_remover->num = valor_sucessor;
    }
}

void balancear(No **raiz, No *node)
{
    if (node == NULL)
        return;

    if (fb(node) == 0)
        return;

    if (fb(node) == -2)
    { // sub direita maior que sub esquerda
        if (fb(node->filho_drt) == 1)
        { // caso de rotação dupla
            rs_drt(raiz, node->filho_drt);
        }
        rs_esq(raiz, node);
        return;
    }

    if (fb(node) == 2)
    { // sub esquerda maior que sub direita
        if (fb(node->filho_eqr) == -1)
        { // caso de rotação dupla
            rs_esq(raiz, node->filho_eqr);
        }
        rs_drt(raiz, node);
    }
    balancear(raiz, node->filho_eqr);
    balancear(raiz, node->filho_drt);
}

void inserir_no(No **node, No *novo_no)
{
    if (*node == nullptr || novo_no == nullptr)
    {
        printf("Erro\n");
        return;
    }

    if ((*node)->num == novo_no->num)
    {
        printf("Numero ja existe\n");
        return;
    }

    if (novo_no->num <= (*node)->num)
    {
        if ((*node)->filho_eqr == nullptr)
        {
            (*node)->filho_eqr = novo_no;
        }
        else
        {
            inserir_no(&(*node)->filho_eqr, novo_no);
        }
    }
    else
    {
        if ((*node)->filho_drt == nullptr)
        {
            (*node)->filho_drt = novo_no;
        }
        else
        {
            inserir_no(&(*node)->filho_drt, novo_no);
        }
    }
}

int main()
{
    int num;
    No *raiz = nullptr;
    bool run = true;

    while (run)
    {
        printf("Arvore AVL\n");
        int opcao;
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Buscar\n");
        printf("3. Imprimir\n");
        printf("4. Remover\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Inserir
            printf("Digite um numero para inserir: ");
            scanf("%d", &num);
            if (raiz == nullptr)
            {
                raiz = criar_no(num);
            }
            else
            {
                inserir_no(&raiz, criar_no(num));
            }

            balancear(&raiz, raiz);
            printf("\nNumero %d inserido com sucesso.\n", num);

            break;
        case 2: // Buscar
            printf("Digite um numero para buscar: ");
            scanf("%d", &num);
            {
                No *resultado = buscar(raiz, num);
                if (resultado != nullptr)
                {
                    printf("Numero %d encontrado.\n", resultado->num);
                }
                else
                {
                    printf("Numero %d nao encontrado.\n", num);
                }
            }
            break;
        case 3: // Imprimir
            imprime_arvore(raiz, 0);
            break;
        case 4: // Remover
            printf("Digite um numero para remover: ");
            scanf("%d", &num);
            remover_no(&raiz, num);
            printf("Numero %d removido com sucesso.\n", num);
            break;
        case 5: // Sair
            run = false;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
