#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Stack;

Stack *top;
void push(int value)
{
    Stack *temp;
    temp=(Stack*)malloc(sizeof(Stack));
    temp->data=value;
    temp->next=top;
    top=temp;
}
int pop()
{
    int val;
    if(top==NULL)
    {
        printf("\nUnderflow - Stack is empty");
        val=-1;
        return val;
    }
    else
    {
        val=top->data;
        Stack *temp=top;
        top=top->next;
        free(temp);
        return val;
    }
}
void display()
{
    if(top==NULL)
    {
        printf("\nUnderflow - Stack is empty");
    }
    else
    {
        printf("\nStack is :");
        for(Stack *p=top;p!=NULL;p=p->next)
        {
            printf("\n%d",p->data);
        }
    }
}
int main()
{
    top=NULL;
    int ch,num;
    do
    {
        printf("\nSTACK FUNCTION USING LINKED LIST");
        printf("\nPRESS 1 - PUSH");
        printf("\nPRESS 2 - POP");
        printf("\nPRESS 3 - DISPLAY");
        printf("\nPRESS 0 - EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter Number want to Push in Stack: ");
            scanf("%d",&num);
            push(num);
            break;

            case 2:
            num=pop();
            if(num==-1)
            {
                printf("\nNothing Poped");
            }
            else
            {
                printf("\nPoped Number: %d",num);
            }
            break;

            case 3:
            display();
            break;
        }
    }while(ch!=0);
    return 0;
}
