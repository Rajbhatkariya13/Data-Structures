#include<stdio.h>
void heapSort(int *x,int lb,int ub)
{
int y,ci,ri,lci,rci,g,swi;

y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ri];
x[ri]=x[ci];
x[ci]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
//implementing heap sort
y=ub;
while(y>lb)
{
g=x[lb];
x[lb]=x[y];
x[y]=g;
y--;
ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(x[lci]>x[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else break;
}
}
}
int main()
{
int x[10],y;
for(y=0; y<=9; y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
heapSort(x,0,9);
for(y=0; y<=9; y++)
{
printf("%d\n",x[y]);
}

return 0;
}