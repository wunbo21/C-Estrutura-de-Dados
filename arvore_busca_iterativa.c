#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int info;
  struct arv* esq;
  struct arv* dir;
}Arv;

// ********************** //
// Declaração das funções //
// ********************** //
Arv* cria_arv_vazia();
Arv* cria_arv(int n, Arv* esq, Arv* dir);
Arv* abb_busca_iterativa(Arv* a, int n);
int verifica_arv_vazia(Arv* a);
void imprime_arv(Arv* a);

int main() {

  Arv* a;
  Arv* k;
  int valor = 0;

  a = cria_arv_vazia();
  k = cria_arv_vazia();

  Arv* a9 = cria_arv(48, cria_arv_vazia(), cria_arv_vazia());
  Arv* a8 = cria_arv(45, cria_arv_vazia(), cria_arv_vazia());
  Arv* a7 = cria_arv(22, cria_arv_vazia(), cria_arv_vazia());
  Arv* a6 = cria_arv(13, cria_arv_vazia(), cria_arv_vazia());
  Arv* a5 = cria_arv(47, a8, a9);
  Arv* a4 = cria_arv(18, cria_arv_vazia(), a7);
  Arv* a3 = cria_arv(15, a6, cria_arv_vazia());
  Arv* a2 = cria_arv(38, cria_arv_vazia(), a5);
  Arv* a1 = cria_arv(17, a3, a4);
  a = cria_arv(23, a1, a2);

  printf("Imprimindo arvore recursivamente:\n");
  imprime_arv(a);

  printf("\n\nDigite um valora para ver se existe na arvore: ");
    scanf("%d", &valor);
  
  k = abb_busca_iterativa(a, valor);

  if(k != NULL)
    printf("Valor %d encontrado\n\n", k->info);
  else
    printf("Valor nao encontrado.\n\n");

  return 0;
}

// ******* //
// Funções //
// ******* //
Arv* cria_arv_vazia(){
  return NULL;
}

int verifica_arv_vazia(Arv* a){
  return a == NULL;
}

Arv* cria_arv(int n, Arv* esq, Arv* dir){
  Arv* p = (Arv*)malloc(sizeof(Arv));
  p->info = n;
  p->esq = esq;
  p->dir = dir;
}

void imprime_arv(Arv* a){
  if(!verifica_arv_vazia(a)){
    printf("%d - ", a->info);
    imprime_arv(a->esq);
    imprime_arv(a->dir);
  }
}

Arv* abb_busca_iterativa(Arv* a, int n){
  while(a != NULL && a->info != n){
    if(n < a->info)
      a = a->esq;
    else
      a = a->dir;
  }
  return a;
}