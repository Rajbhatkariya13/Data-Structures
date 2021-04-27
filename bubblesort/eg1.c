#include<stdio.h>
void bubbleSort(int *arr,int size);
int main()
{
int sizeOfArray,x;
printf("Enter the Number of elements : ");
scanf("%d",&x);
if(x<=0) 
{
printf("Enter a +ive value\n");
return 0;
}
int arr[x];

for(int e=0; e<x; e++)
{
printf("Enter a number: ");
scanf("%d",&arr[e]);
}
bubbleSort(arr,x);
for(int e=0; e<x; e++)
{
printf("%d  ",arr[e]);
}
return 0;
}
void bubbleSort(int *arr,int size)
{
int e,f,g;
int m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(arr[e]>arr[f])
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
e++;
f++;
}
m--;
}
}