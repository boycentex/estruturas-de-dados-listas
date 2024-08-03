#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct pessoa {
    char nome[30];
    char cpf[12]; 
    int idade;
} Pessoa;

void preencher(Pessoa *pessoas, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Informe o nome da %d° pessoa\n", i + 1);
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Informe o CPF da %d° pessoa\n", i + 1);
        scanf("%s", pessoas[i].cpf);
        printf("Informe a idade da %d° pessoa\n", i + 1);
        scanf("%d", &pessoas[i].idade);
    }
}

void imprimir(Pessoa *pessoas, int n) {
    int i, x = 0, y = 0;
    int maior = pessoas[0].idade;
    int menor = pessoas[0].idade;

    for (i = 1; i < n; i++) {
        if (pessoas[i].idade > maior) {
            maior = pessoas[i].idade;
            x = i;
        }
        if (pessoas[i].idade < menor) {
            menor = pessoas[i].idade;
            y = i;
        }
    }

    printf("A pessoa mais velha chama-se %s e sua idade é de %d anos\n", pessoas[x].nome, maior);
    printf("A pessoa mais nova chama-se %s e sua idade é de %d anos\n", pessoas[y].nome, menor);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Informe o número de pessoas: ");
    scanf("%d", &n);

    Pessoa *pessoas = (Pessoa *)malloc(n * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencher(pessoas, n);
    imprimir(pessoas, n);

    free(pessoas);

    return 0;
}
