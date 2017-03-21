#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
    if(pdeq->head == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq))
    {
        pdeq->tail = newNode;
    }
    else
    {
        pdeq->head->prev = newNode;
    }

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq))
    {
        pdeq->head = newNode;
    }
    else
    {
        pdeq->tail->next = newNode;
    }

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
    Node* delNode;
    Data retData;

    if(DQIsEmpty(pdeq))
    {
        printf("Dequeue Memory Error!");
        exit(-1);
    }

    delNode = pdeq->head;
    retData = delNode->data;

    pdeq->head = pdeq->head->next;

    if(pdeq->head == NULL)
    {
        pdeq->tail = NULL;
    }
    else
    {
        pdeq->head->prev = NULL;
    }

    free(delNode);

    return retData;
}

Data DQRemoveLast(Deque* pdeq)
{
    Node* delNode;
    Data retData;

    if(DQIsEmpty(pdeq))
    {
        printf("Dequeue Memory Error!");
        exit(-1);
    }

    delNode = pdeq->tail;
    retData = delNode->data;

    pdeq->tail = pdeq->tail->prev;

    if(pdeq->tail == NULL)
    {
        pdeq->head = NULL;
    }
    else
    {
        pdeq->tail->next = NULL;
    }

    free(delNode);

    return retData;
}

Data DQGetFirst(Deque* pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Dequeue Memory Error!");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Dequeue Memory Error!");
        exit(-1);
    }

    return pdeq->tail->data;
}