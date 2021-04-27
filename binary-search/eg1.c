#include<stdio.h>
int binarySearch(int *x,int num,int lb,int ub)
{
int mid;
while(lb<=ub)
{
mid=lb+(ub-lb)/2;
if(x[mid]==num) 
{
return mid;
}
if(num<x[mid]) ub=mid-1;
else lb=mid+1;
}
return -1;
}
int main()
{
int x[10],num,i,y;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
printf("Enter number to be searched :");
scanf("%d",&num);
i=binarySearch(x,num,0,9);
if(i!=-1) printf("%d found on % place\n ",x[i],i);
else printf("%d does not exist\n",num);
return 0;
}