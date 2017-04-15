#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2)        // 우선순위 비교함수
{
    return ch2 - ch1;
}

int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A');
    HInsert(&heap, 'C');
    HInsert(&heap, 'B');

    while (!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

    return 1;
}