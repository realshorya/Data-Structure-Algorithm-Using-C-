#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LIST;
LIST *addatend(LIST *start,int value)
{
    LIST *temp;
    temp=(LIST*)malloc(sizeof(LIST));
    temp->data=value;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        LIST *ptr;
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return start;
}
void display(LIST *start)
{
    LIST *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        if(ptr->next!=NULL)
        {
            printf("->");
        }
        ptr=ptr->next;
    }
}
LIST *merging(LIST *p,LIST *q)
{
    LIST *newstart=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            newstart=addatend(newstart,p->data);
            p=p->next;
        }
        else
        {
            newstart=addatend(newstart,q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        newstart=addatend(newstart,p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        newstart=addatend(newstart,q->data);
        q=q->next;
    }
    return newstart;
}
int main()
{
    LIST *start1,*start2,*result;
    start1=start2=NULL;
    int i,n,m,num;
    printf("\nHow many numbers are in 1st List:");
    scanf("%d",&n);
    printf("\nInsert Values in Increasing Order ONLY\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter Element %d: ",i);
        scanf("%d",&num);
        start1=addatend(start1,num);
    }
    printf("\nHow many numbers are in 1st List:");
    scanf("%d",&m);
    printf("\nInsert Values in Increasing Order ONLY\n");
    for(i=1;i<=m;i++)
    {
        printf("Enter Element %d: ",i);
        scanf("%d",&num);
        start2=addatend(start2,num);
    }
    printf("\nList 1: ");
    display(start1);
    printf("\nList 2: ");
    display(start2);
    printf("\nMerged List are: ");
    result=merging(start1,start2);
    display(result);
    return 0;
}
