// Q4) Evaluate postfix expression using stack and array. 

#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 

#define MAX 100 
int stack[MAX]; 
int top = -1; 

void push(int val) { 
    if (top == MAX - 1) 
        return; 
    top++; 
    stack[top] = val; 
} 

int pop() { 
    if (top == -1) 
        return -1; 
    int val = stack[top]; 
    top--; 
    return val; 
} 

int evaluate(char postfix[]) { 
    int i, a, b; 
    char ch; 
    for (i = 0; postfix[i] != '\0'; i++) { 
        ch = postfix[i]; 
        if (isdigit(ch)) { 
            push(ch - '0'); 
        } 
        else { 
            b = pop(); 
            a = pop(); 
            switch (ch) { 
                case '+': push(a + b); break; 
                case '-': push(a - b); break; 
                case '*': push(a * b); break; 
                case '/': push(a / b); break; 
            } 
        } 
    }   
    return pop(); 
} 

int main() { 
    char postfix[100]; 
    printf("Enter postfix expression (single digit operands): "); 
    scanf("%s", postfix);   
    int result = evaluate(postfix); 
    printf("Result = %d\n", result); 
    return 0; 
} 