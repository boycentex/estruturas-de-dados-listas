#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>

#define OPNIAO "gostou\n"
#define OPNIAO2 "nao gostou\n"

int main() {
    setlocale(LC_ALL, "portuguese");
	
	int n;
	printf("informe o numero de entrevistados\n");
	scanf("%d", &n);
	char **opniao;
	char *sexo;
	int i;
	int masculino = 0;
	int feminino = 0;
	int gostou=0, ngostou=0;
	
	opniao = (char**) malloc(n * sizeof(char*));
	if(opniao == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	sexo = (char*) malloc(n * sizeof(char));
	if(sexo == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	for(i=0; i<n; i++){ 
		opniao[i] = (char*) malloc(20 * sizeof(char));
        if (opniao[i] == NULL) {
            printf("Erro ao alocar memória para as colunas.\n");
            exit(1);
        }
	}
	
	for(i=0; i<n; i++){ 
		printf("informe o sexo da %d° pessoa\n", i+1);
		scanf(" %c", &sexo[i]);
		printf("informe o opnião da %d° pessoa\n", i+1);
		getchar();
		fgets(opniao[i], 20, stdin) != NULL;
	}
	
	for(i=0; i<n; i++){ 
		if(sexo[i] == 'M' || sexo[i] == 'm'){ 
			masculino++;
		}
		if (sexo[i] == 'F' || sexo[i] == 'f'){ 
			feminino++;
		}
		if(strcmp(opniao[i], OPNIAO) == 0){ 
			gostou++;
		}
		if(strcmp(opniao[i], OPNIAO2) == 0){ 
			ngostou++;
		}
	}
	float pfeminino = 0;
	float pmasculino = 0;
	
	if (feminino > 0) {
    	pfeminino = ((float) gostou / feminino) * 100.0;
	}
	if (masculino > 0) {
    	pmasculino = ((float) ngostou / masculino) * 100.0;
	}
	
	printf("a porcentagem do sexo feminino que gostaram foi de %.2f\n", pfeminino);
	printf("a porcentagem do sexo masculino que não gostaram foi de %.2f \n", pmasculino);
	
	for (i = 0; i < n; i++) {
        free(opniao[i]);
    }
    free(opniao);
    free(sexo);
	
	return 0;
}
