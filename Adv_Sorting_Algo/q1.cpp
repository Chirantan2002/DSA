#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a[] = {4,2,3,1,5};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Original array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int firstIdx = -1, lastIdx = -1;
    for(int i = 0;i < n - 1;i++){
        if(a[i] > a[i+1]){
            if(firstIdx == -1) firstIdx = i;
            else if(firstIdx != -1){
                lastIdx = i + 1;
                break;
            }
        }
    }
    swap(a[firstIdx], a[lastIdx]);

    cout << "Array after correction: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}