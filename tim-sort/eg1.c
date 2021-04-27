#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3;
int *tmp;
int i1,i2,i3;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=(size1+size2);
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}
void insertionSort(int *x,int lb,int ub)
{
int e,ep,z,y,num;
ep=ub-1;
for(y=lb;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=0&& x[z]>num;z--) x[z+1]=x[z];
x[z+1]=num;
}
}
int main()
{
int *x;
int n,sz,i,numberOfSegments;
FILE *f;
int lb,ub,z,lb1,lb2,ub1,ub2,p;
f=fopen("data.d","rb");
fseek(f,0,2);
sz=ftell(f);
n=sz/4;
printf("number of records: %d\n",n);
x=(int *)malloc(sizeof(int)*n);
fseek(f,0,0);
for(i=0;i<n;i++)
{
fread(&x[i],sizeof(int),1,f);
}
numberOfSegments=n/64;
if(n%64!=0) numberOfSegments++;
//sorting of segments of 64 elements
i=0;
while(i<numberOfSegments)
{
lb=i*64;
ub=lb+64-1;
if(ub>n) ub=n-1;
insertionSort(x,lb,ub);
i++;
}
for(p=64;p<n;p=2*p)
{
for(lb1=0;lb1<n;lb1=lb1+2*p)
{
ub1=lb1+p-1;
lb2=ub1+1;
ub2=(lb1+2*p)-1;
if(lb2>=n) break;
if(ub2>=n) ub2=n-1;
merge(x,lb1,ub1,lb2,ub2);
}
}
for(i=0;i<n;i++) printf("%d\t",x[i]);
fclose(f);
return 0;
}