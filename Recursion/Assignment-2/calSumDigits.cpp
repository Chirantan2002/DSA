#include <iostream>

using namespace std;

int digitSum(int n)
{
    if (n >= 0 and n <= 9)
        return n;
    int digit = n % 10;
    int res = digit + digitSum(n / 10);
    return res;
}

int main()
{
    cout << digitSum(555);
}