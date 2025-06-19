#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr, vector<int> &leftArr, vector<int> &rightArr){
    int n1 = leftArr.size(), n2 = rightArr.size();
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(leftArr[i] >= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while(i < n1) arr[k++] = leftArr[i++];
    while(j < n2) arr[k++] = rightArr[j++];
}

void mergeSortDecreasing(vector<int> &arr){
    int n = arr.size();
    if(n <= 1) return;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> leftArr(n1), rightArr(n2);
    for(int i = 0;i < n1;i++) leftArr[i] = arr[i];
    for(int i = 0;i < n2;i++) rightArr[i] = arr[i+n1];

    mergeSortDecreasing(leftArr);
    mergeSortDecreasing(rightArr);
    merge(arr, leftArr, rightArr);

    leftArr.clear();
    rightArr.clear();
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << endl;
    cout << "Enter the array elements: ";
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << endl;
    cout << "Original Array: ";
    for(int i = 0;i < n;i++) cout << arr[i] << " ";
    cout << endl;
    mergeSortDecreasing(arr);
    cout << "Sorted Array in Dec order: ";
    for(int i = 0;i < n;i++) cout << arr[i] << " ";
    return 0;
}