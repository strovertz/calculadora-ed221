#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

Pilha* pilha_cria (){

    Pilha* p = (Pilha*) malloc(sizeof (Pilha));

    p-> prim = NULL;

    return p;

}

void pilha_push(Pilha* p, float v) {
    Pilha_List * n = ( Pilha_List *) malloc(sizeof ( Pilha_List ));

    if (n->tipo == true) v = n->operando;
    if (n->tipo == false) v = n->operador;
    n-> prox = p-> prim;
    p-> prim = n;
}

float pilha_pop (Pilha* p) {
    Pilha_List *t = p->prim;
    float v;
    if (t->tipo == true) v = t->operando;
    if (t->tipo == false) v = t->operador;
    p->prim = t->prox;
    free(t);
    return v;
}

bool pilha_vazia(Pilha* p) {
    if(p->prim == NULL) return true;
    return 0;
}

void pilha_libera (Pilha *p) {
    Pilha_List* q = p->prim;
    while(q != NULL) {
        Pilha_List * t = q->prox;
        free(q);
        q = t;
    }
}

void pilha_imprime(Pilha *p) {
    for (Pilha_List* q=p->prim; q != NULL; q=q->prox) {
        printf("%f \n", q->operador);
    }
}


