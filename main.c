#include <stdio.h>
#include "interface.h"


int main (void) {
    while (1){
        Pilha* num = pilha_cria();
        Pilha* shar = pilha_cria();
        printf("teste");
        le_string(num, shar);
    }
}
