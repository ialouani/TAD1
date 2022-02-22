#ifndef __LISTE
#define __LISTE

struct block;
struct liste{
  struct block* tete;
};
enum Bool {false,true};
typedef struct liste* Liste;//risqué de pouvoir considérer un type incomplet
//qui n'a pas bcp de sens vu d'un point de vue abstractif.

Liste liste_vide();
enum Bool liste__est_vide(Liste l);
void add__head(Liste l, int b);
void add__tail(Liste l, int b);
void remove__head(Liste l);
void remove__tail(Liste l);
void liste__add_after(Liste l,struct block* after,int b);//dernier(1).
void liste__remove_after(Liste l, struct block* after);//dernier(2).
int len(struct liste* lc);
enum Bool find(struct liste* lc, int a);
void debug_data(Liste lc);

#endif
