#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// 테이블의 초기화
void TBLInit(Table* pt, HashFunc* f)
{
    int i;

    // 모든 슬롯 초기화
    for(i = 0; i < MAX_TBL; ++i)
        (pt->tbl[i]).status = EMPTY;

    pt->hf = f;    // 해쉬 함수 등록
}

// 테이블에 키와 값을 저장
void TBLInsert(Table* pt, Key k, Value v)
{
    int hv = pt->hf(k);

    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;
}

// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table* pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
    {
        (pt->tbl[hv]).status = DELETED;

        return (pt->tbl[hv]).val;    // 소멸 대상의 값 반환
    }
}

// 키를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table* pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tbl[hv]).val;    // 탐색 대상의 값 반환
}