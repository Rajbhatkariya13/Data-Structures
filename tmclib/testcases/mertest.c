#include<stdio.h>
#include<stdlib.h>
#include<tmsort.h>

int intComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int *x,y,req;
int ub,lb;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement");
return 0;
}
lb=0;
ub=req-1;
x=(int *)malloc(sizeof(int)*req);
int successful;
int errorNumber;
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
mergeSort(x,intComparator,sizeof(int),lb,ub,&successful,&errorNumber);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}