#include<stdio.h>
#include<stdlib.h>

void selection_naive(int arr[]);
void selection_better(int arr[]);

int main()
{
    int arr[]={5,3,8,4,10};
    //selection_naive(arr);
    selection_better(arr);
   

}

void selection_naive(int arr[])
{   //makes use of another array meaning more memory
     int i,j,min=0;
     int temp[5];

     for(i=0;i<5;i++) // first loop is for filling the temp array with sorted elemnets
    {
        for(j=0;j<5;j++)//this loop is for iterating over the array to find min everytime
        {   
         
            if(arr[j]<arr[min])
                min=j; //finding min everytime
                     
        }
        
        temp[i]=arr[min];// filling temp
        arr[min]=99; //replaving sorted element with infinity
    }

    for(i=0;i<5;i++)
    {
        arr[i]=temp[i];
        printf("%d  ",arr[i]);
    }
}

void selection_better(int arr[])
{
  int i,j,min=0,temp;
     
     for(i=0;i<5;i++)
     {
         for(j=i;j<5;j++)
         {
             if(arr[j]<arr[min])
                min=j;
         }
         temp=arr[i];
         arr[i]=arr[min];
         arr[min]=temp;
     }

    printf("the sorted array is :");
    for(i=0;i<5;i++)
    {  
        
        printf("%d  ",arr[i]);
    }
}