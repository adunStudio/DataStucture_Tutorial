#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
    // 연결 리스트 기반의 큐가 비었다면 F에 NULL이 저장된다.
    pq->front = NULL;
    pq->rear  = NULL;
}

int QIsEmpty(Queue* pq)
{
    if(pq->front == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq))        // 첫 번째 노드의 추가라면,
    {
        pq->front = newNode;   // F가 새 노드를 가리키게 하고
        pq->rear  = newNode;   // R도 새 노드를 가리키게 한다.
    }
    else
    {
        pq->rear->next = newNode;   // 마지막 노드가 새 노드를 가리키게 하고,
        pq->rear = newNode;         // R이 새 노드를 가리키게 한다.
    }
}

Data Dequeue(Queue* pq)
{
    Node* delNode;
    Data retData;

    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);

    return retData;
}

Data QPeek(Queue* pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->front->data;
}