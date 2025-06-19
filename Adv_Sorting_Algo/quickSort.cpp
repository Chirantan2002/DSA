#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[(low + high) / 2], cnt = 0;
    for(int i = low ;i <= high;i++){
        if(i == (low + high) / 2) continue;
        if(arr[i] <= pivot) cnt++;
    }
    int pivotIdx = cnt + low;
    swap(arr[(low + high) / 2], arr[pivotIdx]);
    int i = low, j = high;
    while(i < pivotIdx && j > pivotIdx){
        if(arr[i] <= pivot) i++;
        if(arr[j] > pivot) j--;
        else if(arr[i] > pivot && arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;j--;
        }
    }
    return pivotIdx;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high){
        int pivotIdx = partition(arr, low, high);
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}