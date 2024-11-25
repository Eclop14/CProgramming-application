#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 100
#define COL 100

void fillRandom2DArray(int array[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = (rand() % 2001) - 1000;
        }
    }
}

void print2DArray(int array[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%4d] ", array[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int s1[ROW][COL], int s2[ROW][COL], int target[ROW][COL], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            target[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                target[i][j] += s1[i][k] * s2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];
    int row1, col1, row2, col2;

    srand(time(NULL));
    printf("Input matrix 1 row & col: ");
    scanf("%d %d", &row1, &col1);
    printf("Input matrix 2 row & col: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Matrix multiplication not possible. (col1 != row2)\n");
        return -1;
    }

    fillRandom2DArray(matrix1, row1, col1);
    fillRandom2DArray(matrix2, row2, col2);

    multiplyMatrix(matrix1, matrix2, result, row1, col1, col2);

    printf("\nMatrix 1:\n");
    print2DArray(matrix1, row1, col1);

    printf("\nMatrix 2:\n");
    print2DArray(matrix2, row2, col2);

    printf("\nResult of multiplication:\n");
    print2DArray(result, row1, col2);

    return 0;
}
