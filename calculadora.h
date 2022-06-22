#include "pilha.h"

typedef struct calculadora Calc;

struct calculadora {
    char f[21];
    Pilha* p; // pilha de operandos
};


Calc* calc_cria (char * f);

void calc_operando (Calc* c, float v, char entrada);

void calc_operador (Calc* c, char op);

void calc_libera (Calc* c);