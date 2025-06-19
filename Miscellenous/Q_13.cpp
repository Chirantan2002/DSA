#include <iostream>
// #include <stdlib.h>

using namespace std;

int main(void)
{
    int a[100], i, size = 0;
    int COUNT = 0;
    cout << "Enter the size of the arr: ";
    cin >> size;
    cout << "Enter the elements:";
    for (i = 0; i < size; ++i)
    {
        cout << "\nElement a[" << i << "]: ";
        cin >> a[i];
    }

    for (i = 0; i < sizeof(a); i++)
    {
        if (a[i] % i == 0)
            COUNT++;
    }

    cout<<COUNT;
}