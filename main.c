#include <stdio.h>

int lerInteiroNoIntervalo (int minimo, int maximo);

int main(){

    return 0;
}

int lerInteiroNoIntervalo (int minimo, int maximo){
    int resultadoLeitura, valor, entradaInvalida;

    do
    {   
        resultadoLeitura = scanf("%d", &valor);

        if (resultadoLeitura != 1){
            entradaInvalida = 1;
            printf("Entrada invalida\n");
            while(getchar() != '\n');
        }

        else {
            entradaInvalida = (valor > maximo || valor < minimo);
            if (entradaInvalida) {
                printf("Valor invalido\n");
            }
        }

    } while(entradaInvalida);

    return valor;
}