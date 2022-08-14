#include <stdio.h>
#include "interface.h"


int main (void) {
    while (1){
        Pilha* n = pilha_cria();
        Pilha* c = pilha_cria();
        Data_t t;
        char *exp = aloca_temp();
        fgets(exp, 195, stdin);
        printf("Resultado: %lf", le_string(n, c, t, exp));
    }
}
