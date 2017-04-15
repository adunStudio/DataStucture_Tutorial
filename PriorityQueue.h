#ifndef __PRIORITY_QUEUE_C__
#define __PRIORITY_QUEUE_C__

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue* ppq, PriorityComp pc);
int PQIsEmpty(PQueue* ppq);

void PEnqueue(PQueue* ppq, PQData data);
PQData PDequeue(PQueue* ppq);

#endif