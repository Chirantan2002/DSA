#include <iostream>

using namespace std;

int count = 0;

int steps(int n)
{
    if (n == 0)
        return count;
    if (n % 2 == 0)
    {
        count++;
        steps(n / 2);
    }
    else
    {
        count++;
        steps(n - 1);
    }
}

int main()
{
    cout << steps(25);
}