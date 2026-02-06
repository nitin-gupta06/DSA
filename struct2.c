/*
2) Write a program that takes roll_no, fname, lname of 5 students and 
print the same records in ascending order on the basis of roll_no.
*/

#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char fname[50];
    char lname[50];
};

int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter roll number, first name, and last name of student %d: ", i + 1);
        scanf("%d %s %s", &students[i].roll_no, students[i].fname, students[i].lname);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nSorted student records:\n");
    for (int i = 0; i < 5; i++) {
        printf("Roll No: %d, First Name: %s, Last Name: %s\n", 
               students[i].roll_no, students[i].fname, students[i].lname);
    }

    return 0;
}