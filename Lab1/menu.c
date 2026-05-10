#include <stdio.h>
#include <stdlib.h>

void insertion() {
    printf("\nInsertion of Element\n\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int pos;
    printf("Enter the position where you want to insert the element [0-%d]: ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos > n + 1) {
        printf("Invalid position");
        return;
    }
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }
}

void delete() {
    printf("\nDeletion of Element\n\n");
    int n;
    printf("Enter the Size of Array: ");
    scanf("%d", &n);
    int arr[n - 1];
    printf("Enter the Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int z, m = 0;
    printf("Enter the Element u want to  delete: ");
    scanf("%d", &z);
    for (int i = 0; i < n; i++) {
        if (arr[i] == z) {
            m++;
        }
        if (m > 0) {
            arr[i] = arr[i + 1];
        }
    }
    if (m == 0) {
        printf("No Element Found");
    } else {
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", arr[i]);
        }
    }
}

void linear() {
    printf("\nLinear Search\n\n");
    int n, search, result = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &search);
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            result = 1;
            break;
        }
    }
    if (result) {
        printf("Found");
    } else {
        printf("Not Found");
    }
}

void binary() {
    printf("\nBinary Search\n\n");
    int n, search, result = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int l = 0, h = n - 1;
    printf("Enter the number to search: ");
    scanf("%d", &search);
    while (l <= h) {
        int mid = (l + h) / 2;

        if (search == arr[mid]) {
            result = 1;
            break;
        } else if (search > arr[mid]) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    if (result) {
        printf("Found");
    } else {
        printf("Not Found");
    }
}

void bubble() {
    printf("\nBubble Sort\n\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void selection() {
    printf("\nSelection Sort\n\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    do {
        printf("1. Insertion at desired location\n");
        printf("2. Delete an element from the desired location\n");
        printf("3. Search an element using Linear Search\n");
        printf("4. Search an element using Binary Search\n");
        printf("5. Sort an array using Bubble sort\n");
        printf("6. Sort an array using Selection sort\n");
        int c;
        printf("Choose an option [1-6]: ");
        scanf("%d", &c);
        switch (c) {
        case 1:
            insertion();
            break;
        case 2:
            delete();
            break;
        case 3:
            linear();
            break;
        case 4:
            binary();
            break;
        case 5:
            bubble();
            break;
        case 6:
            selection();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid option");
            break;
        }
    } while (1);

    return 0;
}