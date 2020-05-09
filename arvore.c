#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
  int info;
  struct arvore* gal_esq;
  struct arvore* gal_dir;
}Arv;

Arv* arv_cria_vazia();
Arv* arv_cria(int n, Arv* gal_esq, Arv* gal_dir);
int arv_vazia(Arv* a);
void arv_imprime(Arv* a);
void arv_imprime_folha(Arv* a);
int arv_conta_par(Arv* a);

int main(){

  Arv* a;
  int total_par = 0;

  a = arv_cria_vazia();

  Arv* a1 = arv_cria(4, arv_cria_vazia(), arv_cria_vazia()); /* Criando sub Arvore d */
	Arv* a2 = arv_cria(2, arv_cria_vazia(), a1); /* Criando sub Arvore b */
	Arv* a3 = arv_cria(5, arv_cria_vazia(), arv_cria_vazia()); /* Criando sub Arvore e */
	Arv* a4 = arv_cria(6, arv_cria_vazia(), arv_cria_vazia()); /* Criando sub Arvore f */
	Arv* a5 = arv_cria(3, a3, a4); /* Criando sub Arvore c */
	a = arv_cria(1, a2, a5); /* Arvore Raiz a */

  /*a = arv_cria(1,
		arv_cria(2,
			arv_cria_vazia(),
			arv_cria(4, arv_cria_vazia(), arv_cria_vazia())
		),
		arv_cria(3,
			arv_cria(5, arv_cria_vazia(), arv_cria_vazia()),
			arv_cria(6, arv_cria_vazia(), arv_cria_vazia())
		)
	);*/

  printf("Valores dentro da arvore:\n");
  arv_imprime(a);

  printf("\n\nFolhas da arvore:\n");
  arv_imprime_folha(a);

  printf("\n\nA quantidade de numeros pares e:\n");
  total_par = arv_conta_par(a);
  printf("%d", total_par);

  return 0;
}

Arv* arv_cria_vazia(){
  return NULL;
}

Arv* arv_cria(int n, Arv* gal_esq, Arv* gal_dir){
  Arv* p = (Arv*)malloc(sizeof(Arv));
  p->info = n;
  p->gal_esq = gal_esq;
  p->gal_dir = gal_dir;
  return p;
}

int arv_vazia(Arv* a){
  return a == NULL;
}

void arv_imprime(Arv* a){
  if(!arv_vazia(a)){
    printf("%d", a->info);
    arv_imprime(a->gal_esq);
    arv_imprime(a->gal_dir);
  }
}

void arv_imprime_folha(Arv* a){
  if(!arv_vazia(a)){
    if( (a->gal_esq == NULL) && (a->gal_dir == NULL) ){
      printf("%d", a->info);
    }
    arv_imprime_folha(a->gal_esq);
    arv_imprime_folha(a->gal_dir);
  }
}

int arv_conta_par(Arv* a){
  int cont = 0;
  if(arv_vazia(a)) 
    return 0;
  else{
    if(a->info % 2 == 0)  
      cont = 1;
    else
      cont = 0; 
  }
  return cont + arv_conta_par(a->gal_esq) + arv_conta_par(a->gal_dir);
}