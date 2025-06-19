#include <iostream>

using namespace std;

int stairPath(int n)
{
    if (n <= 3)
        return n;
    return stairPath(n - 1) + stairPath(n - 2) + stairPath(n - 3);
}
int main()
{
    cout << stairPath(5);
}
