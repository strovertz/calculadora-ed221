#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "interface.h"
#include "pilha.h"

bool teste_tipo(char x){
     if(x >= 0 && x < 10) return true;
     else return false;
}

void le_string(){
    Pilha* p = pilha_cria();
    char leitura[30];
    char operador;
    char operando[10];
    printf("insira uma expressao");
    //scanf("%s", leitura);
    int tam;
    char tmp[1];
    strcpy(leitura,"10+3");
    tam = strlen(leitura);
    for(int i = 0; i < tam; i++) {
        while(teste_tipo(leitura[i]) == true){
            tmp[0] = leitura[i];
            strcat(operando, tmp[0]);
            calc_operando(p, operando);
            i++;
        }
        operador = leitura[i];
        calc_operador(p, operador);
        operador = 'z';
    }   
}