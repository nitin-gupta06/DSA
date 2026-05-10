// Find the sum of each rows and columns of matrix of given order (row x column). Also find the total sum of all the rows and all the columns individually.

#include <stdio.h>

int main() {
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    int arr[row][col];
    printf("Enter elements of matrix: ");
    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int sum_row;
    int sum_col;
    for (int i = 0; i < row;i++) {
        sum_row = 0;
        for (int j = 0; j < col;j++) {
            sum_row += arr[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, sum_row);
    }

    for (int j = 0; j < col;j++) {
        sum_col = 0;
        for (int i = 0; i < row;i++) {
            sum_col += arr[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum_col);
    }
    int total = 0;
    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col;j++) {
            total += arr[i][j];
        }
    }
    printf("Total sum = %d", total);
    return 0;

}