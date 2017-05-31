#include <stdio.h>

/*
 * 보간 탐색
 */

int ISearch(int arr[], int first, int last, int target)
{
    int mid;

    if(first > last)
        return -1;

    // 이진 탐색과의 차이점을 반영한 코드
    mid = ((double)(target-arr[first]) / (arr[last] - arr[first]) * (last-first)) + first;

    if(arr[mid] == target)
        return mid;

    if(target < arr[mid])
        return ISearch(arr, first, mid -1, target);
    else
        return ISearch(arr, mid +1, last, target);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 9, 11, 14, 21};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int) -1, 7);

    if(idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);


    return 1;
}