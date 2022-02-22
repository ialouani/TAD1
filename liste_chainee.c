#include "./liste_chainee.h"
#ifndef __A1
#define __A1
#include <stdlib.h>

#include <stdio.h>
#endif

struct block{
  int data;
  struct block* next;
};

Liste liste_vide(){
  Liste l=(Liste)calloc(1,sizeof(struct liste));
  l->tete=NULL;//optionnel vu calloc pour MiEUX.
  return l;
}

enum Bool liste__est_vide(Liste l){
  return l->tete==NULL;
}

void add__head(Liste l, int b){
  if(l->tete==NULL){
    struct block* add0=(struct block*)malloc(2*sizeof(struct block*));
    add0->data=b;
    add0->next=NULL;
    l->tete=add0;
    l->tete->next=l->tete;
    return ;}
  else{
    struct block* add0=(struct block*)malloc(2*sizeof(struct block*));
    add0->data=b;
    add0->next=NULL;
    struct block* tmp=l->tete;
    l->tete=add0;
    add0->next=tmp;
    return;
  }
}

void add__tail(Liste l, int b){
   if(liste__est_vide(l)){
    struct block* add0=(struct block*)malloc(2*sizeof(struct block*));
    add0->data=b;
    add0->next=NULL;
    l->tete=add0;
    l->tete->next=l->tete;
    return ;}
   else{
     struct block* tmp=l->tete;
     while(tmp->next!=tmp){
       tmp=tmp->next;}
    struct block* add0=(struct block*)malloc(2*sizeof(struct block*));
    add0->data=b;
    add0->next=NULL;
    tmp->next=add0;
    add0->next=add0;
    return ;}
}

void remove__head(Liste l){
  struct block* removed=l->tete;
  if(liste__est_vide(l)){
    //return NULL;
  }
  else if(l->tete!=NULL && l->tete->next==l->tete){//1 seul element
    struct block* tmp=l->tete;
    tmp->next=NULL;
    l->tete=NULL;
    free(tmp);
    //return tmp;
  }
  else if(!liste__est_vide(l) && l->tete->next!=l->tete){//>=2 (test avant NN).
    struct block* tmp=l->tete;
    l->tete=l->tete->next;
    tmp->next=NULL;
    free(tmp);
    //return tmp;
  }
  else{
    struct block* tmp=l->tete;
    l->tete=l->tete->next;
    tmp->next=NULL;
    free(tmp);
    //return tmp;
  }
}

void remove__tail(Liste l){
  if(l->tete==NULL){
    return;}
  else if(l->tete->next==l->tete){
    struct block* tmp=l->tete;
    l->tete=NULL;
    free(tmp);
    return ;}
  else{//a partir de 2 elements au moins:>>
    struct block* tmp2=l->tete->next;
    struct block* tmp1=l->tete;
    while(tmp2->next!=tmp2){
      tmp1=tmp2;
      tmp2=tmp2->next;
    }
    tmp1->next=tmp1;
    tmp2->next=NULL;
    free(tmp2);
    return ;}
}
    
int len(struct liste* lc){
   int cpt=0;
  if(lc->tete==NULL) return cpt;
  else{
    struct block* tmp=lc->tete;
    while(tmp->next!=tmp){
      cpt++;tmp=tmp->next;
    }
    return cpt+1;
  }
}

void liste__add_after(Liste l,struct block* after,int b){
  if(l->tete==NULL) return;
  else if (l->tete->next==l->tete){//<=>len(l)==1.
    //on suppose que after est coherent avec la structure empilee.
    //add__head(l,b);(car aprs l'unique element donc IMPOSSIBLE!!!!)
    return ;}
  else{//<=>len(l)>1
    struct block* tmp=l->tete;
    while(tmp->next!=tmp){
      if(tmp==after) break;
      else tmp=tmp->next;}
    if(tmp->next==tmp){
      if(tmp==after){
	return ;//bugs sinon.
      }
    }
    else{//tmp==after
      struct block* add0=(struct block*)malloc(2*sizeof(struct block));
      add0->data=b;
      add0->next=NULL;
      struct block* tmp2=tmp->next;
      tmp->next=add0;
      add0->next=tmp2;
      return;
    }
  }
}

void liste__remove_after(Liste l, struct block* after){
  if(l->tete==NULL) return;
  else if (l->tete->next==l->tete){//<=>len(l)==1.
    //on suppose que after est coherent avec la structure empilee.
    //remove__tail(l);
    return ;}
  else{
 struct block* tmp=l->tete;
    while(tmp->next!=tmp){
      if(tmp==after) break;
      else tmp=tmp->next;}
    if(tmp->next==tmp){
      if(tmp==after){
	return ;//bugs sinon.
      }
    }
    else if (tmp->next->next==tmp->next){//<==>a retirer depuis
      //la fin de la queue de *l la capsule struct block type 's.
      remove__tail(l);
      return;
    }
    else{//tmp==after && tmp->next!=tmp bien évidemment.//
      struct block* tmp3=tmp->next->next;
      struct block* tmp2=tmp->next;
      tmp2->next=NULL;
      tmp->next=tmp3;
      free(tmp2);
      return;
    }
  }
}

enum Bool find(struct liste* lc, int a){
  if(lc->tete==NULL) return 0;
  else if(lc->tete->next==lc->tete) return lc->tete->data==a;
  else{
    struct block* tmp=lc->tete;
    while(tmp->next!=tmp){
      if(tmp->data==a) return 1;
      else tmp=tmp->next;
    }
    return tmp->data==a;
  }}

void debug_data(Liste lc){
  if(lc->tete==NULL) return ;
  else if(lc->tete->next==lc->tete){
    printf("%d\t\n",lc->tete->data);return;}
  else{
    struct block* tmp=lc->tete;
    while(tmp->next!=tmp){
      printf("%d\t",tmp->data);tmp=tmp->next;}
    printf("%d\n",tmp->data);
    return;}}

    







  











    
