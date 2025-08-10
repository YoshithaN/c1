#include <stdio.h>
#include <stdlib.h>
#define max 3
int q[max],front=-1,rear=-1;
int isfull(){
    return(front==(rear+1)%max);
}
int isempty(){
    return(front==-1);
}
void insertrear(int item){
    if(isfull()){
        printf("overflow\n");
        return;
    }
    else if(isempty()){
        front=0;
        rear=0;
        q[rear]=item;
    }
    else{
        rear=(rear+1)%max;
        q[rear]=item;
    }
    printf("%d inserted\n",item);
}
void deletefront(){
    if(isempty()){
        printf("queue underflow\n");

    }
    else{
        int item=q[front];
        printf("%d popped from queue\n",item);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%max;

        }
    }

    

}
void insertfront(int value) {
    if (isfull()) {
        printf(" Deque is full (Overflow).\n");
        return;
    }
    if (isempty()) {
        front = 0;
        rear = 0;
        q[front]=value;
    } else {
        
        front = (front - 1 + max) % max;
        q[front]=value;
    }
    
    printf("Inserted %d at the front.\n", value);
}
void deleterear() {
    if (isempty()) {
        printf("Deque is empty (Underflow).\n");
        return;
    }
    int item = q[rear];
    if (front == rear) { 
        front = -1;
        rear = -1;

    } else {
        
        rear = (rear - 1 + max) % max;
    }
    printf("Deleted %d from the rear.\n", item);
}
void display(){
    if(isempty()){
    printf("queue is empty\n");}
    else{
        int i=front;
        while(i!=rear){
            printf("%d\t",q[i]);
            i=(i+1)%max;

        }
        printf("%d",q[rear]);
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n Deque Menu \n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Delete from Front\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                deleterear();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}