#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;


void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    } else {
        printf("Stack Overflow\n");
    }
}


char pop() {
    if (top >= 0) {
        char ch = stack[top];
        top--;
        return ch;
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int main() {
    char str[MAX], reversed[MAX];
    int i;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    
    for (i = 0; str[i] != '\0'; i++) {
        reversed[i] = pop();
    }
    

    printf("Reversed string: %s\n", reversed);

    return 0;
}