#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  char matricula[10];
  float nota = 0;
} aluno;

typedef struct elem {
  aluno *aluno = NULL;
  struct elem *prox = NULL;
} elemento;

typedef struct {
  elemento *inicio = NULL;
  elemento *fim = NULL;
  int tamanho = 0;
} lista;

void imprimir(lista *l) {
  elemento *aux = l->inicio;
  printf("Lista com %d alunos.\n", l->tamanho);
  while (aux != NULL) {
    printf("%s -> ", aux->aluno->nome);
    aux = aux->prox;
  }
  printf("NULL\n\n");
}

void inserir_inicio(lista *l, aluno *a) {
  elemento *novo = new elemento;
  novo->aluno = a;
  if (l->tamanho == 0) {
    l->inicio = novo;
    l->fim = novo;
  } else {
    novo->prox = l->inicio;
    l->inicio = novo;
  }
  l->tamanho++;
}

void inserir_fim(lista *l, aluno *a) {
  elemento *novo = new elemento;
  novo->aluno = a;
  if (l->tamanho == 0) {
    l->inicio = novo;
    l->fim = novo;
  } else {
    l->fim->prox = novo;
    l->fim = novo;
  }
  l->tamanho++;
}

elemento *busca_anterior(lista *l, elemento *e) {
  if ((l->tamanho == 0) || (e == l->inicio)) {
    return NULL;
  }

  elemento *aux = l->inicio;
  while (aux != NULL) {
    if (aux->prox == e) {
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void troca(lista *l, elemento *e1, elemento *e2) {
  // Casos inválidos
  if (e1 == NULL || e2 == NULL || e1 == e2) return;

  // Caso e2 -> e1 (vizinhos invertidos)
  if (e2->prox == e1) {  // inverte os ponteiros e1 e e2
    elemento *tmp = e1;
    e1 = e2;
    e2 = tmp;
  }

  elemento *ant1 = busca_anterior(l, e1);
  elemento *ant2 = busca_anterior(l, e2);

  // Caso e1 -> e2 (vizinhos)
  if (e1->prox == e2) {
    if (ant1 == NULL) {  // Verifica se e1 é o primeiro da lista
      l->inicio = e2;
    } else {
      ant1->prox = e2;
    }
    e1->prox = e2->prox;
    e2->prox = e1;

    if (l->fim == e2) {  // Verifica se e2 é o último da lista
      l->fim = e1;
    }
    return;
  }

  if (ant1 == NULL) {  // Verifica se e1 é o primeiro da lista
    l->inicio = e2;
  } else {
    ant1->prox = e2;
  }

  if (ant2 == NULL) {  // Verifica se e2 é o primeiro da lista
    l->inicio = e1;
  } else {
    ant2->prox = e1;
  }

  elemento *prox1 = e1->prox;
  elemento *prox2 = e2->prox;

  e1->prox = prox2;
  e2->prox = prox1;

  if (prox2 == NULL) {  // Verifica se e2 é o último da lista
    l->fim = e1;
  }

  if (prox1 == NULL) {  // Verifica se e2 é o último da lista
    l->fim = e2;
  }
}

aluno *criar_aluno(const char *nome) {
  aluno *a = new aluno;
  strcpy(a->nome, nome);
  strcpy(a->matricula, "000000");
  a->nota = 0.0;
  return a;
}

elemento *buscar_por_nome(lista *l, const char *nome) {
  elemento *aux = l->inicio;
  while (aux != NULL) {
    if (strcmp(aux->aluno->nome, nome) == 0) return aux;
    aux = aux->prox;
  }
  return NULL;
}

int main(int argc, char const *argv[]) {
  aluno a1;
  strcpy(a1.nome, "A1");

  aluno a2;
  strcpy(a2.nome, "A2");

  aluno a3;
  strcpy(a3.nome, "A3");

  lista lista_alunos;

  inserir_fim(&lista_alunos, &a1);
  inserir_fim(&lista_alunos, &a2);
  inserir_fim(&lista_alunos, &a3);
  imprimir(&lista_alunos);

  elemento *e1 = lista_alunos.inicio;
  elemento *e2 = lista_alunos.fim;
  troca(&lista_alunos, e1, e2);
  imprimir(&lista_alunos);

  return 0;
}
