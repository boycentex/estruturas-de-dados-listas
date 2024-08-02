#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>


int main() {
    setlocale(LC_ALL, "portuguese");
	
	int n;
	printf("informe o numero de questões da prova\n");
	scanf("%d", &n);
	char *gabarito;
	char **respostas;
	int i, j;
	int certa = 0;
	int aprovados = 0;
	gabarito = (char*) malloc(n * sizeof(char));
	if(gabarito == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	printf("informe o gabrito da prova\n");
	for(i=0; i<n; i++){ 
		printf("resposta da %d° questão\n", i+1);
		scanf(" %c", &gabarito[i]);
	}
	respostas = (char**) malloc(10 * sizeof(char*));
		if(respostas == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	for(i=0; i<10; i++){ 
		respostas[i] = (char*) malloc(n * sizeof(char));
	}
	printf("respostas dos alunos\n");
	for(i=0; i<10; i++){ 
		printf("respostas do %d° aluno\n", i+1);
		for(j=0; j<n; j++){ 
			scanf(" %c", &respostas[i][j]);
		}
	}
	
	for(i=0; i<10; i++){ 
		certa=0;
		for(j=0; j<n; j++){ 
			if(respostas[i][j] == gabarito[j]){ 
				certa++;
			}
		}
		float nota = certa/n;
		printf("o %d° aluno tirou nota %.2f\n", i+1, nota);
		
		if(nota >= 6.0) {
            aprovados++;
	}
	
	float paprovados = (aprovados/10)*100.0;
	printf("a porcentagem de alunos aprovados foi de %.2f", paprovados);
	
	free(gabarito);
    for (i = 0; i < 5; i++) {
        free(respostas[i]);
    }
    free(respostas);
	
	return 0;
}
