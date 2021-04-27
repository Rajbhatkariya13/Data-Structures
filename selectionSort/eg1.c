#include<stdio.h>
#include<stdlib.h>
void selctionSort(int *,int );
void selectionSort(int *x,int size)
{
int e,g,f;
int si,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
}
int main()
{
int *x,e,req;
printf("Enter requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(e=0;e<req; e++)
{
printf("Enter a number : ");
scanf("%d",&x[e]);
}
selectionSort(x,req);
for(e=0;e<req;e++)
{
printf("%d\n",x[e]);
}
return 0;
}