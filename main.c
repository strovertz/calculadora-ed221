#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
/*
 *  Trabalho 3 - Gleison A. Pires da Silva
 *  Alguns funções eu construi com ajuda do livro do Celles (n lembro se escreve assi), ele explica como construir uma calculadora pós fixada
 *  O versionamento do código ta presente no meu github, só q em uma parte do trabalho passei tanto stress que esqueci de comitar algumas alterações kkkk
 *  qualquer dúvida pode me questionar ou qualquer contestação de plágio também, já que a turma toda se ajudou um pouco nesse trabaho eu preferi fazer o github pra garantir, a
 *  antes eu tava trabalhando com muitos arquivos, tinha um calculadora.c, calculadora.h, mas tavam me dando muita dor de cabeça os includes na ordem certa, fzer tudo na interface facilitou um pouco
 *
 *  PS: Isso aqui não deveria estar em um readme.txt? não sei mais, são 6 da manhã de domingo...
*/
int main (void) {
    /*Pilha* n = pilha_cria();
    Pilha* c = pilha_cria();
    Data_t t;*/
    char *exp = aloca_temp();

    strcpy(exp, "5+10*3+(2-1)\n");
    float x = le_string(exp);
    printf("Resultado da conta eh: %.2lf\n", x);
}
