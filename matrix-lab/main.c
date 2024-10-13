#include <stdio.h>

#define SIZE 5

typedef
    struct
{
    int v[SIZE][SIZE];
} MATRIX;


MATRIX addMatricies(MATRIX m1, MATRIX m2) {
    MATRIX finalm;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            finalm.v[i][j] = m1.v[i][j] + m2.v[i][j];
        }
    }
    return finalm;
}
MATRIX multiplyMatricies(MATRIX m1, MATRIX m2) {
    MATRIX finalm;
    for (int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            finalm.v[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                finalm.v[i][j] += m1.v[i][k] * m2.v[k][j];
            }

        }
    }
    return finalm;
}

MATRIX transposeMatrix(MATRIX m) {
    MATRIX finalm;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            finalm.v[i][j] = m.v[j][i];
        }
    }
    return finalm;

}

void printMatrix(MATRIX m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(j < SIZE - 1) {
                printf("%d, ", m.v[i][j]);
            }
            else {
                printf("%d\n", m.v[i][j]);
            }

        }
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };


    MATRIX matrix1;
    MATRIX matrix2;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            matrix1.v[i][j] = m1[i][j];
            matrix2.v[i][j] = m2[i][j];
        }
    }

    printf("Matrix A:\n");
    printMatrix(matrix1);
    printf("Matrix B:\n");
    printMatrix(matrix2);
    printf("A+B:\n");
    printMatrix(addMatricies(matrix1, matrix2));
    printf("A*B:\n");
    printMatrix(multiplyMatricies(matrix1, matrix2));
    printf("A*B transpose:\n");
    printMatrix(transposeMatrix(multiplyMatricies(matrix1, matrix2)));



}






