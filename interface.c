#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

bool teste_tipo(char x){
     if(x != '*' && x != '+' && x != '-' && x != '^' && x != '/' && x != '(' && x != ')') return true;
     else return false;
}

void le_string(){

    char leitura[30];
    char operador[1];
    char operando[10];
    printf("insira uma expressao");
    scanf("%s", leitura);
    int tam;
    tam = strlen(leitura);
    for(int i =0; i<tam;) {
        while(teste_tipo(leitura[i]) == true){
            strcat(operando, leitura[i]);
            calc_operando(p, operando);
            i++;
        }
        operador = leitura[i];
        calc_operador(p, operador);
        operador = 'z';
        i++;
    }   
}