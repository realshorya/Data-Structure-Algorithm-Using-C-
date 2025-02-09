#include<stdio.h>
#include<stdlib.h>
void insertionsort(int a[],int n)
{
    int i,j,temp;
    for(j=1;j<n;j++)
    {
        temp=a[j];
        i=j-1;
        while(temp<a[i] && i>-1)
        {
            a[i+1]=a[i];
            i=i-1;//this is doned to check back numbers in array 
        }
        a[i+1]=temp;
    }
}
int main()
{
    int *a,n,i;
    printf("\nHow many numbers are there in Arrray:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter Array Numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered Array are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    insertionsort(a,n);
    printf("\nSorted Array are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
