#define TRUE       1
#define FALSE      0
#define HEAP_LEN 100

typedef char HData;
typedef int  Priority;

typedef struct _heapElem
{
    Priority pr;  // 값이 작을수록 높은 우선순위
    HData  data;

} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;


void HeapInit(Heap* ph) // 힙의 초기화
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) // 힙이 비었는지 확인
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int getParentIDX(int idx) // 부모 노드의 인덱스 값 반환
{
    return idx / 2;
}

int getLChildIDX(int idx) // 왼쪽 자식 노드의 인덱스 값 반환
{
    return idx * 2;
}

int getRChildIDX(int idx) // 오른쪽 자식 노드의 인덱스 값 반환
{
    return getLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int getHiPriChildIDX(Heap* ph, int idx)
{
    // 자식 노드가 존재하지 않는다면,
    if (getLChildIDX(idx) > ph->numOfData)
        return 0;

        // 자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
    else if (getLChildIDX(idx) == ph->numOfData)
        return getLChildIDX(idx);

        // 자식 노드가 둘 다 존재한다면,
    else
    {
        // 오른쪽 자식 노드의 우선순위가 높다면,
        if (ph->heapArr[getLChildIDX(idx)].pr > ph->heapArr[getRChildIDX(idx)].pr)
            return getRChildIDX(idx); // 오른쪽 자식 노드의 인덱스 값 반환
            // 왼쪽 자식 노드의 우선순위가 높다면,
        else
            return getLChildIDX(idx); // 왼쪽 자식 노드의 인덱스 값 반환
    }
}

// 힙에 데이터 저장
void HInsert(Heap* ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;          // 새 노드가 저장될 인덱스 값을 idx에 저장
    HeapElem elem = { pr, data };

    // 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
    while(idx != 1)
    {
        // 새 노드와 부모 노드의 우선순위 비교
        if (pr < (ph->heapArr[getParentIDX(idx)].pr)) // 새 노드의 우선순위가 높다면
        {
            // 부모 노드를 한 레벨 내림, 실제로 내림
            ph->heapArr[idx] = ph->heapArr[getParentIDX(idx)];

            // 새 노드를 한 레벨 올림, 실제로는 올리지는 않고 인덱스 값만 갱신
            idx = getParentIDX(idx);
        }

            // 새 노드의 우선순위가 높지 않다면
        else
            break;
    }

    ph->heapArr[idx] = elem; // 새 노드를 배열에 저장
    ph->numOfData += 1;
}

// 마지막 노드를 루트 노드의 자리로 옮긴 다으메 자식 노드와의 비교를 통해서 제자리를 찾아가게 한다.
HData HDelete(Heap* ph)
{
    HData retData = (ph->heapArr[1]).data;          // 반환을 위해서 삭제할 데이터 저장
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장

    // 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다.
    int parentIdx = 1;  // 루트 노드가 위치해야 할 인덱스 값 저장
    int childIdx;

    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while (childIdx = getHiPriChildIDX(ph, parentIdx))
    {
        // 마지막 노드와 우선순위 비교
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break; // 마지막 노드의 우선순위가 높으면 반복문 탈출

        // 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;  // 마지막 노드가 저장될 위치정보를 한 레벨 내림
    }

    ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
    ph->numOfData -= 1;

    return retData;
}

#include <stdio.h>
int main()
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    HInsert(&heap, 'E', 5);
    HInsert(&heap, 'D', 4);

    while (!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

    return 1;
}