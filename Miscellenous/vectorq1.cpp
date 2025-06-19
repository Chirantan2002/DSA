#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 4};
    system("cls");

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cin >> arr[i];
    // }

    // int x;
    // cout << "Enter the key val = ";
    // cin >> x;

    bool sorted = true;
    int sumEven = 0, sumOdd = 0;

    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            sumEven += arr[i];
        }
        else if (i % 2 != 0)
            sumOdd += arr[i];
    }

    cout << "The sum of Evene elements is = " << sumEven << endl;
    cout << "The sum of Odd elements is = " << sumOdd << endl;
    cout << "Congratulations !!" << endl;

    return 0;
}