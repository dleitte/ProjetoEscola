#include <string.h>
#include "utils.h"

void toLowerStr(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int validarSexo(char sexo[]) {
    char temp[20];
    int i;
    for (i = 0; sexo[i] != '\0'; i++) {
        temp[i] = sexo[i];
    }
    temp[i] = '\0';
    toLowerStr(temp);

    return (
        strcmp(temp, "m") == 0 ||
        strcmp(temp, "f") == 0 ||
        strcmp(temp, "masculino") == 0 ||
        strcmp(temp, "feminino") == 0
    );
}

int validarData(int d, int m, int a) {
    if (a < 1900 || a > 2025) return 0;
    if (m < 1 || m > 12) return 0;
    int diasPorMes[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))) {
        return (d >= 1 && d <= 29);
    }
    return (d >= 1 && d <= diasPorMes[m - 1]);
}

int validarCPF(char *cpf) {
    int i, j, soma, digito1, digito2;
    char numeros[12] = {0};
    int contador = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            numeros[contador++] = cpf[i];
        }
    }

    if (contador != 11) return 0;

    for (i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) break;
    }
    if (i == 11) return 0;

    soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += (numeros[i] - '0') * j;
    }

    digito1 = 11 - (soma % 11);
    if (digito1 >= 10) digito1 = 0;
    
    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += (numeros[i] - '0') * j;
    }

    digito2 = 11 - (soma % 11);
    if (digito2 >= 10) digito2 = 0;
    
    return (numeros[9] - '0' == digito1 && numeros[10] - '0' == digito2);
}
