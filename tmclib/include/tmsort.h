#ifndef __tmsort__
#define __tmsort__ 2345
#include<tmconst.h>
#include<tmstack.h>
#include<tmerr.h>
#include<tmutils.h>
void mergeSort(void *x,int (*p2f) (void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error);
#endif