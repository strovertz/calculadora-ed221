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

void pilha_push(Pilha* p, char v, float x) {
    Data_t* n = (Data_t*) malloc(sizeof(Data_t));
    n = p->prim;
    if (n->tipo == true){
        n->operando = x;
    }
    if (n->tipo == false) n->operador = v;
    n-> prox = p-> prim;
    p-> prim = n;
}

float pilha_pop (Pilha* p) {
    Data_t *t = p->prim;
    float v;
    char op;
    if (t->tipo == true) v = t->operando;
    if (t->tipo == false) op = t->operador;
    p->prim = t->prox;
    free(t);
    if (v < 0 || v > 10000) return op;
    else return v;
}

bool pilha_vazia(Pilha* p) {
    if(p->prim == NULL) return true;
    return 0;
}

void pilha_libera (Pilha *p) {
    Data_t * q = p->prim;
    while(q != NULL) {
        Data_t * t = q->prox;
        free(q);
        q = t;
    }
}

void pilha_imprime(Pilha *p) {
    for (Data_t * q=p->prim; q != NULL; q=q->prox) {
        printf("%c\n", q->operador);
    }
}


