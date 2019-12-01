/*
Write a C program to perform the following operations using doubly linked list with header node.

Header node should maintain the count of number of nodes in the list after each operation:

(a) to insert a node next to a node whose information field is specified.
(b) to delete first node if pointer to the last node is given.
(c) to delete a node at the specified position in the list.
(d) to display the contents of the list.
(e) to swap nth and mth nodes in the list */

#include<stdio.h>
#include<stdlib.h>
struct Header_DLL
{
   int info;
   struct Header_DLL *lptr,*rptr;
};

typedef struct Header_DLL *node;

node insert_next(node,int);
node delete_first(node,node);
node delete_pos(node,int);
node swap_data(node,int,int);
void display(node);

void main()
{
    node *head,*last;
    int choice,m,n,data,pos;
    head->info=0;
    head->lptr=head->rptr=NULL;
    while(1)
    {
       printf("\n1:Insert next to a node whose info is given\n2:Delete first\n3:Delete at position\n4:Swap\n5:Display\n6:Exit");
       printf("\nEnter your choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
	         case 1: printf("\nEnter the data: ");
	 	             scanf("%d",&data);
                     head=inser_next(head,data);
		             break;

	         case 2: last=head->rptr;
                     while(last->rptr!=NULL)
                     {
                        last=last->rptr;
                     }
                     head=delete_first(head,last);
                     break;

            case 3: printf("\nEnter the position: ");
                    scanf("%d",&pos);
                    head=delete_pos(head,pos);
                    break;


	         case 4: printf("\nEnter the values of m and n: ");
                     scanf("%d%d",&m,&n);
                     head=swap_data(head,m,n);
	                 break;

	         case 5: display(head);
	 	             break;

	         case 6:  exit(0);

	         default: printf("\nINVALID CHOICE !!!");
	    }
    }
}


node insert_next(node head,int data)
{
    node temp,cur=NULL;
    int key;
    if((temp=(node)malloc(sizeof(struct Header_DLL)))==NULL)
    {
        printf("\nMemory not allocated");
        return head;
    }
    temp->info=data;
    temp->lptr=temp->rptr=NULL;
    printf("\nEnter the key element: ");
    scanf("%d",&key);
    cur=head->next;

    while(cur->rptr!=NULL && cur->info!=key)
    {
        cur=cur->rptr;
    }
    if(cur->info==key)
    {
        temp->rptr=cur->rptr;
        if(cur->rptr!=NULL)
        {
            cur->rptr->lptr=temp;
        }
        cur->rptr=temp;
        temp->lptr=cur;
        head->info++;
        return(head);
    }

    else
    {
        printf("\nKey Element does not exist!");
        return(head);
    }

}


node delete_first(node head,node last)
{
    if(head->rptr==NULL)
    {
        printf("\nList is empty!\n");
        return(head);
    }

    while(last->lptr!=head)
    {
        last=last->lptr;
    }

    head->rptr=last->rptr;
    if(last->rptr!=NULL)
    {
        last->rptr->lptr=head;
    }
    free(last);
    head->info--;
    return(head);
}


node delete_pos(node head,int pos)
{
    node cur=NULL;
    int count=1;
    if(head->rptr==NULL)
    {
        printf("\nList is empty!\n");
        return(head);
    }
    cur=head->rptr;
    while(cur->rptr!=NULL && count!=pos)
    {
        cur=cur->rptr;
        count++
    }
    if(count==pos)
    {
        cur->lptr->rptr=cur->rptr;
        if(cur->rptr!=NULL)
        {
            cur->rptr->lptr=cur->lptr;
        }
        head->info--;
        return(head);
    }
    printf("\nInvalid Position\n");
    return(head);
}


node swap_data(node head,int m,int n)
{
    node p1,p2;
    p1=p2=head->rptr;
    int temp,i;

    if((m<1 || m >head->info) || (n<1 || n >head->info))
    {
        printf("\nInvalid node numbers for swapping !!!");
        return(head);
    }

    for(i=1;i!=m;i++)
    {
        p1=p1->rptr;
    }

    for(i=1;i!=n;i++)
    {
        p2=p2->rptr;
    }

    temp=p1->info;
    p1->info=p2->info;
    p2->info=temp;

    return(head);
}


void display(node head)
{
    node cur;
    if(head->rptr==NULL)
    {
        printf("\nList is Empty!\n");
        return(head);
    }
  	cur=head->rptr;
    printf("\nLIST CONTENTS:\t");
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->rptr;
    }
    printf("\nTotal number of nodes = %d",head->info);
}
