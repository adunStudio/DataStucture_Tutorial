#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->next = NULL;
    plist->tail->prev = plist->head;

    plist->numOfData = 0;
}


void LInsert(List* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;


    /*newNode->next = plist->head;
    if(plist->head != NULL)
    {
        plist->head->prev = newNode;     // 두 번째 이후의 노드를 추가할 때만 실행
    }

    newNode->prev = NULL;
    plist->head = newNode;               // 포인터 변수 head가 새 노드 가리키게 함 */


    plist->numOfData++;
}

int LFirst(List* plist, Data* pdata)
{
    if(plist->head->next == plist->tail)
    {
        return FALSE;
    }

    plist->cur = plist->head->next;            // cur이 첫 번째 노드를 가리키게 함
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List* plist, Data* pdata)
{
    if(plist->cur->next == plist->tail)
    {
        return FALSE;
    }

    plist->cur = plist->cur->next;       // cur을 오른쪽으로 이동
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List* plist, Data* data)
{
    if(plist->cur->prev == plist->head)
    {
        return FALSE;
    }

    plist->cur = plist->cur->prev;      // cur을 왼쪽으로 이동
    *pdata = plist->cur->prev;

    return TRUE;
}

Data LRemove(List* plist)
{
    Node* rpos = plist->cur;
    Data remv = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;              // cur의 위치를 재조절

    free(rpos);

    plist->numOfData--;

    return remv;
}

int LCount(List* plist)
{
    return plist->numOfData;
}