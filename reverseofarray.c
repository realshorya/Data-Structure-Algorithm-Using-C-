#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,n,i;
    printf("How many numbers are in an array:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered Array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nReversed Array Elements:");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
