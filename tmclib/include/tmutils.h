#ifndef __tmutils__
#define __tmutils__ 4223
#include<tmconst.h>
#include<tmerr.h>
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error);
#endif