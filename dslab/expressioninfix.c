#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max 100
char stack[max];
int top=-1;


void push(char c){
    stack[++top]=c;
    
}

char pop(){
    if (top==-1 )return -1;
    return stack[top--];
}

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixtopostfix(char infix[],char postfix[]){
    
    char c;
    int j=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        c=infix[i];
        if(isdigit(c)||isalpha(c)){
            postfix[j++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top]) >= precedence(c)){
                postfix[j++]=pop();
            }
            push(c);
        
        }}
        
       
        while(top!=-1){
            postfix[j++]=pop();
        }
        postfix[j]='\0';
        printf("postfix expression is %s\n",postfix);
  

}

struct node{
    char data;
    struct  node* left,*right;
};

struct stack{
    struct node* data;
    struct stack* next;
    
};

struct stack* top2=NULL;

struct node* createnode(char value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void pushstack(struct node* treenode){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=treenode;
    temp->next=top2;
    top2=temp;
    
}

struct node* popstack(){
    if(top2==NULL){
        return NULL;
    }
    struct stack* temp=top2;
    struct node* value=top2->data;
    top2=top2->next;
    free(temp);
    return value;
    
}

struct node* expression(char postfix[]){
    char symbol;
    for(int i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        if(isalnum(symbol)){
            struct node* operand=createnode(symbol);
            pushstack(operand);
            
        }
        else{
            struct node* operator=createnode(symbol);
            operator->right=popstack();
            operator->left=popstack();
            pushstack(operator);
        }
        
    }
    return popstack();
}


void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
}


void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}


int main(){
    char infix[max],postfix[max];
    
    struct node* root=NULL;
    printf("enter infix expression");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    root=expression(postfix);
    printf("inorder traversal is:  ");
    inorder(root);
    printf("\npreorder traversal   :");
    preorder(root);
    return 0;
}