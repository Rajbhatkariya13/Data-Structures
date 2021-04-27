#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
void __printAllCombinations(char *seed,char *set,int setSize,int maxLength)
{
int i;
int len;
char *tmp;
if(maxLength==0)
{
count++;
printf("%s\n",seed);
return;
}
len=strlen(seed);
tmp=(char *) malloc(sizeof(char)*(len+2));
strcpy(tmp,seed);
for(i=0;i<setSize;i++)
{
tmp[len]=set[i];
tmp[len+1]='\0';
__printAllCombinations(tmp,set,setSize,maxLength-1);
}
free(tmp);
}
void printAllCombinations(char *set,int setSize,int maxLength)
{
__printAllCombinations("",set,setSize,maxLength);
}
int main()
{
char charSet[]={'0','1','2','3','4','5','6','7','8','9'};
printAllCombinations(charSet,10,3); //base address, size of set,max length
printf("%d numbers of combinations are there.\n ",count);
return 0;
}