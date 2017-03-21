#include <stdio.h>
#include "Deque.h"

int main()
{
    Deque deque;
    DequeInit(&deque);

    DQAddFirst(&deque, 3);
    DQAddFirst(&deque, 2);
    DQAddFirst(&deque, 1);

    DQAddLast(&deque, 4);
    DQAddLast(&deque, 5);
    DQAddLast(&deque, 6);
    while(!DQIsEmpty(&deque))
    {
        printf("%d ", DQRemoveFirst(&deque));
    }

    return 0;
}