#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<locale.h> 
#include<stdlib.h> 
#include<ctype.h>

void calcula_hexagono(float l, float *area, float *perimetro){
	
	*perimetro = (6*l);
	*area = (3 * pow(l, 2) * sqrt(3))/2; 
}

int main() {
    setlocale(LC_ALL, "portuguese");
	
	float l;
	float area, perimetro;
	printf("informe o valor para l\n");
	scanf("%f", &l);
	printf("valor informado foi %2.f\n", l);
	calcula_hexagono(l, &area, &perimetro);
	printf("o valor da area � igual a %.3f\n", area);
	printf("o valor do perimetro � igual a %.3f\n", perimetro);
	
	return 0;
}
