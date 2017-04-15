#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}


int HIsEmpty(Heap* ph)        // 힙이 비었는지 확인
{
    return ph->numOfData == 0;
}

int GetParentIDX(int idx)    // 부모 노드의 인덱스 값 반환
{
    return idx / 2;
}

int GetLChildIDX(int idx)
{
    return idx * 2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
    // 자식 노드가 존재하지 않는다면,
    if (GetLChildIDX(idx) > ph->numOfData)
    {
        return 0;
    }

        // 자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
    else if (GetLChildIDX(idx) == ph->numOfData)
    {
        return GetLChildIDX(idx);
    }

    else
    {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
        {
            return GetRChildIDX(idx);
        }
        else
        {
            return GetLChildIDX(idx);
        }
    }
}

void HInsert(Heap* ph, HData data)
{
    int idx = ph->numOfData+1;

    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
        {
            break;
        }
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
    HData retData  = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;

    return retData;
}