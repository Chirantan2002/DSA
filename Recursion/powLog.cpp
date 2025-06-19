#include <iostream>

using namespace std;

int powLog(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    int ans = powLog(x, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    if (n % 2 != 0)
    {
        return ans * ans * x;
    }
    return 0;
}

int main()
{
    cout << powLog(2, 5);
}