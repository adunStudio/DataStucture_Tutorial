#include <stdio.h>

void swap(int arr[], int idx1, int idx2)
{
    int temp  = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
void QuickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = (left + right) / 2;

    swap(arr, left, pivot);

    int first = left;

    for (int i = left; i <= right; ++i)
    {
        if (arr[i] > arr[left])
        {
            swap(arr, i, ++first);
        }
    }

    swap(arr, first, left);

    QuickSort(arr, left, first -1);
    QuickSort(arr, first +1, right);
}

int main()
{
    int arr[] = {3, 2, 4, 1, 0 , 9, 2, 1, 3, 4, 5, 6, 5, 2};

    QuickSort(arr, 0, sizeof(arr)/sizeof(int) -1);

    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
        printf("%d ", arr[i]);

    printf("\n");

    return 1;
}