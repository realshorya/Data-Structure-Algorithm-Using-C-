#include<stdio.h>
#define MAX 10
void enque(int qu[], int val, int *front, int *rear)
{
    if(*rear==MAX-1)
    {
        printf("\nOverflow - Queue is Full");
    }
    else if(*front==-1)
    {
        *front=0;
        *rear=0;
        qu[0]=val;
    }
    else
    {
        *rear+=1;
        qu[*rear]=val;
    }
}
int deque(int qu[], int *front, int *rear)
{
    int n=0;
    if(*front==-1)
    {
        printf("\nUnderflow - Queue is Empty");
        return -1;
    }
    else if(*rear==*front)
    {
        n=qu[*front];
        *rear=*front=-1;
    }
    else
    {
        n=qu[*front];
        *front+=1;
    }
    return n;
}
void display(int qu[], int front, int rear)
{
    if(front==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("\n%d",qu[i]);
        }
    }
}
int main()
{
    int qu[MAX];
    int front=-1,rear=-1;
    int ch,num;
    do{
        printf("\nPRESS 1 - ENQUE");
        printf("\nPRESS 2 - DEQUE");
        printf("\nPRESS 3 - DISPLAY");
        printf("\nPRESS 0 - EXIT");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter Number Want to Add:");
            scanf("%d",&num);
            enque(qu,num,&front,&rear);
            break;

            case 2:
            num=deque(qu,&front,&rear);
            if(num==-1)
            {
                printf("\nNothing Deleted");
            }
            else
            {
                printf("\nDeleted Number is: %d",num);
            }
            break;

            case 3:
            display(qu,front,rear);
            break;
        }
    }while(ch!=0);
    return 0;
}
