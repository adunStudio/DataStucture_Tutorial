#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTbl;

    Person* np;
    Person* sp;
    Person* rp;

    TBLInit(&myTbl, MyHashFunc);

    // 데이터 입력
    np = MakePersonData(20120003, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(20130012, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(20170049, "Han", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    // 데이터 탐색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);

    // 데이터 삭제
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);

    // 데이터 탐색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);

    return 1;
}