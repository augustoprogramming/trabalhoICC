#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerInteiroNoIntervalo (int minimo, int maximo);
int lerOpcaoMenu(void);
int cadastrarNome(char nome[][50], int indice);
int cadastrarEmail(char email[][30], int indice);
int cadastrarSalario(float salario[], int indice);
float SalarioValido(void);
void mostrarFuncionarios(char nome[][50], char email[][30], float salario[], int funcionarios);
void buscarFuncionario(char nomes[][50], char emails[][30], float salarios[], int qtdFuncionarios);
void limparBuffer(void);
void pausar(void);
void limpar(void);
void calcularMedia(float salario[], int indice);
void mostrarMaiorSalario(char nome[][50], float salario[], int funcionarios);


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
                mostrarFuncionarios(nome, email, salario, funcionarios);
                break;

            case 3:
                buscarFuncionario(nome, email, salario, funcionarios);
                break;

            case 4:
                mostrarMaiorSalario(nome, salario, funcionarios);
                break;
            
            case 5:
                calcularMedia(salario, funcionarios);
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
    printf("\n %-4s %-50s %-30s %-s\n", "Ind", "Nome", "E-mail", "Salario"); 
    for(int i = 0; i < funcionarios; i++){
         printf("%-4d %-50s %-30s %.2f\n", i + 1, nome[i], email[i], salario[i]);
    }
}
void limparBuffer(void){
    while (getchar() != '\n');
}
void pausar(void){
    printf("\nAperte ENTER para continuar...");
    getchar();
}
void buscarFuncionario(char nomes[][50], char emails[][30], float salarios[], int qtdFuncionarios){
    char entrada[50];
    int encontrado = 0;
    limpar();

    if (qtdFuncionarios == 0){
        printf("Nao ha funcionarios cadastrados...\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Nome Completo: ");
    scanf(" %49[^\n]", entrada);

    for (int i = 0; i < qtdFuncionarios; i++){
        if (strcmp(entrada, nomes[i]) == 0){
            encontrado = 1;
            printf("\n------------------------------------------\n");
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Salario: R$ %.2f\n", salarios[i]);
            break;
        }
    }

    if (encontrado == 0){
        printf("\nNenhuma pessoa encontrada com esse nome\n");
    }

    limparBuffer();
    pausar();
    limpar();
}

void limpar(void){
    system("cls");
}

void calcularMedia(float salario[], int indice){
    if(indice == 0){
        printf("Nao ha funcionarios cadastrados.\n");
        limparBuffer();
        pausar();
        limpar();
        return;
    }

    float soma = 0;
    float mediaSalarial;
    for(int i = 0; i < indice; i++){
        soma += salario[i];
    }
    mediaSalarial = (soma/indice);
    printf("Media salarial dos funcionarios: R$ %.2f\n", mediaSalarial);
    limparBuffer();
    pausar();
    limpar();
    return;
}

    void mostrarMaiorSalario(char nome[][50], float salario[], int funcionarios){
        if (funcionarios == 0){
            printf("\nNenhum funcionario cadastrado ainda.\n");
            return;
        }

        int indiceMaior = 0;

        for (int i = 1; i < funcionarios; i++){
            if (salario[i] > salario[indiceMaior]){
                indiceMaior = i;
            }
        }

        printf("\nMaior salario eh: %.2f\n", salario[indiceMaior]);
        printf("\nFuncionario: %s\n", nome[indiceMaior]);
    }
