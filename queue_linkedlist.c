#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Queue;

Queue *front,*rear;

void enque(int value)
{
    Queue *temp;
    temp=(Queue*)malloc(sizeof(Queue));
    temp->data=value;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
int deque()
{
    int n=0;
    if(front==NULL)
    {
        printf("\nUnderflow - Queue is Empty");
        return -1;
    }
    else if(front==rear)
    {
        n=front->data;
        front=rear=NULL;
        free(front);
        return n;
    }
    else
    {
        Queue *temp;
        temp=front;
        front=front->next;
        n=temp->data;
        free(temp);
        return n;
    }
}
void display()
{
    if(front==NULL)
    {
        printf("\nQueue id Empty");
    }
    else
    {
        for(Queue *ptr=front;ptr!=NULL;ptr=ptr->next)
        {
            printf("\n%d",ptr->data);
        }
    }
}
int main()
{
    front=rear=NULL;
    int ch,num;
    do
    {
        printf("\nPRESS 1 - ENQUE");
        printf("\nPRESS 2 - DEQUE");
        printf("\nPRESS 3 - DISPLAY");
        printf("\nPRESS 0 - EXIT");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter Number You Want to Add:");
            scanf("%d",&num);
            enque(num);
            break;

            case 2:
            num=deque();
            if(num==-1)
            {
                printf("\nNothing Deleted");
            }
            else
            {
                printf("\nDeleted Number is : %d",num);
            }
            break;

            case 3:
            display();
            break;
        }
    }while(ch!=0);
    return 0;
}
