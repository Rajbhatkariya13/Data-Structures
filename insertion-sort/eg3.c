#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
void *block;
block=(void *)malloc(es);
y=lb+1;
while(y<=ub)
{
memcpy(block,(void *)(x+(y*es)),es);
z=y-1;
while(z>=lb && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}
int intComparator(void *left,void *right)
{
int *a,*b;
a	=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main()
{
int start,end;
int *x,y,z,num,req;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requiremet\n");
return 0;
}
printf("Enter start point : ");
scanf("%d",&start);
printf("Enter end point : ");
scanf("%d",&end);
if(start<0 && start>=req)
{
printf("Invalid start point %d in case of collection of %d numbers\n",start,req);
return 0;
}
if(end<start && end>=req)
{
printf("Invalid end point %d in case of collection of %d numbers\n",end,req);
return 0;
}

x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
insertionSort(x,start ,end,sizeof(int),intComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}
