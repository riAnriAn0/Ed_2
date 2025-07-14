#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
    struct No *node;
    struct No *filho_esq;
    struct No *filho_drt;
    int cor;
    int num;
}No;

typedef struct arvorevc{
    No *raiz;
    int tam;  
};

No *criar_No(){
    No *novo_no = new No();

    if(novo_no) return NULL;

    novo_no->cor = 0;
    novo_no->filho_drt = NULL;
    novo_no->filho_esq = NULL;
    novo_no->node = NULL;
    novo_no->num = (rand() % 100);

    return novo_no;
}