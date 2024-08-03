#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct funcionario {
    char nome[30];
    float salario;
    int identificador;
    char cargo[40];
} Funcionario;

void preencher(Funcionario *funcionarios, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Informe os dados do %d° funcionário\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);
        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
        printf("Identificador: ");
        scanf("%d", &funcionarios[i].identificador);
        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[i].cargo);
    }
}

void maior_menor(Funcionario *funcionarios, int n) {
    float maior = funcionarios[0].salario;
    float menor = funcionarios[0].salario;
    int i, indice_maior = 0, indice_menor = 0;

    for (i = 1; i < n; i++) {
        if (funcionarios[i].salario > maior) {
            maior = funcionarios[i].salario;
            indice_maior = i;
        }
        if (funcionarios[i].salario < menor) {
            menor = funcionarios[i].salario;
            indice_menor = i;
        }
    }

    printf("O funcionário com o maior salário ganha %.2f e seu cargo é %s\n", maior, funcionarios[indice_maior].cargo);
    printf("O funcionário com o menor salário ganha %.2f e seu cargo é %s\n", menor, funcionarios[indice_menor].cargo);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Informe o número de funcionários: ");
    scanf("%d", &n);

    Funcionario *funcionarios = (Funcionario *)malloc(n * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencher(funcionarios, n);
    maior_menor(funcionarios, n);

    free(funcionarios);

    return 0;
}
