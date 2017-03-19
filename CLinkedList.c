#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
    plist->tail = NULL;
    plist->cur  = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL)          // 첫 번째 노드라면
    {
        plist->tail = newNode;       // tail이 새 노드를 가리키게 한다.
        newNode->next = newNode;     // 새 노드 자신을 가리키게 한다.
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    plist->numOfData ++;
}

void LInsert(List* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL)          // 첫 번째 노드라면
    {
        plist->tail = newNode;       // tail이 새 노드를 가리키게 한다.
        newNode->next = newNode;     // 새 노드 자신을 가리키게 한다.
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;       // LInsertFront 함수와의 유일한 차이점
    }

    plist->numOfData ++;
}


int LFirst(List* plist, Data* pdata)
{
    if(plist->tail == NULL)
    {
        return FALSE;
    }

    plist->before = plist->tail;      // before가 꼬리를 가리키게 한다.
    plist->cur = plist->tail->next;   // cur이 머리를 가리키게 한다.

    *pdata = plist->cur->data;        // cur이 가리키는 노드의 데이터 반환

    return TRUE;
}

int LNext(List* plist, Data* pdata)
{
    if(plist->tail == NULL)
    {
        return FALSE;
    }

    plist->before = plist->cur;      // before가 다음 노드를 가리키게 한다.
    plist->cur = plist->cur->next;   // cur이 다음 노드를 가리키게 한다.

    *pdata = plist->cur->data;

    return TRUE;
}

Data LRemove(List* plist)
{
    Node* rpos  = plist->cur;
    Data rdata = rpos->data;

    if(rpos == plist->tail)                        // 삭제 대상을 tail이 가리킨다면
    {
        if(plist->tail == plist->tail->next)       // 마지막 노드라면
        {
            plist->tail = NULL;
        }
        else
        {
            plist->tail = plist->before;
        }
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    plist->numOfData --;

    return rdata;
}

int LCount(List* plist)
{
    return plist->numOfData;
}


