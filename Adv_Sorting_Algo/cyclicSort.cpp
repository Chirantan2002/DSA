#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {4,1,6,2,5,3};
    int n = arr.size();

    cout << "Original Array: ";
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Cyclic Sort
    int i = 0;
    while (i < n) {
        if (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
        } else {
            i++;
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

