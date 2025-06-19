//* Given a positive integer return true if it is a power of 2.

#include <iostream>

using namespace std;

bool func(int a)
{
    if(a == 1) return true;
    if(a%2 != 0) return false;
    return func(a/2);
}

int main()
{
    // int sum = 0;
    cout << func(122);
}