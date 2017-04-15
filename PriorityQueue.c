#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue* ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

void PQIsEmpty(PQueue* ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data)
{
    HInsert(ppq, data);
}

PQData PDequeue(PQeueue* ppq)
{
    return HDelete(ppq);
}