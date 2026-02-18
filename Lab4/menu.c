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

void create(){
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

}

void insert_begg(){
    printf("Inserting at the beginning of the linked list\n");



}

void insert_end(){
    printf("Inserting at the end of the linked list\n");


}

void insert_pos(){
    printf("Inserting at the given position of the linked list\n");

}

void delete_begg(){
    printf("Deleting from the beginning of the linked list\n");

}

void delete_end(){
    printf("Deleting from the end of the linked list\n");

}

void delete_pos(){
    printf("Deleting from the given position of the linked list\n");

}

void search(){
    printf("Searching an element in a given linked list\n");

}

void reverse(){
    printf("Reversing a linked list\n");

}

void merge(){
    printf("Merging two linked list\n");

}

void traverse(){
    printf("\n\nTraversing/ Display of linked list\n\n");

    struct node *ptr;
    if (start==NULL){
        printf("\nList is empty!\n");
        return;
    }else{
        ptr=start;
        printf("List Elements: \n");
        while(ptr!=NULL){
            printf("%d\n", ptr->info);
            ptr=ptr->next;
        }
        printf("-----------------------------------------------------------------");
    }
}

void detect_loop(){
    printf("Detecting loop in a linked list\n");

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