#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char word[50];
    struct node* next;
    
};

struct node* createnode(char word[]){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->word,word);
    newnode->next=NULL;
    return newnode;
}

struct node* insert(struct node* head,char word[]){
    struct node* newnode=createnode(word);
    if(head ==NULL){
        return newnode;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=newnode;
    return head;
    
}

void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%s",temp->word);
        if(temp->next!=NULL){
            printf(" ");
        }
        temp=temp->next;
    }
    printf("\n");
}


void replace(struct node* head,char target[],char replacement[]){
    struct node* temp=head;
    while(temp!=NULL){
        if(strcmp(temp->word,target)==0){
            strcpy(temp->word,replacement);
        }
        temp=temp->next;
    }
    
}

int main(){
    struct node* head=NULL;
    char target[50],replacement[50],sentence[200];
    printf("Enter sentence : ");
    fgets(sentence,sizeof(sentence),stdin);
    sentence[strcspn(sentence,"\n")]='\0';
    
    char * token;
    token=strtok(sentence," ");
    while(token!=NULL){
        head=insert(head,token);
        token=strtok(NULL," ");
    }
    
    printf("orginal sentence : ");
    display(head);
    printf("Enter word to replace : ");
    scanf("%s",target);
    printf("enter replacement : ");
    scanf("%s",replacement);
    
    replace(head,target,replacement);
    display(head);
    
    
}

