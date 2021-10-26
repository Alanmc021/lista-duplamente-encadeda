#pragma once
 
typedef struct Lista list;

 
typedef struct Noli no;

 
list* cria_lista(void); 

void cria_lista_vazia(list* l, int c, int r);

no* cria_no_lista(int val);

int vazia_lista(list* l);

int busca_lista(list* l, int val, no** n);

int clas_lista(const list* l);

int rep_lista(const list* l);

void exibir_lista(list* l);

int insere_lista(list* l, int valor);

int exclui_um(list* l, int valor);

void exclui(list* l, int valor);