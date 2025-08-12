#include <stdio.h>
#include <stdlib.h>

#define max 3
int q[max], front = -1, rear = -1;
int deque_type = 0; 

int isfull() {
    return (front == (rear + 1) % max);
}
int isempty() {
    return (front == -1);
}

void insertrear(int item) {
    if (isfull()) {
        printf("Overflow\n");
        return;
    } else if (isempty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % max;
    }
    q[rear] = item;
    printf("%d inserted at rear\n", item);
}

void insertfront(int item) {
    if (isfull()) {
        printf("Overflow\n");
        return;
    } else if (isempty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + max) % max;
    }
    q[front] = item;
    printf("%d inserted at front\n", item);
}

void deletefront() {
    if (isempty()) {
        printf("Queue Underflow\n");
        return;
    }
    int item = q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % max;
    }
    printf("%d deleted from front\n", item);
}

void deleterear() {
    if (isempty()) {
        printf("Queue Underflow\n");
        return;
    }
    int item = q[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + max) % max;
    }
    printf("%d deleted from rear\n", item);
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Deque: ");
    while (i != rear) {
        printf("%d ", q[i]);
        i = (i + 1) % max;
    }
    printf("%d\n", q[rear]);
}

int main() {
    int choice, value;

    printf("Select the type of deque:\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &deque_type);

    if (deque_type != 1 && deque_type != 2) {
        printf("Invalid deque type \n");
        return 1;
    }

    while (1) {
        printf("\nDeque Menu\n");
        if (deque_type == 1) {
           
            printf("1. Insert at Rear\n");
            printf("2. Delete from Front\n");
            printf("3. Delete from Rear\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        } else {
            
            printf("1. Insert at Rear\n");
            printf("2. Insert at Front\n");
            printf("3. Delete from Front\n");
            printf("4. Display\n");
            printf("5. Exit\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (deque_type) {
            case 1: 
                switch (choice) {
                    case 1:
                        printf("Enter value to insert at rear: ");
                        scanf("%d", &value);
                        insertrear(value);
                        break;
                    case 2:
                        deletefront();
                        break;
                    case 3:
                        deleterear();
                        break;
                    case 4:
                        display();
                        break;
                    case 5:
                        printf("Exiting program.\n");
                        exit(0);
                    default:
                        printf("Invalid choice. Try again.\n");
                }
                break;

            case 2: 
                switch (choice) {
                    case 1:
                        printf("Enter value to insert at rear: ");
                        scanf("%d", &value);
                        insertrear(value);
                        break;
                    case 2:
                        printf("Enter value to insert at front: ");
                        scanf("%d", &value);
                        insertfront(value);
                        break;
                    case 3:
                        deletefront();
                        break;
                    case 4:
                        display();
                        break;
                    case 5:
                        printf("Exiting program.\n");
                        exit(0);
                    default:
                        printf("Invalid choice. Try again.\n");
                }
                break;
        }
    }

    return 0;
}

