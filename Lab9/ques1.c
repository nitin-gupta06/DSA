// Q1a) Implement binary tree using array 
#include <stdio.h> 
#define SIZE 100 
int tree[SIZE];
int n = 0;
void insert(int val) {
    if (n >= SIZE) {
        printf("Tree is full!\n");
        return;
    }
    tree[n] = val;
    n++;
    printf("Inserted: %d\n", val);
}
void display() {
    if (n == 0) {
        printf("Tree is empty!\n");
        return;
    }
    printf("Tree (level order): ");
    for (int i = 0; i < n; i++)
        printf("%d ", tree[i]);
    printf("\n");
}
void inorder(int i) {
    if (i >= n) return;
    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}
void preorder(int i) {
    if (i >= n) return;
    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}
void postorder(int i) {
    if (i >= n) return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}
int main() {
    int choice, val;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display (level order)\n");
        printf("3. Inorder traversal\n");
        printf("4. Preorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2: display(); break;
        case 3:
            printf("Inorder: ");
            inorder(0);
            printf("\n");
            break;
        case 4:
            printf("Preorder: ");
            preorder(0);
            printf("\n");
            break;
        case 5:
            printf("Postorder: ");
            postorder(0);
            printf("\n");
            break;
        case 6: return 0;
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}