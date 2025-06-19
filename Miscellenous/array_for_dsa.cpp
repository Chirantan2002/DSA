#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int a[100], i, j, size;
    int pos = 0, val = 0;
    system("cls");
    cout << "Enter the size of a: ";
    cin >> size;

    cout << "Enter the elements:";
    for (i = 0; i < size; i++)
    {
        cout << "\nElement a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Enter the index of insertion: " << endl;
    cin >> pos;
    cout << "Enter the val: " << endl;
    cin >> val;

    for (i = pos - 1; i < size - 1; i++)
    {
        a[i + 1] = a[i];
        a[i] = val;
    }
    a[pos - 1] = a[i];

    cout << "\nNow array after insertion:\n";
    for (i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}