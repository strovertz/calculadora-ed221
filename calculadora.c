#include <stdio.h>
#include <math.h>
#include "calculadora.h"

double calculadora(double num1, double num2, char op)
{
    switch (op) {
    case '+':
        return num2 + num1;
        break;
    case '-':
        return num2 - num1;
        break;
    case '*':
        return num2 * num1;
        break;
    case '/':
        return num2/num1;
        break;
    case '^':
        return pow(num1, num2);
        break;
    default:
        printf("Tem besteira aqui ein: %c ", op);
        exit(1);
    }
}