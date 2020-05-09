#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int info;
  struct arv* pai;
  struct arv* esq;
  struct arv* dir;
}Arv;

Arv* cria_vazia();
Arv* abb_insere_recursiva(Arv* a, int n);
Arv* cria_filho(Arv* a, int val);
int verifica_vazia(Arv* a);
void imprime_arvore(Arv* a);

int main(){

  Arv* a;

  a = cria_vazia();

  a = abb_insere_recursiva(a, 6);
  a = abb_insere_recursiva(a, 4);
  a = abb_insere_recursiva(a, 5);
  a = abb_insere_recursiva(a, 8);

  imprime_arvore(a);

  return 0;
}

Arv* cria_vazia(){
  return NULL;
}

int verifica_vazia(Arv* a){
  return a == NULL;
}

Arv* cria_filho(Arv* a, int val){
  Arv* no = (Arv*)malloc(sizeof(Arv));
  no->pai = a;
  no->info = val;
  no->esq = cria_vazia();
  no->dir = cria_vazia();
  return no;
}

Arv* abb_insere_recursiva(Arv* a, int n){
  if(verifica_vazia(a))
    return cria_filho(a, n);
  else if(n < a->info){
    if(verifica_vazia(a->esq))
      a->esq = cria_filho(a, n);
    else  
      a->esq = abb_insere_recursiva(a->esq, n);
  }
  else if(n > a->info){
    if(verifica_vazia(a->dir))
      a->dir = cria_filho(a, n);
    else
      a->dir = abb_insere_recursiva(a->dir, n);
  }
  
  return a;
}

void imprime_arvore(Arv* a){
  if(!verifica_vazia(a)){
    printf("%d", a->info);
    imprime_arvore(a->esq);
    imprime_arvore(a->dir);
  }
}