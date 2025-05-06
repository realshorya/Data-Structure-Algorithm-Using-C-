/*Only Beginner level of conversion can be done*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void reversestr(char *str)
{
    int len = strlen(str);
    for(int i=0;i<len;i++)
    if(str[i]=='(')
    {
        push(')');
    }
    else if(str[i]==')')
    {
        push('(');
    }
    else
    push(str[i]);
    for(int i=0;i<len;i++)
    str[i]=pop();
}
int main()
{
    top=NULL;
    char infix[40],postfix[40];
    int i,j=0;
    printf("\nEnter Infix Expression: ");
    scanf("%s",infix);
    reversestr(infix);
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
    strrev(postfix);
    printf("\nPrefix Expression are: %s",postfix);
    return 0;
}
