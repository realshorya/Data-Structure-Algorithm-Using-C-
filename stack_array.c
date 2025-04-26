#include<stdio.h>
#define MAX 10

void push(int stack[], int *top, int value)
{
    if(*top == MAX-1)
    {
        printf("\nOverflow - Stack is full");
    }
    else
    {
        *top=*top+1;
        stack[*top]=value;
    }
}
int pop(int stack[] ,int *top)
{
    int val;
    if(*top==-1)
    {
        printf("\nUnderflow - Stack in empty");
        val=-1;
        return val;
    }
    else
    {
        val=stack[*top];
        *top=*top-1;
        return val;
    }
}
void display(int stack[] ,int top)
{
    if(top==-1)
    {
        printf("\nUnderflow - Stack is empty");
    }
    else
    {
        printf("\nStack is: ");
        for(int i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}
int main()
{
    int stack[MAX],top=-1;
    int ch,num;
    do
    {
        printf("\nSTACK FUNCTION USING ARRAY");
        printf("\nPRESS 1 - PUSH");
        printf("\nPRESS 2 - POP");
        printf("\nPRESS 3 - DISPLAY");
        printf("\nPRESS 0 - EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter number want to Push in Stack:");
            scanf("%d",&num);
            push(stack,&top,num);
            break;

            case 2:
            num=pop(stack,&top);
            if(num==-1)
            {
                printf("\nNothing Poped");
            }
            else
            {
                printf("\nPoped number is: %d",num);
            }
            break;

            case 3:
            display(stack,top);
            break;
        }
    }while(ch!=0);
    return 0;
}
