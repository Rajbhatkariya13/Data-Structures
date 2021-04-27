#include<stdio.h>
int count=0;
int m[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int power(int b,int c);
int pwr(int b,int c);
int pwr(int b,int c)
{
count++;
if(c==1) return b;
if(m[c]!=0) return m[c];
m[c]=(c%2==0)?pwr(b,c/2)*pwr(b,c/2):b*pwr(b,c/2)*pwr(b,c/2);
return m[c];
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