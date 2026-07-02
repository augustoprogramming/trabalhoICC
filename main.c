#include <stdio.h>

int lerInteiroNoIntervalo (int minimo, int maximo);
int lerOpcaoMenu(void);

int main(){
    int opcao;
    char nome[10][50];
    char email[10][30];
    float salario[10];
    int funcionarios = 0;

    do
    {
        opcao = lerOpcaoMenu();
    
        switch (opcao){
            case 1:
                if(funcionarios == 10){
                    printf("AGENDA CHEIA!");
                    break;
                }
                // funcao cadastrar funcionario
                funcionarios++;
                break;

            case 2:
                // funcao mostrar funcionários
                break;

            case 3:
                // funcao buscar funcionário
                break;

            case 4:
                // funcao mostrar maior salário
                break;
            
            case 5:
                // funcao calcular média salarial
                break;
            
            case 6:
                printf("Finalizando o programa...\n");
                break;
            
            default:
                printf("Erro inesperado\n");
                break;
        }

    } while (opcao != 6);

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
int lerOpcaoMenu(void) {
    int opcao;

    printf(
        "\n"
        "FUNCIONARIOS\n"
        "----------------------------------------\n"
        "\n"
        "  [1] Cadastrar funcionario\n"
        "  [2] Listar funcionarios\n"
        "  [3] Buscar por nome\n"
        "  [4] Mostrar maior salario\n"
        "  [5] Calcular media salarial\n"
        "  [6] Sair\n"
        "\n"
        "Escolha uma opcao > "
    );

    opcao = lerInteiroNoIntervalo(1, 6);
    
    return opcao;
}