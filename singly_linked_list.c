#include<Stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LIST;

LIST *start;

void addatend(int value)
{
    LIST *temp,*ptr;
    temp=(LIST*)malloc(sizeof(LIST));
    temp->data=value;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void addatbeg(int value)
{
    LIST *temp,*ptr;
    temp=(LIST*)malloc(sizeof(LIST));
    temp->data=value;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}
void display()
{
    LIST *ptr;
    ptr=start;
    printf("\nList Elements are: ");
    while(ptr!=NULL)
    {
        printf("\n%d is stored at %u",ptr->data,ptr);
        ptr=ptr->next;
    }
}
void addatpos(int value, int pos)
{
    int i;
    LIST *ptr,*temp;
    if(pos==1)
    {
        addatbeg(value);
    }
    else
    {
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp=(LIST*)malloc(sizeof(LIST));
        temp->data=value;
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void delfrombeg()
{
    LIST *ptr;
    if(start==NULL)
    {
        printf("\nList is Blank:");
    }
    ptr=start;
    start=start->next;
    free(ptr);
}
void delatpos(int pos)
{
    int i;
    LIST *ptr,*temp;
    if(pos==1)
    {
        delfrombeg();
    }
    else
    {
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
    }
}
void delfromend()
{
    LIST *ptr;
    if(start==NULL)
    {
        printf("\nList is Blank");
    }
    ptr=start;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
}
void sort()
{
    LIST *p,*q;
    for(p=start;p->next!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            int temp;
            if(p->data > q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
void reverse()
{
    LIST *newstart,*temp;
    newstart=NULL;
    while(start!=NULL)
    {
        temp=start;
        start=start->next;
        temp->next=newstart;
        newstart=temp;
    }
    start=newstart;
    display();
}
void search(int num)
{
    LIST *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data == num)
        {
            printf("\nFOUND!!");
            break;
        }
        else{
            ptr=ptr->next;
        }
        if(ptr == NULL)
        {
            printf("\n NOT FOUND!!");
        }
    }
}
int main()
{
    int n,pos,num;
    do{
        printf("\nPRESS-1 to ADD AT BEGINNING");
        printf("\nPRESS-2 to ADD AT ENDING");
        printf("\nPRESS-3 to ADD AT POSTION");
        printf("\nPRESS-4 to DELETE AT BEGINNING");
        printf("\nPRESS-5 to DELETE AT END");
        printf("\nPRESS-6 to DELETE at POS");
        printf("\nPRESS-7 to SORT");
        printf("\nPRESS-8 to SEARCH");
        printf("\nPRESS-9 to DISPLAY");
        printf("\nPRESS-10 to REVERSE");
        printf("\nPRESS-0 to EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("\nEnter Number to ADD:");
            scanf("%d",&num);
            addatbeg(num);
            break;

            case 2:
            printf("\nEnter Number to ADD:");
            scanf("%d",&num);
            addatend(num);
            break;

            case 3:
            printf("\nEnter Number And Position: ");
            scanf("%d %d",&num,&pos);
            addatpos(num,pos);
            break;

            case 4:
            delfrombeg();
            break;

            case 5:
            delfromend();
            break;

            case 6:
            printf("\nEnter Position to Delete:");
            scanf("%d",&pos);
            delatpos(pos);
            break;

            case 7:
            sort();
            break;

            case 8:
            printf("\nEnter Number Want to Search:");
            scanf("%d",&num);
            search(num);
            break;

            case 9:
            display();
            break;

            case 10:
            reverse();
            break;

        }
    }while(n!=0);
    return 0;
}
