#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[50];
    int marks;
    struct node* next;
    
};

struct node* front=NULL;

struct node* createnode(char name[],int marks){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name,name);
    newnode->marks=marks;
    newnode->next=NULL;
    return newnode;
}

struct node* insert(char name[],int marks){
    struct node* newnode=createnode(name,marks);
    if(front==NULL||front->marks < marks){
        newnode->next=front;
        front=newnode;
    }
    else{
        struct node* current=front;
        while(current->next!=NULL && current->next->marks>= marks){
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
    printf("Candidate %s with marks %d added",name,marks);
    }

void schedule(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Interview scheduled for: %s with marks: %d",front->name,front->marks);
    front=front->next;
}

void display(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    
    struct node* temp=front;
    printf("Current Interview queue\n");
    while(temp!=NULL){
        printf("name: %s\tMarks: %d\n",temp->name,temp->marks);
        temp=temp->next;
    }
}

int main(){
    int choice,marks;
    char name[50];
    
    do{
        printf("\n====PRIORITY QUEUE INTERVIEW====\n1.Insert\n2.Shcedule\n3.Display\n4.Exit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
            printf("Enter candidate name: ");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';
            printf("Enter Marks: ");
            scanf("%d",&marks);
            insert(name,marks);
            break;
            case 2:
            schedule();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            
            
        }
    }while(1);
    return 0;
}
    
