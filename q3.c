// Convert uppercase string to lowercase using for loop.

#include <stdio.h>

char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch + 32;
    }
    return ch;
}

int main(){
    char str[100];
    printf("Enter a string in uppercase: ");
    scanf("%[^\n]s", str);

    for(int i = 0; str[i] != '\0'; i++){
        str[i] = toLowerCase(str[i]);
    }

    printf("Lowercase string: %s", str);
    return 0;
}
