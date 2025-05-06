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
    if(top==NULL)
    {
        printf("\nUndervalue - Stack is Empty");
    }
    else
    {
        int val=top->data;
        Stack *temp=top;
        top=top->next;
        free(temp);
        return val;
    }
}
int main()
{
    top=NULL;
    char exp[40];
    int i=0;
    printf("\nEnter the arithmetic expression:");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
         push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
            {
                printf("\nExtra Closing Brackets");
                break;
            }
            else
            pop();
        } 
    }
    if(exp[i]=='\0')
    {
        if(top==NULL)
        {
            printf("\nAll Checked No Extra Parenthesis");
        }
        else
        printf("\nExtra Opening Brackets");
    }
    return 0;
}
