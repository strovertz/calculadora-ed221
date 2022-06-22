#include <stdbool.h>

typedef struct pilha_lista Pilha_List;
typedef struct pilha Pilha;

struct pilha_lista  {

    bool tipo; // if true, operando, if false, operador
    float operando;
    char operador;
    Pilha_List* prox;
};

struct pilha {

    Pilha_List* prim;
};

// cria uma pilha vazia
Pilha* pilha_cria ();
//empilha dado v no topo da pilha p
void pilha_push (Pilha* p, float v);
//remove e retorna o dado no topo da pilha p;
float pilha_pop (Pilha* p);
//retorna true se a pilha p não tiver dados -funcion ok
bool pilha_vazia (Pilha* p);
//libera a mameoria ocupada (destroi a pilha p) - funcion ok
void pilha_libera (Pilha* p);