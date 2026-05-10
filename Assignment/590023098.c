#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int sapID;
    char name[50];
    int year;
    int semester;
    float cgpa;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *stackTop = NULL;

struct Node *qFront = NULL, *qRear = NULL;

struct Node* createNode(int sapID, char name[], int year, int semester, float cgpa) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sapID = sapID;
    strcpy(newNode->name, name);
    newNode->year = year;
    newNode->semester = semester;
    newNode->cgpa = cgpa;
    newNode->next = NULL;
    return newNode;
}

void addStudent() {
    int sapID, year, semester;
    char name[50];
    float cgpa;

    printf("Enter SAP ID: ");
    scanf("%d", &sapID);
    printf("Enter Name: ");
    scanf(" %49[^\n]", name);
    printf("Enter Year: ");
    scanf("%d", &year);
    printf("Enter Semester: ");
    scanf("%d", &semester);
    printf("Enter CGPA: ");
    scanf("%f", &cgpa);

    struct Node *newNode = createNode(sapID, name, year, semester, cgpa);

    if (head == NULL) head = newNode;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student added.\n");
}

void displayAll() {
    struct Node *temp = head;

    if (!temp) {
        printf("No records.\n");
        return;
    }

    while (temp != NULL) {
        printf("SAP ID: %d, Name: %s, Year: %d, Semester: %d, CGPA: %.2f\n",
               temp->sapID, temp->name, temp->year, temp->semester, temp->cgpa);
        temp = temp->next;
    }
}

void push(struct Node *node) {
    struct Node *newNode = createNode(node->sapID, node->name, node->year, node->semester, node->cgpa);
    newNode->next = stackTop;
    stackTop = newNode;
}

struct Node* pop() {
    if (stackTop == NULL) return NULL;

    struct Node *temp = stackTop;
    stackTop = stackTop->next;
    return temp;
}


void deleteStudent() {
    int sapID;
    printf("Enter SAP ID to delete: ");
    scanf("%d", &sapID);

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->sapID != sapID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Not found.\n");
        return;
    }

    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;

    push(temp);
    free(temp);

    printf("Deleted.\n");
}

void undoDelete() {
    struct Node *node = pop();

    if (node == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    if (head == NULL) head = node;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }

    printf("Restored.\n");
}


void sortBySapID() {
    struct Node *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->sapID > j->sapID) {

                int sapID = i->sapID;
                char name[50];
                strcpy(name, i->name);
                int year = i->year;
                int semester = i->semester;
                float cgpa = i->cgpa;

                i->sapID = j->sapID;
                strcpy(i->name, j->name);
                i->year = j->year;
                i->semester = j->semester;
                i->cgpa = j->cgpa;

                j->sapID = sapID;
                strcpy(j->name, name);
                j->year = year;
                j->semester = semester;
                j->cgpa = cgpa;
            }
        }
    }

    printf("Sorted by SAP ID:\n");
    displayAll();
}

void sortByName() {
    struct Node *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {

                int sapID = i->sapID;
                char name[50];
                strcpy(name, i->name);
                int year = i->year;
                int semester = i->semester;
                float cgpa = i->cgpa;

                i->sapID = j->sapID;
                strcpy(i->name, j->name);
                i->year = j->year;
                i->semester = j->semester;
                i->cgpa = j->cgpa;

                j->sapID = sapID;
                strcpy(j->name, name);
                j->year = year;
                j->semester = semester;
                j->cgpa = cgpa;
            }
        }
    }

    printf("Sorted by Name:\n");
    displayAll();
}


void enqueue(struct Node *node) {
    struct Node *newNode = createNode(node->sapID, node->name, node->year, node->semester, node->cgpa);

    if (qRear == NULL) {
        qFront = qRear = newNode;
    } else {
        qRear->next = newNode;
        qRear = newNode;
    }
}

struct Node* dequeue() {
    if (qFront == NULL) return NULL;

    struct Node *temp = qFront;
    qFront = qFront->next;

    if (qFront == NULL)
        qRear = NULL;

    return temp;
}

void processQueue() {
    if (head == NULL) {
        printf("No records.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        enqueue(temp);
        temp = temp->next;
    }

    struct Node *node;
    while ((node = dequeue()) != NULL) {
        printf("SAP ID: %d, Name: %s, Year: %d, Semester: %d, CGPA: %.2f\n",
               node->sapID, node->name, node->year, node->semester, node->cgpa);
        free(node);
    }
}


int main() {
    int choice;

    do {
        printf("\n1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Delete Student\n");
        printf("4. Undo Delete\n");
        printf("5. Sort by SAP ID\n");
        printf("6. Sort by Name\n");
        printf("7. Process Queue\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: deleteStudent(); break;
            case 4: undoDelete(); break;
            case 5: sortBySapID(); break;
            case 6: sortByName(); break;
            case 7: processQueue(); break;
            case 8: printf("Exit.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}