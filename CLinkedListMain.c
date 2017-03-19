#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
    // 원현 연결 리스트의 생성 및 초기화
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    // 리스트에 5개의 데이터를 저장
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
//바보입니당 헤헷 ㅇㅅㅇ)/

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i = 0; i < LCount(&list) - 1; ++i)
        {
            if(LNext(&list, &data))
            {
                printf("%d ", data);

            }
        }

    }
    return 0;
}