#include<stdio.h>
int count=0;
int power(int b,int c);
int pwr(int b,int p);
int pwr(int b,int p)
{
if(p==1) return b;
count++;
return b*power(b,p-1);
}
int power(int b,int c)
{
if(c==0) return 1;
return pwr(b,c);
}
int main()
{
int p,b;
int i;
printf("Enter base : ");
scanf("%d",&b);
printf("Enter power : ");
scanf("%d",&p);
i=power(b,p);
printf("%d^%d is %d\n",b,p,i);
printf("%d copies has been created\n",count);
return 0;
}