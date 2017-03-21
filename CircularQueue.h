#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__


#define TRUE  1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

// 원형 큐가 텅 빈 상태: F와 R이 동일한 위치를 가리킨다.
// 원형 큐가 꽉 찬 상태: R이 가리키는 위치의 앞을 F가 기리킨다.
typedef struct _cQueue
{
    int front;      // 큐의 머리
    int rear;       // 큐의 꼬리

    Data queArr[QUE_LEN];

} cQueue;

typedef cQueue Queue;

void QueueInit(Queue* pq);
int QueIsEmpty(Queue* pq);
int NextPosIdx(int pos);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pk);

#endif