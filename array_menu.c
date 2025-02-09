#include<stdio.h>
#include<stdlib.h>
void ReverseofArray(int a[],int n)
{
    int i;
    printf("\nRevered Array elements:");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
void EvenArray(int a[],int n)
{
    int i;
    printf("\nEven Array Elements:");
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            printf("%d ",a[i]);
        }
    }
}
void SumofArray(int a[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("\nSum of Array is : %d",sum);
}
int main()
{
    int *a,n,i,choice;
    printf("How many numbers are in an array:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nPress-1 To Reverse Array");
    printf("\nPress-2 To Find Even In Array");
    printf("\nPress-3 To Sum Array");
    printf("\nEnter Your Choise:");
    scanf("%d",&choice);
    printf("\nEntered Array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    switch(choice)
    {
        case 1:
        ReverseofArray(a,n);
        break;
        
        case 2:
        EvenArray(a,n);
        break;

        case 3:
        SumofArray(a,n);
        break;
    }
    return 0;
}
