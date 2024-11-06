
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct arg_struct {
    int row;             // Row index for the row to be processed
    int **mat1;          // Pointer to the first matrix
    int **mat2;          // Pointer to the second matrix
    int **result;        // Pointer to the result matrix
    int cols;            // Number of columns 
};

void *add_row(void *arguments) {
    struct arg_struct *args = (struct arg_struct *)arguments;
    
    // Process the entire row by adding corresponding element
    for (int col = 0; col < args->cols; col++) {
        args->result[args->row][col] = args->mat1[args->row][col] + args->mat2[args->row][col];
    }
    
    pthread_exit(NULL);
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    // memory for mat1
    int **mat1 = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat1[i] = malloc(n * sizeof(int));
    }

    // mat2
    int **mat2 = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat2[i] = malloc(n * sizeof(int));
    }

    // result
    int **result = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = malloc(n * sizeof(int));
    }

    // Input mat1
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input mat2
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    pthread_t threads[m]; // array of threads
    struct arg_struct args[m]; // array of arguments for the threads

    // Creation threads
    for (int i = 0; i < m; i++) {
        args[i].row = i;
        args[i].mat1 = mat1;
        args[i].mat2 = mat2;
        args[i].result = result;
        args[i].cols = n; 
        pthread_create(&threads[i], NULL, add_row, (void *)&args[i]);
    }

    // wait for the threads
    for (int i = 0; i < m; i++) {
        pthread_join(threads[i], NULL);
    }

    // output
    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // freeing up
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
