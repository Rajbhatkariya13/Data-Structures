#include<tmutils.h>
#include<stdlib.h>
#include<string.h>
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error)
{
int size1,size2,size3;
void *tmp;
int i1,i2,i3;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
if(es<=0)
{
if(error) *error=ELEM_SIZE_ZERO;
return;
}
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=(size1+size2);
tmp=(void *)malloc(es*size3);
if(tmp==NULL)
{
if(error) *error=MEM_ALLOC_ERROR;
return;
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
//if(x[i1]<x[i2])
if(p2f(x+(i1*es),x+(i2*es))<0)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}else
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
//x[i1]=tmp[i3];
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
//x[i2]=tmp[i3];
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
if(successful) *successful=SUCCESSFUL;
}
