#include <stdio.h>
#include <stdlib.h>

/* structure definition for linked list node */
 struct node
{
       int data;
       struct node *next;
};
       
void insertLast(struct node **head, int newnode);
int getLength(struct node *head);
void insertBeg(struct node **head,int newnode);
void insertMiddle(struct node **head,int newnode,int position);
void deletebeg(struct node **head);   
void deletelast(struct node **head);
void deletemiddle(struct node **head,int position);    
void DeleteLinkedList(struct node **head);

int main()
{
    struct node *head,*newnode,*iterator;
    int i,count;
    int ldata[5]={4,3,2,1,0};
    head=NULL;
              // printf(" address id %u",head);
    
   for(i=0;i<=4;i++)
   {
   insertLast(&head,ldata[i]);
   }
   insertMiddle(&head,ldata[3], 2);
   
    
   
   deletemiddle(&head,2);
   iterator=head;
   do
   {
                               printf("->%d",iterator->data);
                               iterator=iterator->next;
                               //printf("\n address id %u",iterator);
                              
   }while(iterator!=NULL);
   
    count=getLength(head);
    printf("\nlength of list is %d\n",count);
    
  DeleteLinkedList(&head);
                    
}

void insertLast(struct node **head, int ldata)
{
     struct node *iterator=*head;
     struct  node *temp=(struct node*)malloc(sizeof(struct node));
     if(*head==NULL)
     {
                    *head=temp;
                    (*head)->data=ldata;
                   (*head)->next=NULL;
                    }
     else
     {
     while(iterator->next!=NULL)
     {
                                
                                iterator=iterator->next;
     }
     iterator->next=temp;
     temp->data=ldata;
     temp->next=NULL;
     }
     
}

void insertBeg(struct node **head, int ldata)
{
     struct  node *temp=(struct node*)malloc(sizeof(struct node));
     if(*head==NULL)
     {
                   printf("in function NULL");
                   
                   *head=temp;
                   (*head)->data=ldata;
                   (*head)->next=NULL;
     }
      else
      {
                     printf("in function else");                                                                        
                     
                     temp->data=ldata;
                     temp->next=*head;
                     *head=temp;  
      }
    
}

int getLength(struct node *head)
{
     int count=0;
     struct node *temp=head;
     while(temp != NULL)
     {
               temp=temp->next;
               count++;            
     }
     return count;
 }

void insertMiddle(struct node **head,int ldata,int position)
{
     struct node *iterator=*head;
     struct node *previous=NULL;
     struct  node *temp=(struct node*)malloc(sizeof(struct node));
     int count;
      if(*head==NULL)
     {
                   printf("in function NULL");
                   
                   *head=temp;
                   (*head)->data=ldata;
                   (*head)->next=NULL;
     }
     
     else
     {
         for(count=1;count<position;count++)
         {
                   previous=iterator;
                   iterator=iterator->next;                        
         }
         temp->data=ldata;
         previous->next=temp;
         temp->next=iterator;
         
     }
     
 }

void deletebeg(struct node **head)
{
     struct node *temp=*head;
     printf("\n %d",temp->data);
     if(*head!=NULL)
     {
           
           *head=temp->next; 
           free(temp);        
     }
      printf("\n %d \n",temp->data);
 }
void deletelast(struct node **head)
{
     struct node *temp=*head,*previous=NULL;
     
     if(*head!=NULL)
     {
           while(temp->next!=NULL)
           {
           previous=temp;
           temp=temp->next;           
           }
           previous->next=NULL;
           free(temp);               
     }
      printf("\n %d \n",temp->data);
 }
 
 void deletemiddle(struct node **head,int position)
 {
      struct node *iterator=*head;
     struct node *previous=NULL;
     int count;
     if(*head!=NULL)
     {
      for(count=1;count<position;count++)
         {
                   previous=iterator;
                   iterator=iterator->next;                        
         }
         previous->next=iterator->next;
         printf("\n %d \n",iterator->data);
         free(iterator);
      }
  }

void DeleteLinkedList(struct node **head)
{
	struct node *auxilaryNode, *iterator;
	iterator = *head;
	while(iterator)
	{
		auxilaryNode = iterator->next;
		free(iterator);
		iterator = auxilaryNode;
	}
	*head = NULL; // to affect the real  head back in the caller
}



