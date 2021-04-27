#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *data,int cs,int es,int (*p2f)(void *,void *));
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f;
int si,oep,iep,w;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);

if(w<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
}
int main()
{
int *x,e,req;
printf("Enter requirement : ");
scanf("%d",&req);
x=(int *)malloc(sizeof(int)*req);
for(e=0;e<req; e++)
{
printf("Enter a number : ");
scanf("%d",&x[e]);
}
selectionSort(x,req,sizeof(int),myComparator);
for(e=0;e<req;e++)
{
printf("%d\n",x[e]);
}
return 0;
}