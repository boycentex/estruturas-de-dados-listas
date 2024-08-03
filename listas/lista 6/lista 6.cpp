#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>

#define MAX_VAGAS 5 
#define MAX_TURMAS 3

void Bem_Vindo(){ 
	printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
	printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
	printf("funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
	printf("Autor: Ada Lovelace Versao: 1.0\n");
}

void menu(){ 
	printf("escolha uma opção\n");
	printf("1 – Criar turma\n");
	printf("2 – Listar turmas\n");
	printf("3 – Matricular aluno\n");
	printf("4 – Lancar notas\n");
	printf("5 – Listar alunos\n");
	printf("6 – Sair\n");
}

typedef struct aluno{ 
	int mat;
	char nome[81];
	float notas[3];
	float media;
}Aluno;

typedef struct turma{ 
	char id;
	int vagas;
	Aluno *alunos[MAX_VAGAS];
}Turma;

Turma *turmas[MAX_TURMAS];

Turma* criar_turma(char id){ 
	Turma *novaturma = (Turma*) malloc(sizeof(Turma));
	if(novaturma == NULL){ 
		printf("erro na alocação de memoria\n");
		exit(1);
	}
	novaturma->id = id;
	novaturma->vagas = MAX_VAGAS;
	int i;
	for(i=0; i< MAX_VAGAS; i++){ 
		novaturma->alunos[i] = NULL;
	}
	
	return novaturma;
}

void listar_turmas(Turma **turmas, int n){ 
	printf("Lista de Turmas:\n");
	int i;
	for (i = 0; i < n; i++){ 
		if(turmas[i] != NULL){ 
			printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
		}
	}
}

void matricular_aluno(Turma* turma, int mat, char* nome){ 
	if (turma == NULL) {
        printf("Turma não existe.\n");
        return;
    }
	
	if (turma->vagas <= 0) {
        printf("Não há vagas disponíveis nesta turma.\n");
        return;
    }
	
	Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
	if(novo==NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	
	novo->mat = mat;
    strcpy(novo->nome, nome);
    novo->notas[0] = 0.0; 
    novo->notas[1] = 0.0;
    novo->notas[2] = 0.0;
    novo->media = 0.0;
    
	int i;
	for (i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            turma->alunos[i] = novo;
            break;
        }
    }
	turma->vagas--;
	printf("Aluno matriculado com sucesso na turma %c.\n", turma->id);
}

void lancar_notas(Turma *turma){ 
	if (turma == NULL) {
        printf("Turma não existe.\n");
        return;
    }
    int mat;
    printf("informe o numero da matricula do aluno\n");
	scanf("%d", &mat);	
    int i;
    Aluno *aluno = NULL;
    for (i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL && turma->alunos[i]->mat == mat) {
            aluno = turma->alunos[i];
            break;
        }
    }
    
    if (aluno == NULL) {
        printf("Aluno não encontrado nesta turma.\n");
        return;
    }
    
    printf("informe as 3 notas do aluno\n");
    for(i=0; i<3; i++){ 
    	scanf("%f", &aluno->notas[i]);
	}
    printf("notas cadastradas com sucesso\n");
    
    aluno->media = (aluno->notas[0] + aluno->notas[1] + aluno->notas[2]) / 3.0;
    printf("Media do aluno: %.2f\n", aluno->media);
    
}

void imprimir_turmas(Turma **turmas, int n){ 
	printf("Dados das Turmas\n");
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("Turma %c - %d vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
            
        }
    }
    printf("\n");
}

Turma* procurar(Turma **turmas, int n, char id){ 
	int i;
	for (i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id){
            return turmas[i];
        }
    }
    return NULL;
}

int main() {
    setlocale(LC_ALL, "portuguese");
	
	Bem_Vindo();
    printf("\n");
    int opcao = 0;
    char id;
    int cont = 0;
    int mat;
    char nome[81];

    while (opcao != 6) {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (cont < MAX_TURMAS) {
                printf("Digite um id para a turma\n");
                scanf(" %c", &id);
                turmas[cont] = criar_turma(id);
                cont++;
                printf("Turma %c criada com sucesso\n", id);
                printf("\n");
            } else {
                printf("Número máximo de turmas atingido.\n");
            }
        }

        if (opcao == 2) {
            listar_turmas(turmas, MAX_TURMAS);
        }

        if (opcao == 3) {
            printf("Digite o id da turma para matricular o aluno\n");
            scanf(" %c", &id);
            printf("Digite o número de matrícula do aluno\n");
            scanf("%d", &mat);
            printf("Digite o nome do aluno\n");
            scanf(" %[^\n]", nome);

            Turma* turma = NULL;
            for (int i = 0; i < cont; i++) {
                if (turmas[i]->id == id) {
                    turma = turmas[i];
                    break;
                }
            }

            if (turma != NULL) {
                matricular_aluno(turma, mat, nome);
            } else {
                printf("Turma não encontrada.\n");
            }
        }
        
        if(opcao == 4){ 
        	printf("Digite o id da turma para lançar as notas\n");
            scanf(" %c", &id);

            Turma* turma = NULL;
            for (int i = 0; i < cont; i++) {
                if (turmas[i]->id == id) {
                    turma = turmas[i];
                    break;
                }
            }

            if (turma != NULL) {
                lancar_notas(turma);
            } else {
                printf("Turma não encontrada.\n");
            }
        }
        
		if(opcao == 5){ 
			imprimir_turmas(turmas, cont);
		}
    }
    
	printf("Obrigado por usar este programa!\n");	
	
	return 0;
}
