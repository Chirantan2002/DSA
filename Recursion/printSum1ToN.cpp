#include <iostream>

using namespace std;

// void sum(int x, int n)
// {
//     if (n == 0)
//     {
//         cout << x << endl;
//         return;
//     }
//     sum(x + n, n - 1);
// }

// int sum(int x, int n)
// {
//     if (n == 0)
//         return x;

//     int ans = sum(x + n, n - 1);
//     return ans;
// }

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int main()
{
    cout << sum(5);
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();