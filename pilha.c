#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

Pilha* pilha_cria (){
    Pilha* p = (Pilha*) malloc(sizeof (Pilha));
    p-> prim = NULL;
    return p;
}

Data_t pilha_topo(Pilha *p) {
    return p->prim->dado;
}

void pilha_push(Pilha* p, Data_t x) {
    Lista* n = (Lista*) malloc(sizeof(Lista));
    if(n) {n->dado = x; n->prox = p->prim; p->prim = n;} 
    else return;
}

Data_t pilha_pop (Pilha* p) {
    Lista *t = p->prim;
    p->prim = t->prox;
    return t->dado;
}

bool pilha_vazia(Pilha* p) {
    if(p->prim == NULL) return true;
    return 0;
}

void pilha_libera (Pilha *p) {
    Lista *q = p->prim;
    while(q != NULL) {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

/*void pilha_imprime(Pilha *p) {
    for (Data_t * q=p->prim; q != NULL; q=q->prox) {
        printf("%c\n", q->operador[0]);
    }
}*/ // rascunho p testes caso eu esqueça de apagar, favor desconsiderar