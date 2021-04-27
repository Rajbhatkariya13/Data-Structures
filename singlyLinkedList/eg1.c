#include<stdio.h>
#include<malloc.h>
struct Node  *top;
struct Node
{
int data;
struct Node *next;
};
void push(int data)
{
struct Node *node;
node=(struct Node *) malloc(sizeof(struct Node));
node->data=data;
node->next=top;
top=node;
}
int isEmpty()
{
return top==NULL;
}
int pop()
{
int data;
struct Node *node;
data=top->data;
node=top;
top=top->next;
free(node);
return data;
}
int main()
{
top=NULL;
int i=0;
while(i<99)
{
push(i);
i++;
}
i=0;
while(i<99)
{
printf("%d _ ",pop());
i++;
}
}
