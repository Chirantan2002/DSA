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

int kthSmallest(int arr[], int low, int high, int k)
{
    if(low < high){
        int pivotIdx = partition(arr, low, high);
        if(pivotIdx + 1 == k) return arr[pivotIdx];
        else if(pivotIdx + 1 > k) return kthSmallest(arr, low, pivotIdx - 1, k);
        else return kthSmallest(arr, pivotIdx + 1, high, k);
    }
}

int kthLargest(int arr[], int low, int high, int k)
{
    int n = high - low + 1;
    return kthSmallest(arr, low, high, n - k + 1);
}

int main()
{
    int arr[] = {12, 5, 7, 3, 19, 8, 2, 15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // quickSort(arr, 0, n - 1);

    int k = 4;
    cout << kthLargest(arr, 0, n - 1, k);

    return 0;
}