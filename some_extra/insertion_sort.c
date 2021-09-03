#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,key;
    int *arr;
    printf("enter the number of elements in the array\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("enter the elements in the array");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);  
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>key&&(j>=0))
        {
            arr[j+1]=arr[j];
            j=j-1;

        }
        arr[j+1]=key;
    }
    return 0;
}