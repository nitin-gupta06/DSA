// Find the product of two matrices.

int main(){
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    int arr[row][col];
    printf("Enter elements of matrix: ");
    for(int i=0; i<row;i++){
        for (int j=0; j<col;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    return 0;
}