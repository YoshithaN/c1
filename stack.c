#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};

struct node *top=NULL;
void push(int value)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if(!newnode){
printf("memory not allocated\n");
return;
}
newnode->data=value;
newnode->next=top;
top=newnode;
printf("value aded to stack\n");}

void pop()
{
if(top==NULL)
{
printf("stack underflow\n");
return;
}
struct node *temp=head;
printf("%d popped ",top->data);
top=top->next;
free(temp);
}
void peek()
{
if(top==NULL)
{
printf("stack empty");
}
printf(%d",top->data);
}
void display()
{
if(top==NULL)
{
printf("stack empty\n");}
struct node *temp=top;
while(temp!=NULL)
{
printf("%d",temp->data);

temp=temp->next;
}
printf("NULL\n");
}



