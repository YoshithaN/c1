#include <stdio.h>
#include <stdlib.h>
#define max 3
int q[max],front=-1,rear=-1;
void enqueue(int item)
{
    if (rear==max-1)
    {
        printf("queue is full,overflow\n");

    }
    else if(front==-1)
    {
        front=0;
        q[++rear]=item;
    }
    else{
        q[++rear]=item;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("underflow\n");

    }
    else{
        int item=q[front];
        printf("%d popped\n",item);
        if(front==rear)
        {   front=-1;
            rear=-1;
           

        }
        else
        {
            front=front+1;      
        }
    }
}
void display()
{
    if(front!=-1){
    for(int i=front;i<=rear;i++)
{
    printf("%d\t",q[i]);
    

}
printf("\n");}
else{
    printf("queue is empty\n");
}
}
void peek()
{   
    if(front!=1){
        int item=q[front];
    printf("%d",item);
}else{
    printf("queue is empty\n");
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
    

