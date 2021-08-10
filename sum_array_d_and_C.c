//sum of array elements using divide and conquerer algo

#include<stdio.h>
#include<stdlib.h>

int SUM(int x[] ,int y ,int z);//function prototyping

int main()
{ 
  int res,i,arr[5],l,h; 
  printf("enter the elements of the arrays:");
  for(i=0;i<5;i++)
      scanf("%d",&arr[i]);
  l=0;
  h=4;
  printf("%i\n",arr[h]);
  res=SUM(arr,l,h);
  printf("the sum of the array is %i",res);
  return 0;
}

int SUM(int x[] ,int y ,int z)
{
    int mid;
    int r,k;
    if(y>z)
      return 0;
    else if(y==z)
        {
          r=x[y];
          return r;
        }
    else
        {
          mid=(y+z)/2;
          k=SUM(x,y,mid)+SUM(x,mid+1,z);
          return k;
        }
    
        
}


