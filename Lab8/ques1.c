// Q1) Queue using array - insert, delete, display 
#include <stdio.h> 
#include <stdlib.h> 

#define SIZE 100 
int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void insert(int val) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = val;
    printf("Inserted: %d\n", val);
}

void delete_elem() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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