// Q3) Check whether the string is palindrome or not using array and Queue 
#include <stdio.h> 
#include <string.h> 
#define SIZE 100 
char queue[SIZE];
int front = -1, rear = -1;
void enqueue(char ch) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = ch;
}
char dequeue() {
    if (front == -1 || front > rear) return '\0';
    char ch = queue[front];
    front++;
    return ch;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    // Insert all characters in queue 
    for (int i = 0; i < len; i++)
        enqueue(str[i]);
    // Compare from both ends using queue (front) and array (back) 
    int isPalindrome = 1;
    for (int i = len - 1; i >= len / 2; i--) {
        char ch = dequeue();
        if (ch != str[i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    return 0;
}