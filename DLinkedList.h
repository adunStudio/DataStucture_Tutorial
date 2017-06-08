#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE  1
#define FALSE 0

#include "Slot2.h"

typedef int LData;

//typedef Slot LData;

typedef struct _node
{
    LData data;
    struct _node* next;

} Node;

typedef struct _linkedList
{
    Node* head;                         // 연결 리스트의 머리를 가리키는 포인터 변수 -> 더미 노드를 가리키는 멤버
    Node* cur;                          // 참조를 위한 포인터 변수 -> 참조 및 삭제를 돕는 변수
    Node* before;                       // 삭제를 돕는 멤버

    int numOfData;                      // 저장된 데이터의 수를 기록하기 위한 멤버
    int (*comp)(LData d1, LData d2);    // 정렬의 기준을 등록하기 위한 멤버

} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void FInsert(List* plist, LData data);
void SInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

// 리스트 정렬에 기준이 되는 함수를 등록한다.
void SetSortRule(List* plist, int (*comp)(LData d1, LData dc2));

#endif