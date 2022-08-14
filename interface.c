#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interface.h"
#define TM_EXP 60;

char* aloca_temp() {
    char* tmp = malloc(200*sizeof(char));
    printf("loopa akq");
    return tmp;
}

double calculadora(double num1, double num2, char op)
{
    switch (op) {
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
        printf("Tem besteira aqui ein: %c ", op);
        exit(1);
    }
}

Data_t calculo(Pilha *n, char op){

    Data_t result;
    double uno, dos;

    uno = pilha_pop(n).operando;
    dos = pilha_pop(n).operando;

    result.operando = calculadora(uno, dos, op);
    //printf("teste: %lf", result.operando);
    return result;
}
bool testa_tipos(char *t){
    char j = *t;
    if(j >= 48 || j <=  57) return true;
    else return false;
}

Data_t fraciona_exp(char **string){
    Data_t atm;
    char *t = *string;
    if (testa_tipos(t)){
        atm.type = true; 
        atm.operando = atof(t);
        while(testa_tipos(t)){t++;}
        
        }

    else{atm.type = false; atm.operador = t[1]; t++;}

    strcpy(*string, t);
    return atm;
}

double results(char operacao, Pilha *n, Pilha *c, Data_t ins, Data_t t, char *tmp) {
    switch (operacao) {
        case 'a':
            if(pilha_vazia(n)) {
                printf("Erro: pilha vazia");
                exit(32);
            }

            double res = pilha_pop(n).operando;
            
            if(!pilha_vazia(n)) {
                printf("Falta operador \n");
                exit(1);
            }
            printf("%lf", res);
            return res;
        
            pilha_libera(n);
            pilha_libera(c);
            break;
        
        case 'o':
            pilha_push(n, calculo(n, pilha_pop(c).operador));
            break;
        case 'e': 
            pilha_push(c, t);
            t = fraciona_exp(&tmp);
            break;
        case 'f':
            printf("Vai fechar esse parenteses \n");
            break;
        
        case 'c':
            char *parenteses_final = malloc(sizeof(char));
            parenteses_final[0] = pilha_pop(c).operador;
            free(parenteses_final);                    
            t = fraciona_exp(&tmp);
        
        case 'p':
            printf("Problema com parenteses aberto ou nao\n");
            break;
        
        default:
            t = fraciona_exp(&tmp);
            break;
    }
    return -1;
}

double le_string(char *exp){

    printf("problema aq");
    Data_t ins;
    Pilha* n = pilha_cria();
    Pilha* c = pilha_cria();
    Data_t t;
    printf("chega aq");
    ins.operador = '&';
    pilha_push(c, ins);
    char *tmp = exp;
    t = fraciona_exp(&tmp);
    
    while(1){
      if(t.operador == ' ') {
                t = fraciona_exp(&tmp);
            }
            if(t.type) {
                pilha_push(n, t);
                t = fraciona_exp(&tmp);
            
            } else if(!t.type){
                if(t.operador == ' ') {
                    t = fraciona_exp(&tmp);
                }
                char operacao = opera_ou_empilha(t.operador, pilha_topo(c).operador);
                results(operacao, n, c, ins, t, tmp);

            } else{
                t = fraciona_exp(&tmp);
            }
        }
    return 10;
}