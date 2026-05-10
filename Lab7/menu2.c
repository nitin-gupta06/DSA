// Q 2) Reverse string using stack


#include <stdio.h> 
#include <string.h> 

#define MAX 100 
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1)
        return;
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    char ch = stack[top];
    top--;
    return ch;
}

int main() {
    char str[100], reversed[100];
    int i;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    int len = strlen(str);

    for (i = 0; i < len; i++)
        push(str[i]);
    for (i = 0; i < len; i++)
        reversed[i] = pop();
    reversed[i] = '\0';
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);
    return 0;
}