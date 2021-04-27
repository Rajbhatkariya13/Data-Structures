#include<stdio.h>
#include<stdlib.h>
void linearSort(int *,int);
void linearSort(int *x,int size)
{
int oep;
int iep;
int e;
int f;
int g;
oep=size-2;
iep=size-1;
e=0;
f=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
}
int main()
{
int *x,req;
int e=0;
printf("Enter requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(e=0;e<req; e++)
{
printf("Enter a number : ");
scanf("%d",&x[e]);
}
linearSort(x,req);
for(e=0;e<req;e++)
{
printf("%d\n",x[e]);
}

return 0;
}