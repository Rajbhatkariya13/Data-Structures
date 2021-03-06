#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
The below code is written by bobby in the year 2020
cs represents collection size
es represents size of one element
*/

void bubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}
//following code is being written by sam in year2023
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *) left;
j=(int *) right;
return (*i)-(*j);
}
/* 
following code is being written by sam in year2023
*/
int main()
{
int *x,req,y;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}

x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("unable to allocate memory for %d numbers\n",req);
return 0; 
}
for(y=0;y<req;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}

bubbleSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}