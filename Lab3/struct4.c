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
    struct employee employees[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter name of employee %d: ", i + 1);
       

    printf("\nEmployees in alphabetical order:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s", employees[i].name);
        printf("Address: %s", employees[i].address);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    return 0;
}