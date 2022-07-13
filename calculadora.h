#ifndef _CALCULADORA_H_    // para evitar a inclusão múltipla deste arquivo
#define _CALCULADORA_H_
#include "pilha.h"

void calc_operando (Pilha* p, char v[10]);

void calc_operador (Pilha* p, Pilha* n, char op);


#endif // _CALCULADORA_H_