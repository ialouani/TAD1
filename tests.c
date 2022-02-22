#include "./liste_chainee.h"
#include<assert.h>

#include <stdio.h>
#include<stdlib.h> //macro EXIT_SUCCESS.

struct block{
  int data;
  struct block* next;
};


static void test_liste__vide(){
  Liste l=liste_vide();
  assert(l->tete==NULL);
  assert(liste__est_vide(l)==1);
free(l);
  printf("OK pour Liste liste_vide() &+:enum Bool liste__est_vide .\n");
}

static void test_add__head(){
  Liste l=liste_vide();
  add__head(l,1);
  add__head(l,2);
  add__head(l,3);
 assert(l->tete->data==3);
 assert(l->tete->next->data==2);
assert(l->tete->next->next->data==1);
assert(l->tete->next->next->next==l->tete->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
  printf("OK pour test__add_head().!!\n");
}
static void test_add__tail(){
  Liste l=liste_vide();
  add__tail(l,1);
  add__tail(l,2);
  add__tail(l,3);
  assert(l->tete->data==1);
  assert(l->tete->next->data==2);
  assert(l->tete->next->next->data==3);
  assert(l->tete->next->next->next==l->tete->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
  printf("OK pour test__add_tail().!!\n");
}

static void test_remove__head(){
  Liste l=liste_vide();
  add__tail(l,1);
  add__tail(l,2);
  add__tail(l,3);
  assert(l->tete->data==1);
  assert(l->tete->next->data==2);
  assert(l->tete->next->next->data==3);
  assert(l->tete->next->next->next==l->tete->next->next);
remove__head(l);
remove__head(l);
assert(l->tete->data==3);
assert(l->tete->next==l->tete);
free(l->tete);
free(l);
  printf("OK pour test__remove_head().!!\n");
}

static void test_remove__tail(){
  Liste l=liste_vide();
  add__head(l,1);
  add__head(l,2);
  add__head(l,3);
  assert(l->tete->data==3);
  assert(l->tete->next->data==2);
  assert(l->tete->next->next->data==1);
  assert(l->tete->next->next->next==l->tete->next->next);
remove__tail(l);
remove__tail(l);
assert(l->tete->data==3);
assert(l->tete->next==l->tete);
free(l->tete);
free(l);
  printf("OK pour test__remove_tail().!!\n");
}

static void test_LEN(){
 Liste l=liste_vide();
  add__head(l,1);
  add__head(l,2);
  add__head(l,3);
assert(len(l)==3);
remove__tail(l);
remove__head(l);
assert(l->tete->data==2 && l->tete->next==l->tete);
assert(len(l)==1);
remove__head(l);assert(len(l)==0);
free(l);
printf("OK pour test_LEN.//\n");
}

static void test_adding_after(){
Liste l=liste_vide();
  add__head(l,1);
  add__head(l,2);
  add__head(l,3);
add__head(l,4);
struct block* after=l->tete->next->next;
liste__add_after(l,after,5);
 assert(l->tete->data==4);
  assert(l->tete->next->data==3);
  assert(l->tete->next->next->data==2);
assert(l->tete->next->next->next->data==5);
assert(l->tete->next->next->next->next->data==1);
  assert(l->tete->next->next->next->next->next->next==l->tete->next->next->next->next);
free(l->tete->next->next->next->next);
free(l->tete->next->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
printf("OK pour le test de ADDING___after.//\n");
}
static void test_removing_after(){
Liste l=liste_vide();
  add__head(l,1);
  add__head(l,2);
  add__head(l,3);
add__head(l,4);
struct block* after=l->tete->next->next;
liste__remove_after(l,after);
 assert(l->tete->data==4);
  assert(l->tete->next->data==3);
  assert(l->tete->next->next->data==2);
  assert(l->tete->next->next->next==l->tete->next->next);
//free(l->tete->next->next->next->next);
//free(l->tete->next->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
printf("OK pour le test de REMOVING___after.//\n");
}

static void test_FIND(){
Liste l=liste_vide();
  add__head(l,1);
  add__tail(l,2);
  add__head(l,3);
add__tail(l,4);
assert(find(l,1)==1);
assert(find(l,2)==1);
assert(find(l,3)==1);
assert(find(l,4)==1);
assert(find(l,5)==0);
assert(find(l,0)==0);
free(l->tete->next->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
printf("OK pour la fonction de testing(procedure..) if belonging elemnt or not.\n");
}

void test__debug_data(){
Liste l=liste_vide();
  add__head(l,1);
  add__tail(l,2);
  add__head(l,3);
add__tail(l,4);
debug_data(l);
free(l->tete->next->next->next);
free(l->tete->next->next);
free(l->tete->next);
free(l->tete);
free(l);
printf("OK (dernier ok--<<<<<.|///\n");
}

int main(){
  test_liste__vide();
test_add__head();
test_add__tail();
test_remove__head();
test_remove__tail();
test_LEN();
test_adding_after();
test_removing_after();
test_FIND();
test__debug_data();
  return EXIT_SUCCESS;
}
