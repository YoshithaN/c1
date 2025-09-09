#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

char infix[max];   
char postfix[max]; 
char stack[max];  
int top = -1;

void push(char op) {
    if (top == max - 1) {
        printf("stack overflow\n");
        return;
    }
    stack[++top] = op;
}

char pop() {
    if (top == -1) {
        printf("stack underflow\n");
        return 0;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return 0;
    } else {
        return stack[top];
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {  
        return 3;
    }
    return 0;
}

int isRightAssociative(char op) {
    return (op == '^');
}

void convert() {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i]) != '\0' && ch != '\n') {
        if (isdigit(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (top != -1 &&
                   ((isRightAssociative(ch) == 0 && precedence(peek()) >= precedence(ch)) ||
                    (isRightAssociative(ch) == 1 && precedence(peek()) > precedence(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    printf("enter infix expression: ");
    fgets(infix, max, stdin);
    convert();
    printf("postfix expression is: %s\n", postfix);
    return 0;
}
#include <stdio.h>

struct sparse {
    int row;
    int col;
    int val;
};

int main() {
    int m, n, val;
    printf("enter total rows col and val\n");
    scanf("%d%d%d", &m, &n, &val);

    struct sparse matrix[val + 1];
    struct sparse t[val + 1];

    matrix[0].row = m;
    matrix[0].col = n;
    matrix[0].val = val;

    t[0].row = n;
    t[0].col = m;

    printf("enter data (row col value):\n");
    for (int i = 1; i <= val; i++) {
        scanf("%d%d%d", &matrix[i].row, &matrix[i].col, &matrix[i].val);
    }

    int k = 1;
    for (int c = 0; c < matrix[0].col; c++) {
        for (int i = 1; i <= matrix[0].val; i++) {
            if (matrix[i].col == c) {
                t[k].row = matrix[i].col;
                t[k].col = matrix[i].row;
                t[k].val = matrix[i].val;
                k++;
            }
        }
    }
    t[0].val = k - 1;   // 
    printf("\nOriginal matrix (triplet form):\n");
    for (int i = 0; i <= matrix[0].val; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].val);
    }

    printf("\nTranspose (triplet form):\n");
    for (int i = 0; i <= t[0].val; i++) {
        printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
    }

    return 0;
}
