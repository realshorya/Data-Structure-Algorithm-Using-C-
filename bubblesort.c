#include<stdio.h>
#include<stdlib.h>
void bubblesort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nSorted Array Elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int *a,i,n;
    printf("How many numbers are there:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(a)*n);
    printf("\nEnter Array Elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered Array Elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    bubblesort(a,n);
    return 0;
}
