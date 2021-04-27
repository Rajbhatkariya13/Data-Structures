#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,largest,i,j,k,num;
int *tmp;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
tmp=(int *)malloc(sizeof(int)*largest+1);
for(y=0;y<=largest;y++) tmp[y]=0;
for(y=0;y<=9;y++)
{
i=x[y];
tmp[i]=tmp[i]+1;
}
k=0;
for(y=0;y<=largest;y++)
{
num=tmp[y];
j=0;
while(j<num)
{
x[k]=y;
k++;
j++;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}