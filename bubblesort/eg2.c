#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *arr,int size);
int main()
{
int size,e;
int *arr;
printf("Enter the Number of elements : ");
scanf("%d",&size);
arr=(int *)malloc(sizeof(int)*size);
for(e=0;e<size;e++)
{
printf("Enter a Number : ");
scanf("%d",&arr[e]);
}
bubbleSort(arr,size);
for(e=0;e<size;e++)
{
printf("%d\n",arr[e]);
}
free(arr);
return 0;
}
void bubbleSort(int *arr,int size)
{
int e,g,f,m;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(*(arr+f)<*(arr+e))
{
g=*(arr+f);
*(arr+f)=*(arr+e);
*(arr+e)=g;
}
e++;
f++;
}
m--;
}
}

