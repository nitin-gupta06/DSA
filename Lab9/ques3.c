// Q2) Construct BST and perform search, traversals, deletion 
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
struct Node* insert(struct Node* root, int val) { 
    if (root == NULL) 
        return create_node(val); 
    if (val < root->data) 
        root->left = insert(root->left, val); 
    else if (val > root->data) 
        root->right = insert(root->right, val); 
    return root; 
} 
struct Node* search(struct Node* root, int key) { 
    if (root == NULL || root->data == key) 
        return root; 
    if (key < root->data) 
        return search(root->left, key); 
    else 
        return search(root->right, key); 
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
struct Node* find_min(struct Node* root) { 
    while (root->left != NULL) 
        root = root->left; 
    return root; 
} 
struct Node* delete_node(struct Node* root, int key) { 
    if (root == NULL) 
        return root; 
    if (key < root->data) 
        root->left = delete_node(root->left, key); 
    else if (key > root->data) 
        root->right = delete_node(root->right, key); 
    else { 
        // Node with one or no child 
        if (root->left == NULL) { 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
        // Node with two children - get inorder successor 
        struct Node* temp = find_min(root->right); 
        root->data = temp->data; 
        root->right = delete_node(root->right, temp->data); 
    } 
    return root; 
} 
int main() { 
    struct Node* root = NULL; 
    int choice, val; 
    while (1) { 
        printf("\n--- Menu ---\n"); 
        printf("1. Insert\n"); 
        printf("2. Search\n"); 
        printf("3. Inorder traversal\n"); 
        printf("4. Preorder traversal\n"); 
        printf("5. Postorder traversal\n"); 
        printf("6. Delete\n"); 
        printf("7. Exit\n"); 
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
                printf("Enter element to search: "); 
                scanf("%d", &val); 
                if (search(root, val) != NULL) 
                    printf("Element %d found.\n", val); 
                else 
                    printf("Element %d not found.\n", val); 
                break; 
            case 3: 
                printf("Inorder: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Preorder: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 5: 
                printf("Postorder: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 6: 
                printf("Enter element to delete: "); 
                scanf("%d", &val); 
                root = delete_node(root, val); 
                printf("Deleted (if existed).\n"); 
                break; 
            case 7: return 0; 
            default: printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
} 
  