#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
}Arv;

Arv* ab_insere(Arv* a, int n);
Arv* cria_arv_vazia();
int verifica_ab_vazia(Arv* a);
void imprime(Arv* a);
void imprime_crescente(Arv* a);
void imprime_decrescente(Arv* a);

int main() {

  Arv* a;
  int i = 0, aux = 0;

  a = cria_arv_vazia();

  srand(time(NULL));

  for(i = 0; i < 5; i++){
    aux = rand() % 100;
    a = ab_insere(a, aux);
  }

  printf("Imprimindo seguinte a ordem da arvore:\n");
  imprime(a);

  printf("\n\nImprimindo em ordem crescente:\n");
  imprime_crescente(a);

  printf("\n\nImprimindo em ordem decrescente:\n");
  imprime_decrescente(a);

  return 0;
}

int verifica_ab_vazia(Arv* a) {
  return a == NULL;
}

Arv* cria_arv_vazia(){
  return NULL;
}

Arv* ab_insere(Arv* a, int n) {
  Arv* aux = (Arv*) malloc(sizeof(Arv));
  aux->info = n;
  aux->esq = cria_arv_vazia();
  aux->dir = cria_arv_vazia();

  if(verifica_ab_vazia(a))
    return aux;
  else {
    Arv* antes = cria_arv_vazia();
    Arv* atual = a;
    while(atual != NULL){
      antes = atual;
      atual = (n < atual->info)? atual->esq : atual->dir;
    }
    if(n < antes->info)
      antes->esq = aux;
    else // n > antes->info
      antes->dir = aux;
    return a;
  }
}

void imprime(Arv* a){
  if(!verifica_ab_vazia(a)){
    printf("%d - ", a->info);
    imprime(a->esq);
    imprime(a->dir);
  }
}

void imprime_crescente(Arv* a){
  if(!verifica_ab_vazia(a)){
    imprime_crescente(a->esq);
    printf("%d - ", a->info);
    imprime_crescente(a->dir);
  }
}

void imprime_decrescente(Arv* a){
  if(!verifica_ab_vazia(a)){
    imprime_decrescente(a->dir);
    printf("%d - ", a->info);
    imprime_decrescente(a->esq);
  }
}