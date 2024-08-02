#include<stdio.h>
#include<stdlib.h>

int main(){ 
	
	int linhas, colunas;
	printf("informe o numero de linhas\n");
	scanf("%d", &linhas);
	printf("informe o numero de colunas\n");
	scanf("%d", &colunas);
	int **mat;
	int i, j;
	mat = (int**) malloc(linhas * sizeof(int));
	if(mat == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	for(i=0; i<linhas; i++){ 
		mat[i] = (int*) malloc(colunas * sizeof(int));
	}
	printf("preencha a matriz\n");
	for(i=0; i<linhas; i++){ 
		for(j=0; j<colunas; j++){ 
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n");
	for(i=0; i<linhas; i++){ 
		for(j=0; j<colunas; j++){ 
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("sua transposta fica assim:\n");
	for(i=0; i<linhas; i++){ 
		for(j=0; j<colunas; j++){ 
			printf("%d ", mat[j][i]);
		}
		printf("\n");
	}	
	
	for(i=0; i<linhas; i++){ 
		free(mat[i]);
	}
	
	free(mat);
	
return 0;
}
