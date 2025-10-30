#include <stdio.h>
#include <string.h>

#include <stdlib.h>

struct node{
    char url[100];
    struct node* prev,*next;
    
};
 struct node* current=NULL;
  void visitnewpage(char url[]){
      struct node* newnode=(struct node*)malloc(sizeof(struct node));
      strcpy(newnode->url,url);
      newnode->prev=current;
      newnode->next=NULL;
      if(current!=NULL){
          current->next=newnode;
          
      }
      current=newnode;
      printf("visted %s",current->url);
  }
  
  void nextpage(){
      if(current==NULL||current->next==NULL){
          printf("cannot go forward\n");
      }
      else{
          current=current->next;
          printf(" moved forward %s",current->url);
      }
  }
  
  void prevpage(){
      if(current==NULL||current->prev==NULL){
          printf("cannot move backward\n");
      }
      else{
         current=current->prev;
          printf("moved backward %s",current->url);
          
      }
  }
  
  void displaycurrent(){
      if(current!=NULL){
          printf("current url is %s",current->url);
      }
      else{
          printf("no url cannot print\n");
      }
      
  }
  
  int main(){
      int choice;
      char url[100];
      do{
          printf("menu\n1.new site\n2.next page\n,3.prev page\n4.display current page\n5.exit\n");
          printf("enter choice\n");
          scanf("%d",&choice);
          getchar();
          switch (choice){
              case 1:
              printf("enter url");
              fgets(url,sizeof(url),stdin);
              visitnewpage(url);
              break;
              case 2:
              nextpage();
              break;
              case 3:
              prevpage();
              break;
              case 4:
              displaycurrent();
              break;
              case 5:
              exit(0);
              break;
              default:
              printf("invalid choice\n");
              break;
              
          }
      }while(1);
      return 0;
  }
  