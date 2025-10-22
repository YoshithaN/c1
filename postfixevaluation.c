#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 100
char stack[max];
int top=-1;
 void push(char c){
     stack[++top]=c;
 }
 char pop(){
     if(top==-1){
         return -1;
     } else{
         return stack[top--];
     }
 }
  int precedence(char c){
      if(c=='^')
      return 3;
      else if(c=='*'||c=='/')
      return 2;
      else if(c=='+'||c=='-')
      return 1;
      else 
      return 0;
  }
  
void infixtopostfix(char infix[],char postfix[])
{
    
    char c;
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        c=infix[i];
        if(isdigit(c)||isalpha(c)){
            postfix[j++]=c;
        }
        else if (c=='('){
            push(c);
            
        }
        else if(c==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1&&precedence(stack[top])>precedence(c)){
                postfix[j++]=pop();
                
            }
            push(c);
        }
    }
    
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression is %s",postfix);
    
}

//eval
int evalstack[max];
int vtop=-1;
void evalpush(int n){
    evalstack[++vtop]=n;
}
int evalpop(){
    
    return evalstack[vtop--];
}
int postfixevaluation(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            evalpush(ch - '0');
        }
        else{
            int val2=evalpop();
            int val1=evalpop();
            switch(ch){
                case '+':
                evalpush(val2+val1);
                break;
                case '-':
                evalpush(val1-val2);
                break;
                case '*':
                evalpush(val1*val2);
                break;
                case '/':
                evalpush(val1/val2);
                break;
                case '^':{
                int result=1;
                for(int j=0;j<val2;j++){
                    result*=val1;
                }
                evalpush(result);}
                break;
                
                
            }
        }
    }
    return evalpop();
}




int main(){
    char infix[max],postfix[max];
    printf("enter infix expression\n");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    
    int answer=postfixevaluation(postfix);
    printf("\nevalation is %d",answer);
    return 0;
}