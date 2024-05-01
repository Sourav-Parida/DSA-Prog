//WRITE A PROGRAM TO DELETE A NODE BEFORE A GIVEN NODE OF SINGLY LINK LIST.


#include<stdio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start=NULL;
struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * delete_before(struct node *);

void main(){
int option;

  do{
    printf("\n****MAIN MENU****");
    printf("\n 1. create link list");
    printf("\n 2. Display link list");
    printf("\n 3. Delete a node after a given node");
    printf("\n 4. Exit");
    printf("\n Enter your option");
    scanf("%d",&option);
    switch(option){
      case 1:
          start=create_ll(start);
          printf("\n   ***link list created***   \n");
          break;
      case 2:
          start=display(start);
          break;
      case 3:
          start=delete_before(start);
          break;
    }
  }
  while(option !=4);
}

struct node * create_ll(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("\nEnter the data :");
    scanf("%d",&num);
    while(num != -1){
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL){
            new_node->next=NULL;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
        ptr->next=new_node;
        new_node->next=NULL;
        }
    printf("Enter the data :");
    scanf("%d",&num);
    }
    return start;
}

struct node * display(struct node *start){
    struct node *ptr;
    ptr=start;
    printf("\nThe linked list is:\n ");
    while(ptr != NULL){
        printf("%d , ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return start;
}


struct node * delete_before(struct node *start){
  struct node *ptr,*preptr,*ptr1;
  int val;
  printf("\n Enter the value before which the node has to be deleted :");
    scanf("%d",&val);
    ptr=start;
    ptr1=ptr;
    preptr=ptr;
        while(ptr->data != val){
          preptr=ptr;
          ptr=ptr->next;
        }
        while(ptr1->next !=preptr){
          ptr1=ptr1->next;
        }
        ptr1->next=ptr;
        free(preptr);
        return start;
}