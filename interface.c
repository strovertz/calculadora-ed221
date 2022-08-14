#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "interface.h"
#define TM_EXP 60;

char* aloca_temp() {
    char* tmp = malloc(200*sizeof(char));
    //printf("loopa akq");
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
            return num2 / num1;
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
bool testa_tipos(char *s){
    if(isdigit(s[0])) return true;
    else return false;
}

Data_t fraciona_exp(char **string){
    Data_t ret;
    char *s = *string;

    if(testa_tipos(s)){

        ret.type = true;
        sscanf(s, "%lf", &ret.operando);
        while(testa_tipos(s)){
            s++;
        }

    } else if(!testa_tipos(s)) {
        ret.type = false;
        ret.operador= *s;
        s++;

    } else {

        s++;
    }

    *string = s;
    return ret;
}

/*double results(char operacao, Pilha *n, Pilha *c, Data_t ins, Data_t t, char *tmp) {
    char parenteses_final[1];
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
            parenteses_final[0] = pilha_pop(c).operador;
            t = fraciona_exp(&tmp);
        case 'p':
            printf("Problema com parenteses aberto ou nao\n");
            break;
        default:
            t = fraciona_exp(&tmp);
            break;
    }
}*/

double le_string(char *exp) {

    Data_t ins;
    Pilha* n = pilha_cria();
    Pilha* c = pilha_cria();
    Data_t t;
    printf("\nchega aq\n");
    ins.operador = '&';
    pilha_push(c, ins);
    char *tmp = malloc(100*sizeof(char));
    tmp = exp;
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
                //results(operacao, n, c, ins, t, tmp);
                char parenteses_final[1];
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
                        parenteses_final[0] = pilha_pop(c).operador;
                        t = fraciona_exp(&tmp);
                    case 'p':
                        printf("Problema com parenteses aberto ou nao\n");
                        break;
                    default:
                        t = fraciona_exp(&tmp);
                        break;
                }
            } else{
                t = fraciona_exp(&tmp);
            }
        }
}