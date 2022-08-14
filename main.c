#include <stdio.h>
#include "interface.h"


int main (void) {
    while (1){
        Pilha* num = pilha_cria();
        Pilha* shar = pilha_cria();
        Data_t t;
        printf("teste");
        le_string(num, shar, t);
    }
}
