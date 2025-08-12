#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100
char infix[max];//orginal
char postfix[max];//output
char stack[max];//operator
int top=-1;
void push(char op)
{
if(top==max-1)
{
printf("stack overflow\n");
return;
}
stack[++top]=op;
}
char pop()
{
if(top==-1)
{
printf("stack underflow\n");
return 0;
}
return stack[top--];
}
char peek()
{
if(top==-1)
{
return 0;
}
else{
return stack[top];
}
}
int precedence(char op)
{
if(op=='+'||op=='-'){
return 1;
}
if(op=='*'||op=='/')
{
return 2;
}
return 0;}
void convert()
{
int i=0;
int j=0;
char ch;
while((ch=infix[i])!='\0'&&ch!='\n')
{
if(isdigit(ch)){
postfix[j++]=ch;}
else if(ch=='(')
{
push(ch);}
else if(ch==')')
{
while (peek() !='(')
{
postfix[j++]=pop();}
pop();}
else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
{
while(top!=-1 &&precedence(peek()) >=precedence(ch)){
postfix[j++]=pop();
}
push(ch);}i++;}
while(top!=-1)
{
postfix[j++]=pop();
}
postfix[j]='\0';
}
int main()
{
printf("enetr infix expression:");
fgets(infix,max,stdin);
convert();
printf("postfix expression is:%s\n",postfix);
return 0;
}


