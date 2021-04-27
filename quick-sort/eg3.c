#include<stdio.h>
#include<stdlib.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<= x[lb]) e++;
while(x[f] > x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int *lbStack,*ubStack,pp,top,size,lb,ub;
size=(upperBound-lowerBound)+1;
//right now i am assuming that malloc won't fail to allocate memory for 
lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;
while(top!=size)
{
//pop
lb=lbStack[top];
ub=ubStack[top];
top++;
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
top--;
lbStack[top]=pp+1;
ubStack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbStack[top]=lb;
ubStack[top]=pp-1;
}
}
free(lbStack);
free(ubStack);
}

int main()
{
int *x,y,e,f,lowerBound,upperBound;
int g,req;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0) 
{
printf("Invalid requirement of %d numbers\n",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
lowerBound=0;
upperBound=req-1;
quickSort(x,lowerBound,upperBound);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}