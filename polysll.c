#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create a polynomial by reading terms from the user
struct Node* createPolynomial() {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int n, c, e;

    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (c e): ");
        scanf("%d %d", &c, &e);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp   = e;
        newNode->next  = NULL;

        // append at the end (order is how user enters it)
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Display polynomial in standard form
void displayPolynomial(struct Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *poly = createPolynomial();

    printf("\nThe polynomial is: ");
    displayPolynomial(poly);

    return 0;
}
