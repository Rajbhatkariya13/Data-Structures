#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<= x[lb]) e++;
while(x[f] > x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int *lbStack,*ubStack,pp,top,size,lb,ub;
size=(upperBound-lowerBound)+1;
//right now i am assuming that malloc won't fail to allocate memory for 
lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;
while(top!=size)
{
//pop
lb=lbStack[top];
ub=ubStack[top];
top++;
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
top--;
lbStack[top]=pp+1;
ubStack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbStack[top]=lb;
ubStack[top]=pp-1;
}
}
free(lbStack);
free(ubStack);
}
int main()
{
FILE *f,*file[10];
int sz,num,totalNumbers,numbersInEachFile,e,g,i,j,count;
int *x;
srand(time(0));
//creating a data file of 500MB
f=fopen("data.d","wb");
while(ftell(f)<(500*1024*1024))
{
num=rand();
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
//find total numbers in data file
f=fopen("data.d","rb");
fseek(f,0,SEEK_END);
sz=ftell(f);
fclose(f);
totalNumbers=sz/4;
numbersInEachFile=totalNumbers/10;
//distribute all data in 10 files after sorting them
x=(int *)malloc(sizeof(int )*numbersInEachFile);
file[0]=fopen("file1.ddd","wb");
file[1]=fopen("file2.ddd","wb");
file[2]=fopen("file3.ddd","wb");
file[3]=fopen("file4.ddd","wb");
file[4]=fopen("file5.ddd","wb");
file[5]=fopen("file6.ddd","wb");
file[6]=fopen("file7.ddd","wb");
file[7]=fopen("file8.ddd","wb");
file[8]=fopen("file9.ddd","wb");
file[9]=fopen("file10.ddd","wb");
f=fopen("data.d","rb");
i=0;
count=0;
while(1)
{
fread(&num,sizeof(int),1,f);
if(feof(f)) break;
x[count]=num;
count++;
if(count==numbersInEachFile)
{
quickSort(x,0,numbersInEachFile-1);
j=0;
while(j<numbersInEachFile)
{
fwrite(&x[j],sizeof(int),1,file[i]);
j++;
}
fclose(file[i]);
count=0;
i++;
}
}
fclose(f);
free(x);
//merging all 10 files into 1 sorted file
file[0]=fopen("file1.ddd","rb");
file[1]=fopen("file2.ddd","rb");
file[2]=fopen("file3.ddd","rb");
file[3]=fopen("file4.ddd","rb");
file[4]=fopen("file5.ddd","rb");
file[5]=fopen("file6.ddd","rb");
file[6]=fopen("file7.ddd","rb");
file[7]=fopen("file8.ddd","rb");
file[8]=fopen("file9.ddd","rb");
file[9]=fopen("file10.ddd","rb");
f=fopen("data2.d","wb");
x=(int *)malloc(sizeof(int)*10);
for(i=0;i<=9;i++)
{
fread(&x[i],sizeof(int),1,file[i]);
}
e=0; 
g=1;
while(!feof(file[0]) || !feof(file[1]) || !feof(file[2]) || !feof(file[3]) || !feof(file[4]) || !feof(file[5]) || !feof(file[6]) || !feof(file[7]) || !feof(file[8]) || !feof(file[9]))
{
while(g<10)
{
if(x[g]<x[e] && !feof(file[g])) e=g;
g++;
}
if(feof(file[e]))
{
e=e+1;
g=e+1;
continue;
}
fwrite(&x[e],sizeof(int),1,f);
fwrite(&x[e],sizeof(int),1,file[e]);
if(feof(file[e])) printf("%d file finished\n",e);
e=0;
g=1;
}
return 0;
}