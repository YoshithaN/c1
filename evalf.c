#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define max 100

int stack[max];
int top = -1;

void push(int item) {
    if (top >= max - 1) {
        printf("stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("stack underflow\n");
        return 0;
    } else {
        return stack[top--];
    }
}

int evaluate(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':   
                    push((int)pow(a, b));
                    break;
                default:
                    printf("invalid operation\n");
                    break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[max];
    printf("enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    int result = evaluate(exp);
    printf("result is: %d\n", result);
    return 0;
}
