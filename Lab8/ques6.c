// Q6) Implement a Queue using Stacks 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 100 
int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;
void push1(int val) {
    if (top1 == SIZE - 1) return;
    top1++;
    stack1[top1] = val;
}
int pop1() {
    if (top1 == -1) return -1;
    int val = stack1[top1];
    top1--;
    return val;
}
void push2(int val) {
    if (top2 == SIZE - 1) return;
    top2++;
    stack2[top2] = val;
}
int pop2() {
    if (top2 == -1) return -1;
    int val = stack2[top2];
    top2--;
    return val;
}
void enqueue(int val) {
    push1(val);
    printf("Enqueued: %d\n", val);
}
int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    int val = pop2();
    printf("Dequeued: %d\n", val);
    return val;
}
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 4: return 0;
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}