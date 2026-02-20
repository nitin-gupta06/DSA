/*
1) Create a structure named student that has name, roll no. and mark as members.
Assume an appropriate types and size of member. 
Write a program using structure to read and display the data entered by the user.
*/

#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    float mark;
};

int main() {
    struct student s;

    printf("Enter name: ");
    scanf("%[^\n]s", &s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);

    printf("Enter mark: ");
    scanf("%f", &s.mark);

    printf("\nStudent Information:\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.roll_no);
    printf("Mark: %.2f\n", s.mark);

    return 0;
}