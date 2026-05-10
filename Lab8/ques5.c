// Q5) Implement a Stack using Queues 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 100 
int q1[SIZE], q2[SIZE]; 
int front1 = -1, rear1 = -1; 
int front2 = -1, rear2 = -1; 
void enq1(int val) { 
    if (front1 == -1) front1 = 0; 
    rear1++; 
    q1[rear1] = val; 
} 
int deq1() { 
    if (front1 == -1 || front1 > rear1) return -1; 
    int val = q1[front1]; 
    front1++; 
    if (front1 > rear1) front1 = rear1 = -1; 
    return val; 
} 
void enq2(int val) { 
    if (front2 == -1) front2 = 0; 
    rear2++; 
    q2[rear2] = val; 
} 
int deq2() { 
    if (front2 == -1 || front2 > rear2) return -1; 
    int val = q2[front2]; 
    front2++; 
    if (front2 > rear2) front2 = rear2 = -1; 
    return val; 
} 
int isEmpty1() { 
    return front1 == -1 || front1 > rear1; 
} 
void push(int val) { 
    enq2(val); 
    while (!isEmpty1()) { 
        enq2(deq1()); 
    } 
    // Swap q1 and q2 by transferring back 
    while (front2 != -1 && front2 <= rear2) { 
        enq1(deq2()); 
    } 
    printf("Pushed: %d\n", val); 
} 
int pop() { 
    if (isEmpty1()) { 
        printf("Stack is empty!\n"); 
        return -1; 
    } 
    int val = deq1(); 
    printf("Popped: %d\n", val); 
    return val; 
} 
void display() { 
    if (isEmpty1()) { 
        printf("Stack is empty!\n"); 
        return; 
    } 
    printf("Stack (top to bottom): "); 
    for (int i = front1; i <= rear1; i++) 
        printf("%d ", q1[i]); 
    printf("\n"); 
} 
int main() { 
    int choice, val; 
    while (1) { 
        printf("\n--- Menu ---\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Display\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &val); 
                push(val); 
                break; 
            case 2: pop(); break; 
            case 3: display(); break; 
            case 4: return 0; 
            default: printf("Invalid choice!\n"); 
        } 
    } 
    return 0; 
} 