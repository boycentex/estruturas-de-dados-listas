#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum genero{masculino, feminino};

typedef struct pessoa{ 
	char nome[50];
	int idade;
	genero genero;
}Pessoa;


int main(){ 
	
	Pessoa p;
	
	int opcao;
	printf("informe seu genero\n");
	printf("0 para masculino e 1 para feminino\n");
	scanf("%d", &opcao);
	switch (opcao){ 
	case 0:
	p.genero = masculino;
	break;
	case 1:
	p.genero=feminino;
	break;
	default:
	printf("opção invalida\n");
	return 1;
	}
	
	printf("Informe seu nome\n");
    scanf(" %[^\n]", p.nome);
    printf("Informe sua idade\n");
    scanf("%d", &p.idade);
	printf("\n");
	printf("Nome: %s\n", p.nome);
	printf("Idade: %d\n", p.idade);
	printf("Genero: %s\n", p.genero==masculino ? "masculino" : "feminino");
	
return 0;
}
