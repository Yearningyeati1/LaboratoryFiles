#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct arg_struct {
    int row;         
    int col;            
    int **mat1;        
    int **mat2;          
    int **result;        
};

void *add_element(void *arguments) {
    struct arg_struct *args = (struct arg_struct *)arguments;
    
  
    args->result[args->row][args->col] = args->mat1[args->row][args->col] + args->mat2[args->row][args->col];
    
    pthread_exit(NULL);
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
   
    int **mat1 = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat1[i] = malloc(n * sizeof(int));
    }

    
    int **mat2 = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat2[i] = malloc(n * sizeof(int));
    }

    
    int **result = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = malloc(n * sizeof(int));
    }


    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

   
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    pthread_t threads[m][n]; 
    struct arg_struct args[m][n]; 

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            args[i][j].row = i;
            args[i][j].col = j;
            args[i][j].mat1 = mat1;
            args[i][j].mat2 = mat2;
            args[i][j].result = result;
            pthread_create(&threads[i][j], NULL, add_element, (void *)&args[i][j]);
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }


    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

  
    for (int i = 0; i < m; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(result[i]);
    }
    free(mat1);
    free(mat2);
    free(result);

    return 0;
}
