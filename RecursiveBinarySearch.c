#include <stdio.h>

/*
 * 이진 탐색(재귀)
 */

int BSearchRecur(int arr[], int first, int last, int target)
{
    int mid;
    if(first > last)
        return -1;

    mid = (first + last) / 2;

    if(arr[mid] == target)
        return mid;

    if(target < arr[mid])
        return BSearchRecur(arr, first, mid -1, target);
    else
        return BSearchRecur(arr, mid +1, last, target);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int), 7);

    if(idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);
}