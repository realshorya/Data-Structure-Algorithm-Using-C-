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
        return 0;
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
    char postfix[40];
    int i=0,num1,num2,res;
    printf("\nEnter the Postfix Expression: ");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        if(postfix[i]!='*'&&postfix[i]!='/'&&postfix[i]!='+'&&postfix[i]!='-')
        {
            push(postfix[i]-48);
        }
        else
        {
            num2=pop();
            num1=pop();
            if(postfix[i]=='+')
            res=num1+num2;
            if(postfix[i]=='-')
            res=num1-num2;
            if(postfix[i]=='*')
            res=num1*num2;
            if(postfix[i]=='/')
            res=num1/num2;
            
            push(res);
        }
    }
    printf("\nResult of Postfix Expression are: %d",top->data);
    return 0;
}
