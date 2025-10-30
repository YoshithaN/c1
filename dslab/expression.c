#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node* left,*right;
};

struct stack {
    struct node* data;
    struct stack* next;
};

struct stack *top=NULL;

struct node* createnode(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void push(struct node* treenode){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=treenode;
    temp->next=top;
    top=temp;
}

struct node* pop(){
    if (top==NULL) return NULL;
    struct stack* temp=top;
    struct node* value=top->data;
    top=top->next;
    
    free(temp);
    return value;

}

struct node* expressiontree(char postfix[]){
    int i=0;
    char symbol;
    
    while((symbol=postfix[i])!='\0'){
        if(isdigit(symbol)){
            struct node* operand=createnode(symbol);
            push(operand);

        } else {
            struct node* operator=createnode(symbol);
            operator->right=pop();
            operator->left=pop();
            push(operator);
        }
        i++;

       
    }
    return pop();
    

}

void inorder(struct node* root){
    if (root!=NULL){
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
}
}

int main(){
    struct node* root=NULL;
    char postfix[100];
    int choice;
    do{
        printf("menu\n1.expression tree\n2.inorder\n");
        printf("enter choice\t");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
            printf("enter postfix expression\t");
            scanf("%s",postfix);
            root=expressiontree(postfix);
            printf("tree created\n");
            break;
            case 2:
            printf("inorder traversal\n");
            inorder(root);
            printf("\ninorder successful\n");
            break;

            default:
            printf("error\n");
            break;

        }

    }while(1);

    return 0;
}