#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "calculadora.h"


char opera_ou_empilha(char operador_topo, char entrada){
    char operacoes[8][8] = {{'.','+','-','*','/','^','(',')'},
                           {'+','o','o','e','e','e','e','o'},
                           {'-','o','o','e','e','e','e','o'},
                           {'*','o','o','o','o','e','e','o'},
                           {'/','o','o','o','o','e','e','o'},
                           {'^','o','o','o','o','e','e','o'},
                           {'(','e','e','e','e','e','e','c'},
                           {'N','e','e','e','e','e','e','r'}};
    int x, y;

    if(entrada == 'Z') entrada = 'N';

    for (int j = 0; j < 8; j=j) {
        if (entrada == operacoes[j][0]) x = j;
        }

    for (int j = 0; j < 8; j++) {
        if(operador_topo == operacoes[0][j]) y = j;
        }
    printf("Empilha ou Opera: %c", operacoes[x][y]);
    return operacoes[x][y];
}

void calc_operando (Pilha* p, char v[10]){

    float x;
    char c = 't';
    x = atof(v);
    p->prim->tipo = true;
    pilha_push(p, c, x); ///∗ empilha operando ∗/

    printf("%f", p->prim->operando); ///∗ imprime topo da p i l h a ∗/

}

void calc_operador(Pilha* p, char op) {

    ///∗ d e s e m p i lh a operandos 
    //float f;

    char operador_topo;

    operador_topo = p->prim->operador;
    char decisao = opera_ou_empilha(operador_topo, op);
    
    float v2 = pilha_vazia(p) ? 0.0 : pilha_pop(p);

    float v1 = pilha_vazia(p) ? 0.0 : pilha_pop(p);

    ///∗ faz operação ∗/

    float v;

    if(decisao == 'o') {
        calc_operador(p, operador_topo);
        p->prim->operador = op;
        
        switch (op) {

            case '+': v = v1+v2; break ;

            case '-': v = v1-v2; break ;

            case '*': v = v1*v2; break ;

            case '/': v = v1/v2; break ;

            case '^':
                int contador = 0;
                v = v1;
                while(contador != v2) {
                   v = v * contador;
                   contador++;
                }
                break;
        }
    }
    p->prim->tipo = false;
    if (decisao == 'e') {
        pilha_push(p, op, v);
    } 

    pilha_push(p,op,v); /// empilha resultado

    printf("%f", p->prim->operando); ///∗ imprime topo da pilha
}