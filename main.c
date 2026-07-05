#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerInteiroNoIntervalo(int minimo, int maximo);
int lerOpcaoMenu(void);
int cadastrarNome(char nomes[][50], int indice);
int cadastrarEmail(char emails[][30], int indice);
int cadastrarSalario(float salarios[], int indice);
float lerSalarioValido(void);
void mostrarFuncionarios(char nomes[][50], char emails[][30], float salarios[], int quantidadeFuncionarios);
void buscarFuncionario(char nomes[][50], char emails[][30], float salarios[], int quantidadeFuncionarios);
void limparBuffer(void);
void pausar(void);
void limparTela(void);
void calcularMedia(float salarios[], int quantidadeFuncionarios);
void mostrarMaiorSalario(char nomes[][50], float salarios[], int quantidadeFuncionarios);


int main(void) {
    int opcao;
    char nomes[10][50];
    char emails[10][30];
    float salarios[10];
    int quantidadeFuncionarios = 0;

    do {
        opcao = lerOpcaoMenu();

        if (opcao != 6) {
            limparTela();
        }

        switch (opcao) {
            case 1:
                if (quantidadeFuncionarios == 10) {
                    printf("AGENDA CHEIA! Por favor escolha outra opcao!!!\n");
                    break;
                }

                int nomeValido = cadastrarNome(nomes, quantidadeFuncionarios);
                int emailValido = cadastrarEmail(emails, quantidadeFuncionarios);
                int salarioValido = cadastrarSalario(salarios, quantidadeFuncionarios);

                if (nomeValido && emailValido && salarioValido) {
                    quantidadeFuncionarios++;
                    printf("Funcionario cadastrado com sucesso!\n");
                } else {
                    printf("Falha no cadastro. Tente novamente.\n");
                }
                break;

            case 2:
                mostrarFuncionarios(nomes, emails, salarios, quantidadeFuncionarios);
                break;

            case 3:
                buscarFuncionario(nomes, emails, salarios, quantidadeFuncionarios);
                break;

            case 4:
                mostrarMaiorSalario(nomes, salarios, quantidadeFuncionarios);
                break;
            
            case 5:
                calcularMedia(salarios, quantidadeFuncionarios);
                break;
            
            case 6:
                printf("Finalizando o programa...\n");
                break;
            
            default:
                printf("Erro inesperado\n");
                break;
        }

        if (opcao != 6) {
            limparBuffer();
            pausar();
            limparTela();
        }

    } while (opcao != 6);

    return 0;
}

int lerInteiroNoIntervalo(int minimo, int maximo) {
    int resultadoLeitura, valor, entradaInvalida;

    do {
        resultadoLeitura = scanf("%d", &valor);

        if (resultadoLeitura != 1) {
            entradaInvalida = 1;
            printf("Entrada invalida\n");
            while (getchar() != '\n');
        } else {
            entradaInvalida = (valor > maximo || valor < minimo);
            if (entradaInvalida) {
                printf("Valor invalido\n");
            }
        }

    } while (entradaInvalida);

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

int cadastrarNome(char nomes[][50], int indice) {
    printf("Nome do funcionario: ");
    int resultado = scanf(" %49[^\n]", nomes[indice]);

    if (resultado != 1) {
        printf("Nome invalido.\n");
        while (getchar() != '\n');
        return 0;
    }

    return 1;
}

int cadastrarEmail(char emails[][30], int indice) {
    printf("E-mail do funcionario: ");
    int resultado = scanf(" %29[^\n]", emails[indice]);

    if (resultado != 1) {
        printf("E-mail invalido.\n");
        while (getchar() != '\n');
        return 0;
    }

    return 1;
}

int cadastrarSalario(float salarios[], int indice) {
    salarios[indice] = lerSalarioValido();
    return 1;
}

float lerSalarioValido(void) {
    float valor;
    int resultadoLeitura, entradaInvalida;

    do {
        printf("Salario do funcionario: ");
        resultadoLeitura = scanf("%f", &valor);

        if (resultadoLeitura != 1) {
            entradaInvalida = 1;
            printf("Entrada invalida (deve ser um numero)\n");
            while (getchar() != '\n');
        } else {
            entradaInvalida = (valor < 0);
            if (entradaInvalida) {
                printf("Salario nao pode ser negativo\n");
            }
        }

    } while (entradaInvalida);

    return valor;
}

void mostrarFuncionarios(char nomes[][50], char emails[][30], float salarios[], int quantidadeFuncionarios) {
    if (quantidadeFuncionarios == 0) {
        printf("\nNenhum funcionario cadastrado ainda.\n");
        return;
    }

    printf("\n %-4s %-50s %-30s %-s\n", "Ind", "Nome", "E-mail", "Salario");
    for (int i = 0; i < quantidadeFuncionarios; i++) {
        printf("%-4d %-50s %-30s %.2f\n", i + 1, nomes[i], emails[i], salarios[i]);
    }
}

void limparBuffer(void) {
    while (getchar() != '\n');
}

void pausar(void) {
    printf("\nAperte ENTER para continuar...");
    getchar();
}

void buscarFuncionario(char nomes[][50], char emails[][30], float salarios[], int quantidadeFuncionarios) {
    char entrada[50];
    int encontrado = 0;

    if (quantidadeFuncionarios == 0) {
        printf("Não há funcionários cadastrados...\n");
        return;
    }

    printf("Nome Completo: ");
    scanf(" %49[^\n]", entrada);

    for (int i = 0; i < quantidadeFuncionarios; i++) {
        if (strcmp(entrada, nomes[i]) == 0) {
            encontrado = 1;
            printf("\n------------------------------------------\n");
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Salario: R$ %.2f\n", salarios[i]);
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nNenhuma pessoa encontrada com esse nome\n");
    }
}

void limparTela(void) {
    system("cls");
}

void calcularMedia(float salarios[], int quantidadeFuncionarios) {
    if (quantidadeFuncionarios == 0) {
        printf("Nao ha funcionarios cadastrados.\n");
        return;
    }

    float soma = 0;
    float mediaSalarial;

    for (int i = 0; i < quantidadeFuncionarios; i++) {
        soma += salarios[i];
    }

    mediaSalarial = (soma / quantidadeFuncionarios);
    printf("Media salarial dos funcionarios: R$ %.2f\n", mediaSalarial);
    return;
}

void mostrarMaiorSalario(char nomes[][50], float salarios[], int quantidadeFuncionarios) {
    if (quantidadeFuncionarios == 0) {
        printf("\nNenhum funcionario cadastrado ainda.\n");
        return;
    }

    int indiceMaior = 0;

    for (int i = 1; i < quantidadeFuncionarios; i++) {
        if (salarios[i] > salarios[indiceMaior]) {
            indiceMaior = i;
        }
    }

    printf("\nMaior salario eh: %.2f\n", salarios[indiceMaior]);
    printf("\nFuncionario: %s\n", nomes[indiceMaior]);
}
