#include <iostream>

using namespace std;

int main()
{

    int arr[] = {2, 3, 1, 3, 2, 3, 3, 5, 1};
    int size = 9;
    int temp = 0;
    int max = arr[0];
    int secondLargest;
    int

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            secondLargest = arr[i - 1];
            maxIndex = i;
            secondLargestIndex = i - 1;
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] > 0)
    //     {
    //         cout << arr[i] << " ";
    //     }
    // }

    cout << "The largest element is : " << max << endl;
    cout << "The largest 2nd element is : " << secondLargest << endl;

    return 0;
}