#include <stdio.h>

/*
 * 버블 정렬
 * - 인접합 두 개의 데이터를 비교해가면서 정렬을 진행하는 방식
 * 빅오: n^2
 */
void BubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n-1; ++i)
    {
        for(j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j +1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[4] = {3, 2, 4, 1};

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for(int i = 0; i < 4; ++i)
        printf("%d ", arr[i]);

    printf("\n");

    return 1;
}