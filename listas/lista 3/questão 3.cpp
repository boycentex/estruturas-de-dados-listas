#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){ 
	
	int n;
	printf("informe a ordem da matriz quadrada\n");
	scanf("%d", &n);
	int **mat;
	int i, j;
	mat = (int**) malloc(n * sizeof(int));
	if(mat == NULL){ 
		printf("erro na alocação\n");
		exit(1);
	}
	for(i=0; i<n; i++){ 
		mat[i] = (int*) malloc(n * sizeof(int));
	} 
	for(i=0; i<n; i++){ 
		for(j=0; j<n; j++){ 
			printf("%d ", rand() % 100);
		}
		printf("\n");
	}
	
	for(i=0; i<n; i++){ 
		free(mat[i]);
	} 
	
	free(mat);
	
return 0;
}
