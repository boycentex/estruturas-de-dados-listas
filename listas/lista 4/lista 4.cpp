#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int costa(char **mat, int i, int j, int linhas, int colunas){ 
    if(mat[i][j] == '#'){ 
        if(i == 0 || mat[i-1][j] == '.') return 1;
        if(i == linhas-1 || mat[i+1][j] == '.') return 1;
        if(j == 0 || mat[i][j-1] == '.') return 1;
        if(j == colunas-1 || mat[i][j+1] == '.') return 1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    
    int linhas, colunas;
    printf("Informe o número de linhas: ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas: ");
    scanf("%d", &colunas);
    
    char **mat;
    mat = (char**) malloc(linhas * sizeof(char*));
    if(mat == NULL){ 
        printf("Erro na alocação\n");
        exit(1);
    }
    
    for(int i = 0; i < linhas; i++){ 
        mat[i] = (char*) malloc(colunas * sizeof(char));
        if(mat[i] == NULL){ 
            printf("Erro na alocação\n");
            exit(1);
        }
    }
    
    printf("Digite o mapa, use '.' para indicar água e '#' para indicar a costa:\n");
    for(int i = 0; i < linhas; i++){ 
        for(int j = 0; j < colunas; j++){ 
            scanf(" %c", &mat[i][j]);  
        }
    }
    
    for(int i = 0; i < linhas; i++){ 
        for(int j = 0; j < colunas; j++){ 
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    
    int cont = 0;
    for(int i = 0; i < linhas; i++){ 
        for(int j = 0; j < colunas; j++){ 
            if(costa(mat, i, j, linhas, colunas)){ 
                cont++;
            }
        }
    }
    
    printf("Saída = %d\n", cont);
    
    for(int i = 0; i < linhas; i++){ 
        free(mat[i]);
    } 
    free(mat);        
    
    return 0;
}
