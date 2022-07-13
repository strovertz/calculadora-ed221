#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
//#include "pilha.h"

bool teste_tipo(char x){
     if((x >= 0 && x < 10) || x == '.') return true;
     else return false;
}

char* aloca_temp() {
    char* tmp = malloc(1*sizeof(char));
    return tmp;
}

void le_string(Pilha* n, Pilha* c){
    char leitura[30];
    char operador;
    char operando[10];
    char *temp = malloc(1*sizeof(char));
    int tam;
    char *tmp = aloca_temp();
    strcpy(leitura,"10+3");
    printf("leitura: %s", leitura);
    tam = strlen(leitura);
    for(int i = 0; i < tam; i++) {
        while(teste_tipo(leitura[i]) == true){
            tmp[0] = leitura[i];
            temp[0] = tmp[0];
            strcat(operando, temp);
            calc_operando(n, operando);
            i++;
        }
        operador = leitura[i];
        calc_operador(c, n, operador);
        operador = 'z';
    }   
}