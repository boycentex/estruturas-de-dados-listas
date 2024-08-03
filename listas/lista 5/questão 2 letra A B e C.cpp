#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>


typedef struct pessoa{ 
	char nome[30];
	char cpf[11]; // numero do documento
	int idade;
}Pessoa;

void preencher(Pessoa *pessoa){ 
	printf("informe o nome da pessoa\n");
	scanf(" %[^\n]", pessoa->nome);
	printf("informe o CPF da pessoa\n");
	scanf("%s", &pessoa->cpf);
	printf("informe a idade da pessoa\n");
	scanf("%d", &pessoa->idade);
}

void imprimir(Pessoa *pessoa){ 
	printf("Nome: %s\n", pessoa->nome);
	printf("CPF: %s\n", pessoa->cpf);
	printf("Idade: %d\n", pessoa->idade);
}

void atualizar_idade(Pessoa *pessoa){ 
	printf("informe a nova idade\n");
	scanf("%d", &pessoa->idade);
}


int main() {
    setlocale(LC_ALL, "portuguese");
	
	Pessoa *pessoa;
	char resposta;
	pessoa = (Pessoa*) malloc(sizeof(Pessoa));
	if(pessoa == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	preencher(pessoa);
	imprimir(pessoa);
	printf("gostaria de atualizar a idade ?\n");
	scanf(" %c", &resposta);
	if(resposta == 's' || resposta == 'S'){ 
		atualizar_idade(pessoa);
		imprimir(pessoa);
	}
	
	free(pessoa);
	
	return 0;
}
