#include<stdio.h>
#include<stdlib.h>

/*
void quickSort(int *data,int lowerBound,int upperBound)
{

}
*/
int main()
{
int *x,y,e,f,pp,stack[10][2],top,lowerBound,upperBound,lb,ub;
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
top=req;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=req)
{
//pop
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
//move e forward
while(e<ub && x[e]<=x[lb]) e++;
//move e backward
while(x[f]>x[lb]) f--;
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
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
stack[top][0]=lb;
stack[top][1]=pp-1; 
}
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}