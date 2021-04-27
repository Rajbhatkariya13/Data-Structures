#include<stdio.h>
int main()
{
int x[10],y,li,size,e,f,g;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
size=10;
while(size>1)
{
li=0;
y=1;
while(y<size)
{
if(x[y]>x[li]) li=y;
y++;
}
if(li!=size-1)
{
e=0;
f=li;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
e=0;
f=size-1;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
}
size--;
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}