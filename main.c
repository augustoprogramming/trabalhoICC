#include <stdio.h>

int lerInteiroNoIntervalo (int minimo, int maximo);
int lerOpcaoMenu(void);
int cadastrarNome(char nome[][50], int indice);
int cadastrarEmail(char email[][30], int indice);
int cadastrarSalario(float salario[], int indice);
float SalarioValido(void);
void mostrarFuncionarios(char nome[][50], char email[][30], float salario[], int funcionarios);
void limparBuffer(void);

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
                    printf("AGENDA CHEIA! Por favor escolha outra opcao!!!\n");
                    break;
                }

                int verificar_nome = cadastrarNome(nome, funcionarios);
                int verificar_email = cadastrarEmail(email, funcionarios);
                int verificar_salario = cadastrarSalario(salario, funcionarios);

                if (verificar_nome && verificar_email && verificar_salario) {
                    funcionarios++;
                    printf("Funcionario cadastrado com sucesso!\n");
                } else {
                    printf("Falha no cadastro. Tente novamente.\n");
                }
                break;

            case 2:
                // funcao mostrar funcionários
                mostrarFuncionarios(nome, email, salario, funcionarios);
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
int cadastrarNome(char nome[][50], int indice){
    printf("Nome do funcionario: ");
    int resultado = scanf(" %49[^\n]", nome[indice]);

    if (resultado != 1) {
        printf("Nome invalido.\n");
        while (getchar() != '\n');
        return 0;
    }

    return 1;
}
int cadastrarEmail(char email[][30], int indice){
    printf("E-mail do funcionario: ");
    int resultado = scanf(" %29[^\n]", email[indice]);

    if (resultado != 1) {
        printf("E-mail invalido.\n");
        while (getchar() != '\n');
        return 0;
    }

    return 1;
}
int cadastrarSalario(float salario[], int indice){
    salario[indice] = SalarioValido();
    return 1;
}
float SalarioValido(void){
    float valor;
    int resultadoLeitura, entradaInvalida;

    do
    {
        printf("Salario do funcionario: ");
        resultadoLeitura = scanf("%f", &valor);

        if (resultadoLeitura != 1) {
            entradaInvalida = 1;
            printf("Entrada invalida (deve ser um numero)\n");
            while (getchar() != '\n');
        }
        else {
            entradaInvalida = (valor < 0);
            if (entradaInvalida) {
                printf("Salario nao pode ser negativo\n");
            }
        }

    } while (entradaInvalida);

    return valor;
}
void mostrarFuncionarios(char nome[][50], char email[][30], float salario[], int funcionarios) {
    if (funcionarios == 0){
        printf("\nNenhum funcionario cadastrado ainda.\n");
        return;
    }
    printf("\n %-4s %-30s %-25s %-s\n", "Ind", "Nome", "E-mail", "Salario"); //imprime um aalgo, ocupando um espaço de N caracteres, alinhada à esquerda (o '-' faz isso, sem o '-', alinharia à direita)
                                                                           // esses números garantem que as colunas fiquem alinhadas 
    for(int i = 0; i < funcionarios; i++){
         printf("%-4d %-30s %-25s %.2f\n", i + 1, nome[i], email[i], salario[i]);
    }
}
void limparBuffer(void){
    while (getchar() != '\n');
}
