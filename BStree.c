#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left,*right;
}BStree;

BStree *root;

void insert(int value)
{
    BStree *temp;
    temp=(BStree*)malloc(sizeof(BStree));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        BStree *ptr=root;
        while(ptr!=NULL)
        {
            if(value>ptr->data)
            {
                if(ptr->right==NULL)
                {
                    ptr->right=temp;
                    break;
                }
                else
                {
                    ptr=ptr->right;
                }
            }
            else if(value<ptr->data)
            {
                if(ptr->left==NULL)
                {
                    ptr->left=temp;
                    break;
                }
                else
                {
                    ptr=ptr->left;
                }
            }
            else
            {
                printf("\nDublicate data is not Allowed");
                free(temp);
                break;
            }
        }
    }
}
void preorder(BStree *ptr)
{
    if(ptr==NULL)
        return;
    printf("\t%d",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void inorder(BStree *ptr)
{
    if(ptr==NULL)
        return;
    inorder(ptr->left);
    printf("\t%d",ptr->data);
    inorder(ptr->right);
}
void postorder(BStree *ptr)
{
    if(ptr==NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("\t%d",ptr->data);
}
int main()
{
    root=NULL;
    int ch,num;
    do{
        printf("\nPRESS 1 - Insert");
        printf("\nPRESS 2 - Traverse");
        printf("\nPRESS 0 - Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter Number To ADD:");
            scanf("%d",&num);
            insert(num);
            break;

            case 2:
            printf("\nPreorder Traversal is:");
            preorder(root);
            printf("\nInorder Traversal is:");
            inorder(root);
            printf("\nPostorder Traversal is:");
            postorder(root);
            break;
        }
    }while(ch!=0);
    return 0;
}
