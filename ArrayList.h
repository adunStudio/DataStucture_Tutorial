#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "Point.h"

#define TRUE  1
#define FALSE 0

#define LIST_LEN 100

//typedef int LData;
typedef Point* LData;

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;

} ArrayList;

typedef ArrayList List;

void ListInit(List* plist);                  // 초기화
void LInsert(List* plist, LData data);       // 데이터 저장

int LFirst(List* plist, LData* pdata);       // 첫 데이터 참조
int LNext(List* plist, LData* pdata);        // 두 번째 이후 데이터 참조

LData LRemove(List* plist);                  // 참조한 데이터 삭제
int LCount(List* plist);                     // 저장된 데이터의 수 반환

#endif

