#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
    pstack->head = NULL;                  // 포인터 변수 head는 NULL로 초기화
}

int SIsEmpty(Stack* pstack)
{
    if(pstack->head == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

void SPush(Stack* pstack, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;      // 새 노드가 최근에 추가된 노드를 가리킴

    pstack->head = newNode;            // 포인터 변수 head가 새 노드를 가리킴
}

Data SPop(Stack* pstack)
{
    Data rdata;
    Node* rnode;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdata = pstack->head->data;        // 삭제할 노드의 데이터를 임시로 저장
    rnode = pstack->head;

    pstack->head = pstack->head->next; // 삭제할 노드의 다음 노드를 head가 가리킴
    free(rnode);

    return rdata;
}

Data SPeek(Stack* pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}