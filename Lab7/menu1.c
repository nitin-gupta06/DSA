// Q1) Implement all stack operations using array and linked list: Push, Pop, display, peek.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* top = NULL;

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data) {
    struct node* newnode = createnode(data);
    if (top == NULL) {
        top = newnode;
    } else {
        newnode->next = top;
        top = newnode;
    }
}
void pop() {
    if (top == NULL) {
        printf("the list is empty\n");
    } else {
        struct node* temp = top;
        top->next = top;
        free(temp);
    }
}
void display() {
    struct node* temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element = %d\n", top->data);
    }
}

void reverse() {
    struct node* prev = NULL;
    struct node* current = top;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}
int main() {
    int choice, data;

    do {
        printf("\n     STACK MENU     \n");
        printf("1) Push element in stack\n");
        printf("2) Pop element from stack\n");
        printf("3) Display stack\n");
        printf("4) Peek top element\n");
        printf("5) reverse stack\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            peek();
        } else if (choice == 5) {
            reverse();
        } else if (choice == 6) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}