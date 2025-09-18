#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;   


void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {                        
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;         
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at front.\n", value);
}


void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("Inserted %d at rear.\n", value);
}


void insertAtPos(int value, int pos) {
    if (pos < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (pos == 1 || head == NULL) {
        insertFront(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, pos);
}


void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {        // only one node
        printf("Deleted %d from front.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *toDelete = head;
    head = head->next;
    head->prev = last;
    last->next = head;

    printf("Deleted %d from front.\n", toDelete->data);
    free(toDelete);
}


void deleteRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {       // single node
        printf("Deleted %d from rear.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;

    printf("Deleted %d from rear.\n", last->data);
    free(last);
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
    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp == head) {
        printf("Position out of range.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}


void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head->prev;   // start from last
    printf("Backward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to tail)\n");
}


int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
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
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                printf("Exiting\n");
                return 0;

            default:
                printf("Invalid choice! \n");
        }
    }
}
