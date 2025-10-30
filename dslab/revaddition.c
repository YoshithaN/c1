#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int val;
    struct node *next;
};

// Create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end of list
struct node* insertEnd(struct node* head, int val) {
    struct node* newNode = createNode(val);
    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Add two numbers represented as linked lists
struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* curr = &dummy;
    dummy.next = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        curr->next = createNode(sum);
        curr = curr->next;
    }

    return dummy.next;
}

// Print linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *l1 = NULL, *l2 = NULL;
    int n1, n2, digit;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);

    printf("Enter digits of first number (in reverse order):\n");
    for (int i = 0; i < n1; i++) {
        printf("Digit %d: ", i + 1);
        scanf("%d", &digit);
        l1 = insertEnd(l1, digit);
    }

    printf("\nEnter number of digits in second number: ");
    scanf("%d", &n2);

    printf("Enter digits of second number (in reverse order):\n");
    for (int i = 0; i < n2; i++) {
        printf("Digit %d: ", i + 1);
        scanf("%d", &digit);
        l2 = insertEnd(l2, digit);
    }

    printf("\nFirst number (reversed): ");
    printList(l1);

    printf("Second number (reversed): ");
    printList(l2);

    struct node* result = addTwoNumbers(l1, l2);

    printf("\nSum (reversed): ");
    printList(result);

    return 0;
}
