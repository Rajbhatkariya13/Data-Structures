#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10];
int y,e,f,lb,ub,swpCnt,g;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
while(lb<ub)
{
e=lb;
f=e+1;
swpCnt=0;
while(e<=ub-1)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swpCnt++;
}
e++;
f++;
}
ub--;
if(swpCnt==0) break;
f=ub;
e=f-1;
swpCnt=0;
while(e>=lb)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swpCnt++;
}
e--;
f--;
}
lb++;
if(swpCnt==0) break;
}

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}