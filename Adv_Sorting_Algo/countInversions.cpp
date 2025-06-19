#include <iostream>
#include <vector>
using namespace std;

int inversions(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0, cnt = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            cnt += (a.size() - i); // Count inversions
            j++;
        } else {
            i++;
        }
    }
    return cnt;
}

void merge(vector<int> &a, vector<int> &b, vector<int> &arr) {
    int i = 0, j = 0, k = 0;
    int n1 = a.size(), n2 = b.size();

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }

    while (i < n1) {
        arr[k++] = a[i++];
    }

    while (j < n2) {
        arr[k++] = b[j++];
    }
}

int mergeSort(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1)
        return 0; // Base case: if the array has 0 or 1 element, it's already sorted
                // Split the array into two halves
    int n1 = n / 2, n2 = n - n / 2;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[i + n1];

    int count = 0;
    count += mergeSort(leftArr);
    count += mergeSort(rightArr);

    count += inversions(leftArr, rightArr);

    merge(leftArr, rightArr, arr);

    return count;
}

int main() {
    vector<int> arr = {5, 1, 3, 0, 4, 2, 6};
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int count = mergeSort(arr);
    cout << "Inversion count: " << count << endl;

    return 0;
}