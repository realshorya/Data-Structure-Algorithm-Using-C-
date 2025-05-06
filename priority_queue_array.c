#include<stdio.h>
#define MAX 10
int front,rear;
int qu[MAX];
void enque(int value)
{
    if(front==-1)
    {
        rear=front=0;
        qu[0]=value;
    }
    else if(rear==MAX-1)
    {
        printf("\nOvervalue - Queue is Full");
    }
    else{
        int i=rear;
        while(value<qu[i] && i>=0)
        {
            qu[i+1]=qu[i];
            i=i-1;
        }
        qu[i+1]=value;
        rear=rear+1;
    }
}
void deque()
{
    if(front==-1)
    {
        printf("\nUndervalue - Queue is Empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else{
        for(int i=front;i<rear;i++)
        {
            qu[i]=qu[i+1];
        }
        rear=rear-1;
    }
}
void display()
{
    printf("\nQueue is:");
    if(front==-1)
    {
        printf("\nUndervalue - Queue is Empty");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",qu[i]);
        }
    }
}
int main()
{
    int ch,num;
    rear=front=-1;
    do
    {
        printf("\nPRESS 1 - Add Priority Value");
        printf("\nPRESS 2 - Deque");
        printf("\nPRESS 3 - Display");
        printf("\nPRESS 0 - Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter Number to Add:");
            scanf("%d",&num);
            enque(num);
            break;

            case 2:
            deque();
            break;

            case 3:
            display();
            break;
        }
    }while(ch!=0);
    return 0;
}
