#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arv{
  int info;
  struct arv* esq;
  struct arv* dir;
}Arv;

// *********************** //
// Declaraçãos das funções //
// *********************** //
Arv* cria_arv_vazia();
Arv* ab_insere_rec(Arv* a, int n);
int verifica_ab_vazia(Arv* a);
void imprime_arvore(Arv* a);

// **************** //
// Função Principal //
// **************** //
int main() {

  Arv* a;

  a = cria_arv_vazia();

  a = ab_insere_rec(a, 6);
  a = ab_insere_rec(a, 4);
  a = ab_insere_rec(a, 5);
  a = ab_insere_rec(a, 8);

  printf("Imprimir arvore:\n");
  imprime_arvore(a);

  return 0;
}

// ******* //
// Funções //
// ******* //

// Cria uma arvore vazia
Arv* cria_arv_vazia(){
  return NULL;
}

// Verifica se a arvore e vazia
int verifica_ab_vazia(Arv* a){
  return a == NULL;
}

// Insere valores na arvore recursivamente
Arv* ab_insere_rec(Arv* a, int n){
  if(a == NULL){
    a = (Arv*) malloc(sizeof(Arv));
    a->info = n;
    a->esq = cria_arv_vazia();
    a->dir = cria_arv_vazia();
  }
  else if(n < a->info)
    a->esq = ab_insere_rec(a->esq, n);
  else /* n > a->info */
    a->dir = ab_insere_rec(a->dir, n);
  return a;
}

void imprime_arvore(Arv* a){
  if(!verifica_ab_vazia(a)){
    printf("%d", a->info);
    imprime_arvore(a->esq);
    imprime_arvore(a->dir);
  }
}