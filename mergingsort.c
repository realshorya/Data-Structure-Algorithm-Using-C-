#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int n,int b[],int m,int c[])
{
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    if(i<n)
    {
        for(;i<n;i++,k++)
        {
            c[k]=a[i];
        }
    }
    else if(j<m)
    {
        for(;j<m;j++,k++)
        {
            c[k]=b[j];
        }
    }
}
int main()
{
    int *a,*b,*c,d,e,i;
    printf("\nHow many numbers are there for First array:");
    scanf("%d",&d);
    a=(int*)malloc(sizeof(int)*d);
    printf("\nEnter the numbers in Increasing Numbers:");
    for(i=0;i<d;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nHow many numbers are there for Second array:");
    scanf("%d",&e);
    b=(int*)malloc(sizeof(int)*e);
    printf("\nEnter the numbers in Increasing Numbers:");
    for(i=0;i<e;i++)
    {
        scanf("%d",&b[i]);
    }
    c=(int*)malloc(sizeof(int)*(d+e));
    merge(a,d,b,e,c);
    printf("\nMerged array are:");
    for(i=0;i<d+e;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}
