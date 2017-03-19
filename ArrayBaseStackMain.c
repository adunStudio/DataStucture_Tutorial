#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
    // 스택 생성 및 초기화
    Stack stack;
    StackInit(&stack);

    // 데이터 삽입
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    SPush(&stack, 6);

    // 데이터 꺼내기
    while(!SIsEmpty(&stack))
    {
        printf("%d ", SPop(&stack));
    }

    return 1;
}