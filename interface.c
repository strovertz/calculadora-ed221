#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "pilha.h"

bool teste_tipo(char x){
     if(x != '*' && x != '+' && x != '-' && x != '^' && x != '/' && x != '(' && x != ')') return true;
     else return false;
}

void le_string(){

    Pilha* p = pilha_cria();
    char leitura[30];
    char operador;
    char operando[10];
    printf("insira uma expressao");
    scanf("%s", leitura);
    int tam;
    tam = strlen(leitura);
    for(int i =0; i<tam;) {
        while(teste_tipo(leitura[i]) == true){
            strcat(operando, leitura);
            calc_operando(p, operando);
            i++;
        }
        operador = leitura[i];
        calc_operador(p, operador);
        operador = 'z';
        i++;
    }   
}