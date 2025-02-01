#include<stdio.h>
#include<stdlib.h>
void linearsearch(int a[],int size,int search)
{
    int i,count=0;
    for(i=0;i<size;i++)
    {
        if(a[i]==search)
        {
            printf("\nYour number %d is Found at Position %d",search,i+1);
            count++;
            break;
        }
    }
    if(count==0)
    {
        printf("\nNumber not found");
    }
}
int main()
{
    int *a,i,n,find;
    printf("How many numbers are there in Array:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(a)*n);
    printf("\nEnter Array numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEntered numbers are:");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\nWhat number you wanrt to seaerch in array:");
    scanf("%d",&find);
    linearsearch(a,n,find);
    return 0;
}
