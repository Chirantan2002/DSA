// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&a, vector<int>&b, vector<int>&arr){
    int i = 0, j = 0, k = 0;
    int n1 = a.size(), n2 = b.size();
    
    while(i < n1 && j < n2){
        if(a[i] >= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    
    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void mergeSort(vector<int> &arr){
    int n = arr.size();
    if(n <= 1) return;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> leftArr(n1), rightArr(n2);
    for(int i = 0;i < n1;i++) leftArr[i] = arr[i];
    for(int i = 0;i < n2;i++) rightArr[i] = arr[i+n1];
    
    mergeSort(leftArr);
    mergeSort(rightArr);
    
    merge(leftArr, rightArr, arr);
    
    leftArr.clear();
    rightArr.clear();
}

int main() {
    // Write C++ code here
    vector<int> arr = {39, 25, 64, 79, 86, 7, 60, 48, 38, 1, 21, 68, 47, 99};
    cout << "Original Array: ";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr);
    cout << "Sorted Array: ";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }

    return 0;
}