// Q1b) Implement binary tree using linked list 
#include <stdio.h> 
#include <stdlib.h> 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create_node(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// Insert in level order 
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return create_node(val);
    // Use a simple queue for level order insertion 
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = create_node(val);
            return root;
        } else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = create_node(val);
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
            printf("Inserted: %d\n", val);
            break;
        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5: return 0;
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}