#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arv{
  int info;
  struct arv* pai;
  struct arv* esq;
  struct arv* dir;
}Arv;

Arv* cria_vazia();
int verifica_vazia(Arv* a);
Arv* abb_insere_iterativa(Arv* a, int n);
Arv* cria_filho(Arv* a, int val);
void imprime_arvore(Arv* a);

int main(){

  Arv* a;

  a = cria_vazia();

  a = abb_insere_iterativa(a, 6);
  a = abb_insere_iterativa(a, 4);
  a = abb_insere_iterativa(a, 5);
  a = abb_insere_iterativa(a, 8);

  imprime_arvore(a);

  return 0;
}

Arv* cria_vazia(){
  return NULL;
}

int verifica_vazia(Arv* a){
  return a == NULL;
}

Arv* abb_insere_iterativa(Arv* a, int n){
  Arv* filho = cria_filho(cria_vazia(), n);
  
  if(a == NULL)
    return filho;

  Arv* pai = cria_vazia();
  Arv* aux = a;

  while(aux != NULL){
    pai = aux;
    aux = (n < aux->info) ? aux->esq : aux->dir;
  }

  filho->pai = pai;

  if(n < pai->info)
    pai->esq = filho;
  else 
    pai->dir = filho;  
      
  return a;  
}

Arv* cria_filho(Arv* a, int val){
  Arv* no = (Arv*) malloc(sizeof(Arv));
  no->pai = a;
  no->info = val;
  no->esq = cria_vazia();
  no->dir = cria_vazia();
  return no;
}

void imprime_arvore(Arv* a){
  if(!verifica_vazia(a)){
    printf("%d", a->info);
    imprime_arvore(a->esq);
    imprime_arvore(a->dir);
  }
}