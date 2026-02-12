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
    struct Student students[5], temp;

    for (int i = 0; i < 5; i++) {
        printf("Detail of student %d", i+1);

        printf("Enter roll no. : ");
        scanf("%d", &students[i].roll_no);

        printf("Enter first name: ");
        scanf("%s", &students[i].fname);

        printf("Enter last name: ");
        scanf("%s", &students[i].lname);
    }

    for (int i = 0; i < 5-1; i++) {
        for (int j = 0; j < 5 - 1 - i; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    

    return 0;
}