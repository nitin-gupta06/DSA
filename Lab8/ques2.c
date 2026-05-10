// Q2) Queue using linked list - insert, delete, display 
#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int data; 
    struct Node* next; 
}; 
struct Node *front = NULL, *rear = NULL; 

int isEmpty() { 
    return front == NULL; 
} 

void insert(int val) { 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = val; 
    new_node->next = NULL; 
    if (rear == NULL) { 
        front = rear = new_node; 
    } else { 
        rear->next = new_node; 
        rear = new_node; 
    } 
    printf("Inserted: %d\n", val); 
} 

void delete_elem() { 
    if (isEmpty()) { 
        printf("Queue is Empty!\n"); 
        return; 
    } 
    struct Node* temp = front; 
    printf("Deleted: %d\n", temp->data); 
    front = front->next; 
    if (front == NULL) 
        rear = NULL; 
    free(temp); 
} 

void display() { 
    if (isEmpty()) { 
        printf("Queue is Empty!\n"); 
        return; 
    } 
    struct Node* temp = front; 
    printf("Queue: "); 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 

int main() { 
    int choice, val; 
    while (1) { 
        printf("\n--- Menu ---\n"); 
        printf("1. Insert (Enqueue)\n"); 
        printf("2. Delete (Dequeue)\n"); 
        printf("3. Display\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &val); 
                insert(val); 
                break; 
            case 2: delete_elem(); break; 
            case 3: display(); break; 
            case 4: return 0; 
            default: printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
} 