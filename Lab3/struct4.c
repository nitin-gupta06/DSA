/*
Write a program to read the name, address, and salary of 5 employees using array of structure.
Display information of each employee in alphabetical order of their name.
*/

#include <stdio.h>
#include <string.h>

struct employee {
    char name[50];
    char address[100];
    float salary;
};

int main() {
    struct employee emp[5], temp;
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("\n\nDetails of Employee %d\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]s", emp[i].name);

        printf("Enter address: ");
        scanf(" %[^\n]s", emp[i].address);

        printf("Enter salary: ");
        scanf("%f", &emp[i].salary);
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(emp[i].name, emp[j].name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
    printf("\nEmployees in alphabetical order:\n");
    for (i = 0; i < 5; i++) {
        printf("\nName: %s", emp[i].name);
        printf("\nAddress: %s", emp[i].address);
        printf("\nSalary: %.2f\n", emp[i].salary);
    }

    return 0;
}
