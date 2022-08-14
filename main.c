#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main (void) {
    /*Pilha* n = pilha_cria();
    Pilha* c = pilha_cria();
    Data_t t;*/
    char *expressao = malloc(sizeof(char) * 100);
    
    while(fgets(expressao, 99, stdin)) {
        printf("teste");
        printf("vale %lf\n", le_string(expressao));
    }
}
