#ifndef _PILHA_H_    // para evitar a inclusão múltipla deste arquivo
#define _PILHA_H_
#include <stdbool.h>
#include "data.h"

typedef struct pilha Pilha;


struct pilha {

    Data_t* prim;
};

// cria uma pilha vazia
Pilha* pilha_cria ();
//empilha dado v no topo da pilha p
void pilha_push (Pilha* p, char v, float x, int tipo);
//remove e retorna o dado no topo da pilha p;
float pilha_pop (Pilha* p);
//retorna true se a pilha p não tiver dados -funcion ok
bool pilha_vazia (Pilha* p);
//libera a mameoria ocupada (destroi a pilha p) - funcion ok
void pilha_libera (Pilha* p);

#endif // _PILHA_H_