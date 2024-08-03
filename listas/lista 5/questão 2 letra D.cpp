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

void preencher(Pessoa *pessoa, int n){ 
	int i;
	for(i=0; i<n; i++){ 
	printf("informe o nome da %d° pessoa\n", i+1);
	scanf(" %[^\n]", pessoa[i].nome);
	printf("informe o CPF da %d° pessoa\n", i+1);
	scanf("%s", &pessoa[i].cpf);
	printf("informe a idade da %d° pessoa\n", i+1);
	scanf("%d", &pessoa[i].idade);
	}
}

void imprimir(Pessoa *pessoa, int n){ 
	int maior=0, menor=0;
	int i;
	int x=0;
	int j=0;
	maior = pessoa[0].idade;
	menor = pessoa[0].idade;
	for(i=1; i<n; i++){ 
		if(maior < pessoa[i].idade){ 
			maior = pessoa[i].idade;
			x=i;
		}
		if(menor > pessoa[i].idade){ 
			menor = pessoa[i].idade;
			j=i;
		}
	}
	printf("A pessoa mais velha chama-se %s e sua idade é de %d anos\n", pessoa[x].nome, maior);
	printf("A pessoa mais nova chama-se %s e sua idade é de %d anos\n", pessoa[j].nome, menor);
	
}


int main() {
    setlocale(LC_ALL, "portuguese");
	
	int n;
	printf("informe o numero de pessoas\n");
	scanf("%d", &n);
	Pessoa pessoa[n];
	
	preencher(pessoa, n);
	imprimir(pessoa, n);
	
	return 0;
}
