#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node *next;
}StackNode;
typedef struct _stack
{
StackNode *top;
int size;
}Stack;
void push(Stack *stack,int data)
{
StackNode *node;
node=(StackNode *)malloc(sizeof(StackNode));
node->data=data;
node->next=stack->top;
stack->top=node;
stack->size++;
}
int pop(Stack *stack)
{
StackNode *node;
int data;
node=stack->top;
data=node->data;
stack->top=stack->top->next;
free(node);
stack->size--;
return data;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}
int main()
{
int x[10],y,smallest,largest,range,index,j;
Stack *stack;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
smallest=x[0];
largest=x[0];
for(y=1;y<=9;y++) 
{
if(x[y]>largest) largest=x[y];
if(x[y]<smallest) smallest=x[y];
}
range=largest-smallest+1;
stack=(Stack *)malloc(sizeof(Stack)*range);
for(y=0;y<range;y++) initStack(&stack[y]);
//spreading elements into stack
for(y=0;y<=9;y++)
{
index=x[y]-smallest;
push(&stack[index],x[y]);
}
//collecting all data sequentially from stack
j=0;
for(y=0;y<range;y++)
{
while(!isEmpty(&stack[y]))
{
x[j]=pop(&stack[y]);
j++;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}