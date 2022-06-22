#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calculadora.h"

char opera_ou_empilha(char operador_topo, char entrada){
    char operacoes[8][8] = {'.','+','-','*','/','^','(',')',
                             '+','o','o','e','e','e','e','o',
                             '-','o','o','e','e','e','e','o',
                             '*','o','o','o','o','e','e','o',
                             '/','o','o','o','o','e','e','o',
                             '^','o','o','o','o','e','e','o',
                             '(','e','e','e','e','e','e','c',
                             'N','e','e','e','e','e','e','r'};
    int x, y;

    for (int i = 0; i <7; i++) {
        for (int j = 1; j < 8; j=j) {
            if (entrada == operacoes[i][j]){ x = i;}
        }
    }
    for (int i = 1; i < 7; i=i) {
        for (int j = 0; j < 8; j++) {
            if(operador_topo == operacoes[i][j]) {y = j;}
        }
    }
    //printf("Empilha ou Opera: %c", operacoes[x][y]);
    return operacoes[x][y];
}

void calc_operando (Calc* c, float v, char entrada){

    char operador_topo, operador, decisao;

    operador_topo = c->p->prim->operador;

    operador = entrada;

    decisao = opera_ou_empilha(operador_topo, operador);

    if(decisao == 'o') {
        calc_operador(c, operador_topo);
        c->p->prim->operador = operador;
    }
    if (decisao == 'e') {
        pilha_push(c->p, operador);
    }
    else printf("ta dando erro");

    pilha_push(c->p,v); ///∗ e mpilha operando ∗/

    printf(c->f,v); ///∗ imprime topo da p i l h a ∗/

}

Calc* calc_cria (char * formato) {

    Calc* c = (Calc*) malloc( sizeof (Calc));

    strcpy(c->f, formato);

    c->p = pilha_cria(); ///∗ c r i a p i l h a v a z i a ∗/

    return c;
}

void calc_operador(Calc* c, char op) {

    ///∗ d e s e m p i lh a ope randos ∗/

    const float f;
    float v2 = pilha_vazia(c->p) ? 0.0 : f ; pilha_pop(c->p);

    float v1 = pilha_vazia(c->p) ? 0.0 : f ; pilha_pop(c->p);

    ///∗ f a z ope ração ∗/

    float v;

    switch (op) {

        case '+': v = v1+v2; break ;

        case '-': v = v1-v2; break ;

        case '*': v = v1*v2; break ;

        case '/': v = v1/v2; break ;

    }

    pilha_push(c->p,v); ///∗ empilha r e s u l t a d o ∗/

    printf(c->f,v); ///∗ imprime topo da p i l h a ∗/

}
void calc_libera (Calc* c) {

    pilha_libera(c->p);

    free(c);

}