#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node* Nodeptr;

Nodeptr getNode(void){
    Nodeptr new_node=(Nodeptr)malloc(sizeof(struct node));
    return new_node;
}

void insertOrdered(Nodeptr *list,int val){
Nodeptr newNode=getNode();
Nodeptr temp=*list;
Nodeptr prev =NULL;
newNode->data=val;
if(*list==NULL){
    newNode->next=NULL;
    *list=newNode;
    return;
}
if(newNode->data<=temp->data){
        newNode->next=temp;
        *list=newNode;
        return;
}
while(temp!=NULL){
       if(newNode->data>temp->data){
    prev=temp;
    temp=temp->next;
       }
       else
        break;
}
prev->next=newNode;
newNode->next=temp;
return;
}

Nodeptr mergeList(Nodeptr list1,Nodeptr list2,Nodeptr list3){
if(list1==NULL&&list2==NULL)
    return;
else if(list1!=NULL&&list2==NULL){
    list3=list1;
    return list3;
}
else if(list2!=NULL&&list1==NULL){
    list3=list2;
    return list3;
}
Nodeptr temp1=list1;
while(temp1!=NULL){
insertOrdered(&list3,temp1->data);
temp1=temp1->next;
}
temp1=list2;
while(temp1!=NULL){
insertOrdered(&list3,temp1->data);
temp1=temp1->next;
}
return list3;
}


Nodeptr remDuplicate(Nodeptr list){
if(list==NULL)
    return;
Nodeptr prev=list;
Nodeptr temp=prev->next;

while(prev->next!=NULL){
            if(prev->data==temp->data){
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
                continue;
            }
        prev=temp;
        temp=temp->next;
}
return list;
}


Nodeptr getUnion(Nodeptr list1,Nodeptr list2,Nodeptr list3){
list3=mergeList(list1,list2,list3);

list3=remDuplicate(list3);

return list3;
}

Nodeptr getIntersection(Nodeptr list1,Nodeptr list2,Nodeptr list3){
list1=remDuplicate(list1);
list2=remDuplicate(list2);
Nodeptr temp1=list1;
Nodeptr temp2=list2;
while(temp1!=NULL&&temp2!=NULL ){
        if(temp1->data==temp2->data){
            insertOrdered(&list3,temp1->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data<temp2->data)
            temp1=temp1->next;
        else
            temp2=temp2->next;
}

return list3;
}


void display(Nodeptr first){
    Nodeptr temp=first;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


//We do not return any pointer in some functions as the return type is void ,also we r modifying the head pointer in the function itself

int main()
{
    int val;
    Nodeptr list1=NULL;
    Nodeptr list2=NULL;
    printf("Enter the values for list1 and enter ctrl+Z to exit\n");
    while(scanf("%d",&val)!=EOF){
        insertOrdered(&list1,val);
    }
    printf("Your list1 is\n");
    display(list1);
    printf("\nEnter the values for list2 and enter ctrl+Z to exit\n");
    while(scanf("%d",&val)!=EOF){
        insertOrdered(&list2,val);
    }
    printf("\nYour list2 is\n");
    display(list2);
    Nodeptr list3=NULL;
    list3=getUnion(list1,list2,list3);
    printf("Union LIST\n\n");
    display(list3);
    list3=NULL;
    list3=getIntersection(list1,list2,list3);
    printf("Intersection LIST\n\n");
    display(list3);
    return 0;


}

