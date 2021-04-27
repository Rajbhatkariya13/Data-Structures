//in this code we are able to maintain multiple stacks at a time
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
void push(Stack *stack,const void *data)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=(void *)malloc(stack->elementSize);
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}
void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void *)t->data,stack->elementSize);
free(t->data);
free(t);
}
int isEmpty(Stack *stack)
{
return stack->size==0;
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
void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int pp,lb,ub;
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
Stack stack;
initStack(&stack,sizeof(struct LBUB));
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack,(const void *)&lbub);
while(!isEmpty(&stack))
{
pop(&stack,(void *)&lbub);
lb=lbub.lb;
ub=lbub.ub;
pp=findPartitionPoint(x,lb,ub,es,p2f);
if(pp+1<ub)
{
lbub.lb=pp+1;
lbub.ub=ub;
push(&stack,(const void *)&lbub);
}
if(lb<pp-1)
{
lbub.lb=lb;
lbub.ub=pp-1;
push(&stack,(const void *)&lbub);
}
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