#include<stdio.h>
#include<stdlib.h>
int binarysearch(int a[],int search, int end)
{
    int beg=0,mid,i;
    end--;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==search)
        {
            return mid;
        }
        else if(search>a[mid])
        {
            beg=beg+1;
        }
        else if(search<a[mid])
        {
            end=end+1;
        }
    }
    return -1;
}
int main()
{
    int *a,i,find,n,p;
    printf("How many numbers are there:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(a)*n);
    printf("\nEnter numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered numbers are:");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\nWhat number you want to search:");
    scanf("%d",&find);
    p=binarysearch(a,find,n);
    if(p==-1)
    {
        printf("\nNumber not found!");
    }
    else
    {
        printf("\nNumber found at postion %d",p+1);
    }
    return 0;
}
