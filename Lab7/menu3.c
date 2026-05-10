// Q 3) Convert infix to postfix expression using stack and array

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 


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

char peek() { 
    if (top == -1) 
        return '\0'; 
    return stack[top]; 
} 

int precedence(char op) { 
    if (op == '+' || op == '-') 
        return 1; 
    if (op == '*' || op == '/') 
        return 2; 
    if (op == '^') 
        return 3; 
    return 0; 
} 

void infix_to_postfix(char infix[], char postfix[]) { 
    int i, j = 0; 
    char ch; 
    for (i = 0; infix[i] != '\0'; i++) { 
        ch = infix[i]; 
        if (isalnum(ch)) { 
            postfix[j++] = ch; 
        } 
        else if (ch == '(') { 
            push(ch); 
        } 
        else if (ch == ')') { 
            while (top != -1 && peek() != '(') 
                postfix[j++] = pop(); 
            pop();
        } 
        else { 
            while (top != -1 && precedence(peek()) >= precedence(ch)) 
                postfix[j++] = pop(); 
            push(ch); 
        } 
    } 
    while (top != -1) 
        postfix[j++] = pop(); 
    postfix[j] = '\0'; 
} 

int main() { 
    char infix[100], postfix[100];    
    printf("Enter infix expression: "); 
    scanf("%s", infix); 
    infix_to_postfix(infix, postfix); 
    printf("Postfix expression: %s\n", postfix); 
    return 0; 
} 