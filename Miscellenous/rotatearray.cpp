#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int k = 2;
    k = k % v.size();
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());

    for (int a : v)
    {
        cout << a << " ";
    }

    // int array[] = {1, 2, 3, 4, 5};
    // int size = 5;
    // int k = 2;
    // k = k % size;
    // int ansArray[5];
    // int temp = 0;

    // for (int i = abs(size - k); i < size; i++) // inserting last k elements
    // {

    //     ansArray[temp++] = array[i];
    // }
    // for (int i = 0; i <= k; i++) // inserting first n-k elements
    // {
    //     ansArray[temp++] = array[i];
    // }
    // for(int i=0;i<size;i++){
    //     cout<<ansArray[i]<<" ";
    // }

        return 0;
}