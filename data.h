#ifndef _DATA_H_    // para evitar a inclusão múltipla deste arquivo
#define _DATA_H_
   // o tipo d dados data_t
typedef struct data_t Data_t;

struct data_t  {
    bool type; // 1 se for operando, 0 se for operador
    double operando;
    char operador;
    Data_t* prox;
};

#endif // _DATA_H_