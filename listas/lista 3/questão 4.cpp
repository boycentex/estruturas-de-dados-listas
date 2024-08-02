#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>

int main(){ 
	setlocale(LC_ALL, "portuguese");
	
	int n;
	printf("informe o numero de pessoas\n");
	scanf("%d", &n);
	char **nomes;
	int *v;
	int i;
	nomes = (char**) malloc(n * sizeof(char*));
	v = (int*) malloc(n * sizeof(int));
	if(nomes == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	if(v == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	for(i=0; i<n; i++){ 
		nomes[i] = (char*) malloc(100 * sizeof(char));
	} 
	printf("digite os nomes das %d pessoas\n", n);
	for(i=0; i<n; i++){ 
		printf("informe o %d° nome: ", i+1);
		while (getchar() != '\n');
		scanf("%[^\n]", nomes[i]);
		printf("agora informe a idade de %s\n", nomes[i]);
		scanf("%d", &v[i]);
	}
	printf("\n");
	for(i=0; i<n; i++){ 
		printf("%s tem %d anos\n", nomes[i], v[i]);
	}

	for(i=0; i<n; i++){ 
		free(nomes[i]);
	} 
	
	free(nomes);
	free(v);
	
return 0;
}
