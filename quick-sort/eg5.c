//generic quick sort, because of "top"(global) pointer in this code, we are just able to maintain a single stack.
//what if we want to maintain more than one stack??
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node *top;
int isEmpty()
{
return top==NULL;
}
void push(int lowerBound,int upperBound)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->lb=lowerBound;
t->ub=upperBound;
t->next=top;
top=t;
}
void pop(int *lowerBound,int *upperBound)
{
struct Node *t;
*lowerBound=top->lb;
*upperBound=top->ub;
t=top;
top=top->next;
free(t);
}
int findPartitionPoint(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(x+(e*es),x+(lb*es))<=0) e++;
//while(e<ub && x[e]<=x[lb]) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
//while(x[f]>x[lb]) f--;
if(e<f)
{
memcpy(g,(const void *)(x+(e*es)),es);
//g=x[e];
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
//x[e]=x[f];
memcpy(x+(f*es),(const void *)g,es);
//x[f]=g;
}
else
{
memcpy(g,(const void *)(x+(lb*es)),es);
//g=x[lb];
memcpy(x+(lb*es),(const void *)(x+(f*es)),es);
//x[lb]=x[f];
memcpy(x+(f*es),(const void *)g,es);
//x[f]=g;
}
}
free(g);
return f;
}
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void*))
{
int lb,ub,pp;
push(lowerBound,upperBound);
while(!isEmpty())
{
pop(&lb,&ub);
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub) push(pp+1,ub);
if(lb<pp-1) push(lb,pp-1);
}
}
int main()
{
int *x,req,y;
int lowerBound;
int upperBound;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lowerBound=0;
upperBound=req-1;
quickSort(x,lowerBound,upperBound,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}