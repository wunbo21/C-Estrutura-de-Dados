/*
  Data: 22/04/2020
  Descrição: Esse programa tem a função de verificar se uma árvore é cheia
  Código em C
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  char info;
  struct arv* esq;
  struct arv* dir;
}Arv;

// ********************** //
// DECLARAÇÃO DAS FUNÇÕES //
// ********************** //
Arv* cria_arv_vazia();
Arv* arv_cria(char aux, Arv* esq, Arv* dir);
int verifica_arv_vazia(Arv* a);
int verifica_arv_cheia(Arv* a);
int verifica_arv_folha(Arv* a);
void imprime_arv(Arv* a);

// *********** //
// FUNÇÃO MAIN //
// *********** //
int main() {

  Arv* a;

  a = cria_arv_vazia();

  Arv* a13 = arv_cria('Z', cria_arv_vazia(), cria_arv_vazia());
  //Arv* a12 = arv_cria('J', cria_arv_vazia(), cria_arv_vazia());
  Arv* a11 = arv_cria('I', cria_arv_vazia(), /*a12*/cria_arv_vazia());
  Arv* a10 = arv_cria('M', cria_arv_vazia(), cria_arv_vazia());
  Arv* a9 = arv_cria('H', a10, a11);
  //Arv* a8 = arv_cria('L', cria_arv_vazia(), cria_arv_vazia());
  Arv* a7 = arv_cria('D', a9, cria_arv_vazia());
  Arv* a6 = arv_cria('G', cria_arv_vazia(), cria_arv_vazia());
  Arv* a5 = arv_cria('F', cria_arv_vazia(), cria_arv_vazia());
  Arv* a4 = arv_cria('K', cria_arv_vazia(), /*a8*/cria_arv_vazia());
  Arv* a3 = arv_cria('C', a6, a7);
  Arv* a2 = arv_cria('E', a4, a5);
  Arv* a1 = arv_cria('B', a2, a3); 
	a = arv_cria('A', a1, a13);

  printf("Arvore: \n");
  imprime_arv(a);

  if(verifica_arv_cheia(a))
    printf("\n\nArvore e cheia");
  else
    printf("\n\nArvore nao e cheia");
  

  return 0;
}

// ******* //
// FUNÇÕES //
// ******* //
Arv* cria_arv_vazia(){
  return NULL;
}

Arv* arv_cria(char aux, Arv* esq, Arv* dir){
  Arv* p = (Arv*)malloc(sizeof(Arv));
  p->info = aux;
  p->esq = esq;
  p->dir = dir;
}

int verifica_arv_vazia(Arv* a){
  return a == NULL;
}

void imprime_arv(Arv* a){
  if(!verifica_arv_vazia(a)){
    printf("%c", a->info);
    imprime_arv(a->esq);
    imprime_arv(a->dir);
  }
}

int verifica_arv_cheia(Arv* a){
  if(verifica_arv_vazia(a))
    return 1;
  else{
    if(!verifica_arv_folha(a)){
      return (a->esq != NULL) && (a->dir != NULL);
    }
  }
}

int verifica_arv_folha(Arv* a){
  if(!verifica_arv_vazia(a)){
    return (a->esq == NULL) && (a->dir == NULL);
  }
}