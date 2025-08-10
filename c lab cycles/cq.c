#include <stdio.h>
#include <stdlib.h>
#define max 3
int q[max],front=-1,rear=-1;
int isfull()
{
    return(front==(rear+1)%max);
    
}
int isempty(){
    return(front==-1 && rear==-1);
}
void enqueue(int item){
    if (isfull())
    {
        printf("queue overflow\n");

    }
    else if(front==-1){
        front=0;
        rear=0;
        q[rear]=item;
    }
    else{
        rear=(rear+1)%max;
        q[rear]=item;
    }
}
void dequeue(){
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
void peek(){
    if(!isempty()){
    int item=q[front];
    printf("%d\n",item);
}}
int main()
{
    int choice,value;
    while(1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.peek\n");
        printf("5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enetr vlue to enqueue\n");
            scanf("%d",&value);
            enqueue(value);

            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();    
            break;
        case 4:
            peek();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }


    }
}
    

