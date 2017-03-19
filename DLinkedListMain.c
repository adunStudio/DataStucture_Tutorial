#include <stdio.h>
#include "DLinkedList.h"
int whoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
    {
        return 0;
    }

    return 1;
}
int main()
{
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, whoIsPrecede);

    // 5개의 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }

    // 숫자 2를 검색하여 모두 삭제
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        if(data == 2)
        {
            LRemove(&list);
        }

        while(LNext(&list, &data))
        {
            if(data == 2)
            {
                LRemove(&list);
            }
        }
    }


    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        {

            printf("%d ", data);
        }
    }
}

