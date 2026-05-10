/*
Write a menu driven program for all the operations in case of doubly circular linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Traversing/ Display of linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
}

void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        struct Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* tail = head->prev;

    if (tail == head) {
        head = NULL;
    } else {
        struct Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
    }
    free(tail);
}

void deleteFromPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or list is empty!\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != position) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp == head) {
        deleteFromBeginning();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head) {
        head = temp->next;
    }
    free(temp);
}

void searchElement(int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    int position = 1;

    do {
        if (temp->data == data) {
            printf("Element found at position: %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("Element not found in the list!\n");
}

void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    do{
        int choice, data, position;
        printf("Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the given position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from the given position\n");
        printf("7. Search an element\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;
        case 7:
            printf("Enter element to search: ");
            scanf("%d", &data);
            searchElement(data);
            break;
        case 8:
            displayList();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            break;
        }
    } while(1);

    return 0;
}