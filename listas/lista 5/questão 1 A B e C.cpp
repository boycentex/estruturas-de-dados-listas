#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct funcionario {
    char nome[30];
    float salario;
    int identificador;
    char cargo[40];
} Funcionario;

void preencher(Funcionario *funcionario) {
    printf("Informe os dados do funcionário\n");
    printf("Nome: ");
    scanf(" %[^\n]", funcionario->nome);
    printf("Salário: ");
    scanf("%f", &funcionario->salario);
    printf("Identificador: ");
    scanf("%d", &funcionario->identificador);
    printf("Cargo: ");
    scanf(" %[^\n]", funcionario->cargo);
}

void imprimir(Funcionario *funcionario) {
    printf("Os dados do funcionário são\n");
    printf("Nome: %s\n", funcionario->nome);
    printf("Salário: %.2f\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
}

void alterar_salario(Funcionario *funcionario) {
    printf("Informe o novo salário: ");
    scanf("%f", &funcionario->salario);
}

void liberar(Funcionario *funcionario) {
    free(funcionario);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    Funcionario *funcionario;
    funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencher(funcionario);
    imprimir(funcionario);

    char opcao;
    printf("Deseja alterar o salário do funcionário? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        alterar_salario(funcionario);
        printf("\n");
        imprimir(funcionario);
    } 
    
    liberar(funcionario);

    return 0;
}
