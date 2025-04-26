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
        printf("\nUnderflow - Stack is empty");
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
    char infix[40],postfix[40];
    int i,j=0;
    printf("\nEnter Infix Expression: ");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='('&&infix[i]!=')')
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(top==NULL||top->data=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top->data!='(')
            {
                postfix[j]=pop();
                j++;
            }
            pop();
        }
        else if(infix[i]=='*'||infix[i]=='/')
        {
            if(top->data=='*'||top->data=='/')
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='-')
        {
            while(top!=NULL)
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
    }
    while(top!=NULL)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("\nPostfix Expression are: %s",postfix);
    return 0;
}
