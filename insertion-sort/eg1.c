#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *x,int lb,int ub)
{
int e,ep,z,y,num;
ep=ub-1;
for(y=lb;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=0&& x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}


/*
while(y<=oep)
{
num=x[y];
z=y-1;
while(z>=0&& x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
*/
}
int main()
{
int req,e,f,*x;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<1)
{
printf("invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);

for(e=0; e<req; e++)
{
printf("Enter a number: ");
scanf("%d",&x[e]);
}
insertionSort(x,0,req);
for(e=0;e<req;e++)
{
printf("%d\n",x[e]);
}
return 0;
}