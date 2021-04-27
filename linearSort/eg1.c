#include<stdio.h>
int main()
{
int x[10];
int y,e,f,g,size,oep,iep;
size=10;
for(y=0; y<size;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
oep=size-2;
iep=size-1;
for(e=0;e<=oep;e++)
{
f=e+1;
while(f<=iep)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
}
for(y=0; y<size;y++)
{
printf("%d\n",x[y]);
}

return 0;
}