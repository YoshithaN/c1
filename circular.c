#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;   
void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {              
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)    // move to last node
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at front.\n", value);
}


void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {              
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)   
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at rear.\n", value);
}


void insertAtPos(int value, int pos) {
    if (pos < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (pos == 1) {
        insertFront(value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}


void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {   // single node
        printf("Deleted %d from front.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)   // find last node
        temp = temp->next;

    struct Node *toDelete = head;
    head = head->next;
    temp->next = head;
    printf("Deleted %d from front.\n", toDelete->data);
    free(toDelete);
}


void deleteRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {   // only one node
        printf("Deleted %d from rear.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    printf("Deleted %d from rear.\n", temp->next->data);
    free(temp->next);
    temp->next = head;
}


void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        printf("Position out of range.\n");
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, pos);
    free(toDelete);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


int main() {
    int choice, value, pos;

    while (1) {
        printf("\nCircular Linked List\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPos(value, pos);
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                deleteRear();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
