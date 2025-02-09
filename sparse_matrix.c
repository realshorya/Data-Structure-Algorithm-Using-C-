#include<stdio.h>

void EnterSparse(int row[],int col[], int val[], int r,int c)
{
    int i,j,n,num;
    n=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&num);
            if(num!=0)
            {
                row[n]=i;
                col[n]=j;
                val[n]=num;
                n++;
            }
        }
    }
}

void PrintSparse(int row[],int col[],int val[],int r,int c)
{
    int n,i,j;
    n=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(row[n]==i && col[n]==j)
            {
                printf("%d\t",val[n]);
                n++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    int row[10],col[10],val[10],r,c,i,j,num,n;
    printf("How many Rows and Columns are there for Sparse Matrix:");
    scanf("%d %d",&r,&c);
    printf("\nEnter Matrix Eelement:\n");
    EnterSparse(row,col,val,r,c);
    printf("\nEntered Matrix Are:\n");
    PrintSparse(row,col,val,r,c);
    return 0;
}
