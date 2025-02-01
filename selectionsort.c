#include<stdio.h>
#include<stdlib.h>
void selectionsort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nSorted Array are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int *a,n,i;
    printf("How many numbers are there:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(a)*n);
    printf("\nEnter Array Elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered Array are:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    selectionsort(a,n);
    return 0;
}
