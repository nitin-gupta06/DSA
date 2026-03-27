/*
Q 1) Write a menu driven program for all the operations in case of singly linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Reversing a linked list
i)	Merging two linked list
j)	Traversing/ Display of linked list
k)	Detect loop in a linked list 
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

int getCount(struct node *start){
    int count = 0;
    struct node *temp = start;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void create(){
    struct node *temp, *ptr;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if(start == NULL){
        start = temp;
    } else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void insert_begin(){
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &temp->info);

    temp->next = start;
    start = temp;
}

void insert_end(){
    printf("Inserting at the end of the linked list\n");
    struct node *temp, *ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("\nOut of memory. exiting\n");
        exit(0);
    }
    printf("Enter the data values for node: ");
    scanf("%d", &temp->info);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    } else {
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("\n-----------------------------------------------------------------\n\n");
}

void insert_pos(){
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    int count = getCount(start);

    if(pos < 0 || pos > count){
        printf("Invalid position\n");
        return;
    }

    if(pos == 0){
        insert_begin();
        return;
    }

    struct node *temp, *ptr = start;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &temp->info);

    for(i = 0; i < pos - 1; i++)
        ptr = ptr->next;

    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin(){
    if(start == NULL){
        printf("List empty\n");
        return;
    }

    struct node *temp = start;
    start = start->next;

    printf("Deleted: %d\n", temp->info);
    free(temp);
}

void delete_end(){
    if(start == NULL){
        printf("List empty\n");
        return;
    }

    struct node *ptr = start, *prev;

    if(start->next == NULL){
        printf("Deleted: %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }

    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    printf("Deleted: %d\n", ptr->info);
    free(ptr);
}

void delete_pos(){
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    int count = getCount(start);

    if(pos < 0 || pos >= count){
        printf("Invalid position\n");
        return;
    }

    struct node *ptr = start, *prev;

    if(pos == 0){
        delete_begin();
        return;
    }

    for(i = 0; i < pos; i++){
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = ptr->next;
    printf("Deleted: %d\n", ptr->info);
    free(ptr);
}

void search(){
    int key, pos = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct node *temp = start;

    while(temp != NULL){
        if(temp->info == key){
            printf("Found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    printf("Not found\n");
}

void reverse(){
    struct node *prev = NULL, *curr = start, *next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    start = prev;
    printf("List reversed\n");
}

void merge(){
    struct node *start2 = NULL, *temp, *ptr;
    int n, val;

    printf("Enter number of elements in second list: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &temp->info);
        temp->next = NULL;

        if(start2 == NULL){
            start2 = temp;
        } else {
            ptr = start2;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    if(start == NULL){
        start = start2;
        return;
    }

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = start2;

    printf("Lists merged\n");
}

void traverse(){
    struct node *ptr = start;

    if(ptr == NULL){
        printf("List empty\n");
        return;
    }

    printf("List:\n");
    while(ptr != NULL){
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


void detect_loop(){
    struct node *slow = start, *fast = start;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            printf("Loop detected\n");
            return;
        }
    }

    printf("No loop\n");
}

int main(){
    do{
        printf("\n\nSelect an option:\n\n");
        printf("0. Cretae a linklist.\n");
        printf("1. Insert at the beginning of the linked list\n");
        printf("2. Insert at the end of the linked list\n");
        printf("3. Insert at the given position of the linked list\n");
        printf("4. Delete from the beginning of the linked list\n");
        printf("5. Delete from the end of the linked list\n");
        printf("6. Delete from the given position of the linked list\n");
        printf("7. Search an element in a given linked list\n");
        printf("8. Reversing a linked list\n");
        printf("9. Merging two linked list\n");
        printf("10. Traversing/ Display of linked list\n");
        printf("11. Detect loop in a linked list\n");
        printf("12. Exit\n\n");

        printf("Enter an option from [0-12]: ");
        int choice;
        scanf("%d", &choice);

        printf("\n-----------------------------------------------------------------\n\n");

        switch(choice){
            case 0:
                create();
                break;
            case 1:
                insert_begg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                delete_begg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_pos();
                break;
            case 7:
                search();
                break;
            case 8:
                reverse();
                break;
            case 9:
                merge();
                break;
            case 10:
                traverse();
                break;
            case 11:
                detect_loop();
                break;
            case 12:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(1);



    return 0;
}
