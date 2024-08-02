#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>



int main() {
    setlocale(LC_ALL, "portuguese");
	
	int n;
	printf("informe o tamanho do vetor\n");
	scanf("%d", &n);

    int *v = (int*) malloc(n*sizeof(int));
    int i;
    printf("preencha o vetor de %d elementos\n", n);
    for(i=0; i<n; i++){ 
    	scanf("%d", &v[i]);
	}
	for(i=n; i>0; i--){ 
		printf("%d ", v[i-1]);
	}		    
    
    free(v);
    
	return 0;
}
