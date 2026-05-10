// Q 2) Write a menu driven program for all the operations in case of singly circular linked list
// a)	Insert at the beginning of the linked list
// b)	Insert at the end of the linked list
// c)	Insert at the given position of the linked list
// d)	Delete from the beginning of the linked list
// e)	Delete from the end of the linked list
// f)	Delete from the given position of the linked list
// g)	Search an element in a given linked list
// h)	Reversing a linked list
// i)	Traversing/ Display of linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
};

void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    printf("the next list is \n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void insertatbegnning(int data) {
    struct node* newnode = createnode(data);
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insertatend(int data) {
    struct node* newnode = createnode(data);
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
    }

}

void insertatindex(int pos, int data) {
    struct node* newnode = createnode(data);
    struct node* temp = head;
    int count = 1;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    if (pos<1 || pos>count + 1) {
        printf("invalid input ");
        return;
    }
    temp = head;
    int i = 1;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefrombeginning() {
    struct node* temp = head;
    if (head->next == head) {
        free(head);
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
}

void deletelastnode() {
    struct node* temp = head;
    if (head->next == head) {
        free(head);
        return;
    }
    struct node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    while (temp->next->next != head) {
        temp = temp->next;
    }
    temp->next = head;
    free(last);

}

void deleteatindex(int pos) {

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    // count nodes
    int count = 1;
    struct node* t = head;

    while (t->next != head) {
        count++;
        t = t->next;
    }

    if (pos < 1 || pos > count) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {

        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        struct node* del = head;
        head = head->next;
        last->next = head;
        free(del);
        return;
    }

    struct node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void search(int data) {
    struct node* temp = head;
    int pos = 1;
    while (temp->data != data) {
        temp = temp->next;
        if (temp->data == data) {
            printf("element found at %d ", pos);
        }
        pos++;
        break;
    }
}

void reverse() {
    if (head == NULL || head->next == head) {
        return;
    }

    struct node* prev = NULL, * curr = head, * next = NULL;
    struct node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

int main() {
    do {
        printf("1 insert at begnning\n");
        printf("2 insert at end \n");
        printf("3 insert at index\n");
        printf("4 detele from beginning \n");
        printf("5 delete the last node \n");
        printf("6 delete at usewr given index \n");
        printf("7 enter the element to be searched \n");
        printf("8. Reverse the linked list \n");
        printf("9. Traverse the linked list \n");
        printf("10. Exit\n");
        printf("enter choice:\n");
        int n;
        scanf("%d", &n);
        int data, pos;
        switch (n) {
        case 1:
            printf("enter the data to be inserted \n");
            scanf("%d", &data);
            insertatbegnning(data);
            break;
        case 2:
            printf("enter the data to be inserted \n");
            scanf("%d", &data);
            insertatend(data);
            break;
        case 3:
            printf("enter the data to be inserted \n");
            scanf("%d", &data);
            printf("enter the position to be inserted \n");
            scanf("%d", &pos);
            insertatindex(pos, data);
            break;
        case 4:
            deletefrombeginning();
            break;
        case 5:
            deletelastnode();
            break;
        case 6:
            printf("enter the position to be deleted \n");
            scanf("%d", &pos);
            deleteatindex(pos);
            break;
        case 7:
            printf("enter the element to be searched \n");
            scanf("%d", &data);
            search(data);
            break;
        case 8:
            reverse();
            break;
        case 9:
            traverse();
            break;
        case 10:
            exit(0);
        default:
            printf("invalid input \n");
        }
    } while (1);
    return 0;
}