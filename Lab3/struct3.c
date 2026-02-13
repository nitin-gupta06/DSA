/*
Write a program that takes name, address, age and salary of the employee.
Take the data for n employees in an array and find the average salary.
*/

#include <stdio.h>

struct Employee {
    char name[50];
    char address[100];
    int age;
    float salary;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];
    float total = 0;

    for (int i = 0; i < n; i++) {
        printf("\n\nFor Employee: %d\n\n", i+1);

        printf("Enter name: ");
        scanf(" %[^\n]s", employees[i].name);

        printf("Enter address: ");
        scanf(" %[^\n]s", employees[i].address);

        printf("Enter age: ");
        scanf("%d", &employees[i].age);
        
        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);

        total += employees[i].salary;
    }

    float average = total / n;
    printf("\n\nAverage Salary: %.2f\n", average);

    return 0;
}