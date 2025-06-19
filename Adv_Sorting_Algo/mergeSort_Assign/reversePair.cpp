#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void merge(vector<int> &arr, int low, int mid, int high){
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if((long long int)arr[i] > (long long int)2 * arr[j]){
            ans += mid - i + 1;
            j++;
        }
        else i++;
    }

    i = low, j = mid + 1;
    vector<int> brr;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) brr.push_back(arr[i++]);
        else brr.push_back(arr[j++]);
    }
    while(i <= mid) brr.push_back(arr[i++]);
    while(j <= high) brr.push_back(arr[j++]);

    for(int i = low;i <= high;i++) arr[i] = brr[i-low];
    brr.clear();
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int countReversePairs(vector<int> &arr){
    mergeSort(arr, 0, arr.size() - 1);
    return ans;
}

int main(){
    vector<int> arr = {1,3,2,3,1};
    // int ans = countReversePairs(arr);
    cout << "Number of reverse pairs: " << countReversePairs(arr);
    cout << endl;
    return 0;
}