// Find the product of two matrices.

#include <stdio.h>

int main() {
    int row1, col1, row2, col2;
    printf("Enter number of rows of first matrix: ");
    scanf("%d", &row1);
    printf("Enter number of columns of first matrix: ");
    scanf("%d", &col1);
    printf("Enter number of rows of second matrix: ");
    scanf("%d", &row2);
    printf("Enter number of columns of second matrix: ");
    scanf("%d", &col2);

    int mat1[row1][col1];
    printf("Enter elements of first matrix: ");
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col1;j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    int mat2[row2][col2];
    printf("Enter elements of second matrix: ");
    for (int i = 0; i < row2;i++) {
        for (int j = 0; j < col2;j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    if (col1 != row2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }
    int product[row1][col2];
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col2;j++) {
            product[i][j] = 0;
            for (int k = 0; k < col1;k++) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Product of the two matrices is:\n");
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col2;j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}