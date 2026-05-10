// Q2) Write a menu driven program for all the operations in two polynomials using singly linked list 
// Addition 
// Subtraction 
// multiplication  

#include <stdio.h> 
#include <stdlib.h> 

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node Node;

void insert(Node** poly, int coef, int exp) {
    if (coef == 0) return;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (*poly == NULL) {
        *poly = temp;
        return;
    }

    Node* current = *poly;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL)
            printf(" + ");
        current = current->next;
    }
    printf("\n");
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

Node* subtract(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef - poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, -(poly2->coef), poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert(&result, -(poly2->coef), poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

Node* multiply(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int new_coef = p1->coef * p2->coef;
            int new_exp = p1->exp + p2->exp;
            // Check if exponent already exists 
            Node* curr = result;
            int found = 0;
            while (curr != NULL) {
                if (curr->exp == new_exp) {
                    curr->coef += new_coef;
                    found = 1;
                    break;
                }
                curr = curr->next;
            }
            if (!found)
                insert(&result, new_coef, new_exp);
        }
    }
    return result;
}

void create_poly(Node** poly) {
    int n, coef, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient exponent) in decreasing order of exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insert(poly, coef, exp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int choice;
    printf("Enter first polynomial:\n");
    create_poly(&poly1);
    printf("Enter second polynomial:\n");
    create_poly(&poly2);
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display polynomials\n");
        printf("2. Addition\n");
        printf("3. Subtraction\n");
        printf("4. Multiplication\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("First polynomial: ");
            print(poly1);
            printf("Second polynomial: ");
            print(poly2);
            break;
        case 2:
            result = add(poly1, poly2);
            printf("Addition result: ");
            print(result);
            break;
        case 3:
            result = subtract(poly1, poly2);
            printf("Subtraction result: ");
            print(result);
            break;
        case 4:
            result = multiply(poly1, poly2);
            printf("Multiplication result: ");
            print(result);
            break;
        case 5: return 0;
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}