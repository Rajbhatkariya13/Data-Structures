#include<stdio.h>
int power(int base,int power)
{
int i,total,j;
total=1;
j=base;
if(power==0) return 1;
for(i=0;i<=power;i++) total=total*j;
return total;
}
int main()
{
int base,pwr;
int i;
printf("Enter base : ");
scanf("%d",&base);
printf("Enter power :");
scanf("%d",&pwr);
i=power(base,pwr);
printf("%d^%d is equal to %d\n",base,pwr,i);
return 0;
}