#include<stdio.h>
#include<stdlib.h>
typedef struct __LinkedList
{
struct __LinkedListNode *start;
int size;
}LinkedList;
typedef struct __LinkedListNode
{
int data;
struct __LinkedListNode *next;
}LinkedListNode;
void add(LinkedList *ll,int data)
{
LinkedListNode *node,*nn,*pp;
int i,num;
node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
node->data=data;
node->next=NULL;
if(ll->start==NULL)
{
ll->start=node;
ll->size++;
return;
}else
{
pp=NULL;
nn=ll->start;
while(nn!=NULL)
{
num=nn->data;
if(num>=data)
{
if(pp!=NULL)
{
node->next=nn;
pp->next=node;
ll->size++;
return;
}else
{
node->next=ll->start;
ll->start=node;
ll->size++;
return;
}
}
pp=nn;
nn=nn->next;
}
if(nn==NULL)
{
pp->next=node;
ll->size++;
}
}
}
int removeNode(LinkedList *ll)
{
LinkedListNode *node;
int num;
node=ll->start;
ll->start=ll->start->next;
num=node->data;
ll->size--;
free(node);
return num;
}
int isEmpty(LinkedList *ll)
{
return ll->size==0;
}
void initLinkedList(LinkedList *ll)
{
ll->start=NULL;
ll->size=0;
}
int main()
{
int x[10],y,largest,dc,e,f,num,index;
LinkedList boxes[10];
for(y=0;y<=9;y++) initLinkedList(&boxes[y]);
for(y=0;y<=9;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++) if(x[y]>largest) largest=x[y];
dc=1;
num=largest;
while(num>9)
{
dc++;
num=num/10;
}
int hash(int x)
{
int e=1;
while(e<dc)
{
x=x/10;
e++;
}
return x;
}
for(y=0;y<=9;y++)
{
index=hash(x[y]);
add(&boxes[index],x[y]);
}
e=0;
for(y=0;y<=9;y++)
{
while(!isEmpty(&boxes[y]))
{
x[e]=removeNode(&boxes[y]);
e++;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
}