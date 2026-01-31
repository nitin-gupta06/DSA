// Find sum of all array elements using iteration and recursion.

#include <stdio.h>
#include <stdlib.h>

int sum_recursion(int arr[], int n){
    if(n <= 0)
        return 0;
    return arr[n-1] + sum_recursion(arr, n-1);
}

int sum_iteration(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int c;
    printf("Choose method to calculate sum:\n1. Iteration\n2. Recursion\n3. Exit\n");
    scanf("%d", &c);

    switch (c){
    case 1:
        printf("Sum of all elements: %d\n", sum_iteration(arr, n));
        break;
    case 2:
        printf("Sum of all elements: %d\n", sum_recursion(arr, n));
        break;
    case 3:
        exit(0);
    default:
        break;
    }

    return 0;
}

