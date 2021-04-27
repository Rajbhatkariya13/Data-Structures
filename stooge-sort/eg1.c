#include<stdio.h>
#include<stdlib.h>
void stoogeSort(int *x,int lb,int ub)
{
int g,z,sz,numberOfElements,rLB,lUB;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
sz=ub-lb+1;
if(sz>2)
{
z=sz/3;
numberOfElements=sz-z;
lUB=lb+numberOfElements-1;
rLB=ub-numberOfElements+1;
stoogeSort(x,lb,lUB);
stoogeSort(x,rLB,ub);
stoogeSort(x,lb,lUB);
}
}
int main()
{
int *x,y,req;
printf("Enter your requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int )*req);
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
stoogeSort(x,0,req-1);
for(y=0;y<req;y++) printf("%d\n",x[y]);
free(x);
return 0;
}