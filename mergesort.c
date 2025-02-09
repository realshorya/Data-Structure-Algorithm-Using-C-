#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void Merge(int a[],int beg1,int end1,int end2)
{
    int beg2=end1+1;
    int b[MAX];
    int i,j,k;
    i=k=beg1;
    j=beg2;
    while(i<=end1 && j<=end2)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    if(i<=end1)
    {
        for(;i<=end1;i++,k++)
        {
            b[k]=a[i];
        }
    }
    else
    {
        for(;j<=end2;j++,k++)
        {
            b[k]=a[j];
        }
    }
    for(i=beg1;i<=end2;i++)
    {
        a[i]=b[i];
    }
}
void MergeSort(int a[],int beg,int end)
{
    if(beg==end)
    {
        return;
    }
    int mid=(beg+end)/2;
    MergeSort(a,beg,mid);
    MergeSort(a,mid+1,end);
    Merge(a,beg,mid,end);
} 
int main()
{
    int *a,n,i;
    printf("How many numbers are there in array:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter Array Elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered Array Elements:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    MergeSort(a,0,n-1);
    printf("\nSorted Array Elements:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
