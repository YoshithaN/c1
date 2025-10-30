#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int coeff;
    int exp;
    struct node* next;
};

struct node* createnode(int coeff,int exp){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;
}

struct node* insertnode(struct node* head,int coeff,int exp){
    struct node* newnode=createnode(coeff,exp);
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;}
        temp->next=newnode;
        }
        return head;
    
}

void display(struct node* head){
    if (head==NULL){
        printf("cannot display\n");
        return;
    }
    else{
        struct node* temp=head;
        while(temp!=NULL){
            printf("%dx^%d",temp->coeff,temp->exp);
            if(temp->next!=NULL){
                printf("+");}
            temp=temp->next;
            
        }
    }
}

struct node* addpolynomial(struct node* p1,struct node* p2){
    struct node* result=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->exp > p2->exp){
            result=insertnode(result,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else if(p1->exp < p2->exp){
            result=insertnode(result,p2->coeff,p2->exp);
            p2=p2->next;
        }
        else if(p1->exp ==p2->exp){
            int sum=p1->coeff+p2->coeff;
            result=insertnode(result,sum,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        
    }
    while(p1!=NULL){
        result=insertnode(result,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insertnode(result,p2->coeff,p2->exp);
        p2=p2->next;
    }
    return result;
}

struct node *productpoly(struct node* p1,struct node* p2){
    struct node* result=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->exp > p2->exp){
            result=insertnode(result,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else if(p1->exp < p2->exp){
            result=insertnode(result,p2->coeff,p2->exp);
            p2=p2->next;
        }
        else if(p1->exp ==p2->exp){
            int product=p1->coeff*p2->coeff;
            result=insertnode(result,product,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        
    }
    while(p1!=NULL){
        result=insertnode(result,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insertnode(result,p2->coeff,p2->exp);
        p2=p2->next;
    }
    return result;
    
}

int main(){
    struct node* p1=NULL,*p2=NULL,*sum=NULL,*product=NULL;
    int n,m,coeff,exp;
    printf("enter no of terms in polynomial 1\t");
    scanf("%d",&n);
    printf("enetr elements to polynomial 1\n");
    for(int i=0;i<n;i++){
        printf("enetr coeff and exp of %d term",i+1);
        scanf("%d%d",&coeff,&exp);
        p1=insertnode(p1,coeff,exp);
        
        
        
    }
    printf("polynomial 1\t");
    display(p1);
    printf("\n");
    printf("enetr no of terms of polynomial 2\t");
    scanf("%d",&m);
    printf("enetr elements to polynomial 2\n");
    for(int j=0;j<m;j++){
        printf("enetr coeff and exp of %d term",j+1);
        scanf("%d%d",&coeff,&exp);
        p2=insertnode(p2,coeff,exp);
        
        
        
    }
    printf("polynomial 2\t");
    display(p2);
        printf("\n");
    sum=addpolynomial(p1,p2);
    printf("sum is \t");
    display(sum);
    
    printf("\n product is\t");
    product=productpoly(p1,p2);
    display(product);
    return 0;
    
}