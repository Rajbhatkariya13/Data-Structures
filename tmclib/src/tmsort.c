#include<tmsort.h>
#include<tmutils.h>
void mergeSort(void *x,int (*p2f) (void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b;
Stack stack1;
Stack stack2;
int mid;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(successful) *successful=SUCCESSFUL;
}
