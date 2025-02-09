#include<stdio.h>
void Insertion(int a[],int n)
{
    int i,num,pos;
    i=n;
    printf("\nEnter What Element and Position want to Add:");
    scanf("%d %d",&num,&pos);
    i=n;
    while(i>=pos)
    {
        a[i]=a[i-1];
        i--;
    }
    a[pos-1]=num;
    n++;
    printf("\nInserted Array are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void Deletion(int a[],int n)
{
    int i,pos;
    printf("\nEnter Position Where You Want To Delete:");
    scanf("%d",&pos);
    if(pos<=n)
    {

        for(i=pos-1;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        a[n-1]=0;
        n--;
        printf("\nDeleted Array Are:");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    else
    {
        printf("\nPlease Enter Valid Position");
    }
}
int main()
{
    int a[10]= {10,20,30,40,50,60,70};
    int i,pos,n=7,num,choice;
    printf("Array Elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nPress-1 To Insert In Array");
    printf("\nPress-2 To Delete Value");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        Insertion(a,n);
        break;

        case 2:
        Deletion(a,n);
        break;

        default:
        printf("\nThis is not a valid input");
        break;
    }
    return 0;
}
