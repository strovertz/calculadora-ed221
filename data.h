#ifndef _DATA_H_    // para evitar a inclusão múltipla deste arquivo
#define _DATA_H_
   // o tipo d dados data_t
typedef struct data_t Data_t;

typedef struct data_t  {

    float operando;
    char* operador;
    Data_t* prox;
} Data_t;

#endif // _DATA_H_