#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interface.h"
#define TM_EXP 60;

char opera_ou_empilha(char operador_topo, char entrada){
    char operacoes[8][9] = {{'.','+','-','*','/','^','(',')','\n'},
                            {'+','o','o','e','e','e','e','o','o'},
                            {'-','o','o','e','e','e','e','o','o'},
                            {'*','o','o','o','o','e','e','o','o'},
                            {'/','o','o','o','o','e','e','o','o'},
                            {'^','o','o','o','o','e','e','o','o'},
                            {'$','e','e','e','e','e','e','s','a'},
                            {'(','e','e','e','e','e','e','c','f'}};
    int x, y;

    for (int j = 0; j < 8; j=j) {
        if (entrada == operacoes[j][0]) x = j;
        }

    for (int j = 0; j < 8; j++) {
        if(operador_topo == operacoes[0][j]) y = j;
        }
    printf("Empilha ou Opera: %c", operacoes[x][y]);
    return operacoes[x][y];
}

char* aloca_temp() {
    char* tmp = malloc(2*sizeof(char));
    return tmp;
}

double calculadora(double num1, double num2, char operador)
{
    switch (operador) {
    case '+':
        return num2 + num1;
        break;
    case '-':
        return num2 - num1;
        break;
    case '*':
        return num2 * num1;
        break;
    case '/':
        return num2/num1;
        break;
    case '^':
        return pow(num1, num2);
        break;
    default:
        printf("operador %c desconhecido", operador);
        exit(1);
    }
}


Data_t calculo(Pilha *n, char op){

    Data_t *result;
    double uno, dos;

    uno = pilha_pop(n).operando;
    dos = pilha_pop(n).operando;

    result->operando = calculadora(uno, dos, op);

}
bool testa_tipos(char t){
    int j = t;
    if(j >= 48 || j <=  57) return true;
    else return false;
}

Data_t fraciona_exp(char **string){
    Data_t atm;
    char *t;
    strcpy(t, *string);
    char j;
    j = t[0];
    if (testa_tipos(j) == true){atm.type = true; atm.operando = atof(t); while(testa_tipos(j))t++;}
    else{atm.type = false; atm.operador = t[1]; t++;}

    strcpy(*string, t);
    return atm;
}

double le_string(Pilha* n, Pilha* c, Data_t t){
    
    Data_t ins;
    ins.operador = '&';
    pilha_push(c, ins);
    char *tmp = aloca_temp();
    strcpy(tmp, "10*5/2^4*(2-1)");
    t = fraciona_exp(&tmp);

    while(!pilha_vazia(c)){
      if(t.operador == ' ') {
                t = fraciona_exp(&tmp);
            }
            if(t.type == true) {
                pilha_push(n, t);
                t = fraciona_exp(&tmp);
            
            } else if(t.type == false){
                if(t.operador == ' ') {
                    t = fraciona_exp(&tmp);
                }
                char operacao = opera_ou_empilha(t.operador, pilha_topo(c).operador);
                if(operacao == 'a'){
                    if(pilha_vazia(n)) {
                        printf("erro de falta de resposta\n");
                        exit(1);
                    }
    
                    double res = pilha_pop(n).operando;
                    
                    if(!pilha_vazia(n)) {
                        printf("erro de falta de operadores\n");
                        exit(1);
                    }
                    printf("%lf", res);
                    return res;
                
                    pilha_libera(n);
                    pilha_libera(c);
                    break;
                
                } else if(operacao == 'o'){
                    pilha_push(n, calculo(n, pilha_pop(c).operador));
                
                } else if(operacao == 'e'){
                    pilha_push(c, t);
                    t = fraciona_exp(&tmp);
                
                } else if(operacao == 'f'){
                    printf("Falta um ) nos operadores\n");
                    break;
                
                } else if(operacao == 'c'){
                    char removido = pilha_pop(c).operador;
                    t = fraciona_exp(&tmp);
                
                } else if(operacao == 'p'){
                    printf("Falta um ( nos operadores\n");
                    break;
                
                } else{
                    t = fraciona_exp(&tmp);
                }
            
            } else{
                t = fraciona_exp(&tmp);
            }
        }

}