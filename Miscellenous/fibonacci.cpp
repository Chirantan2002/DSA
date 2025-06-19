#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> fib(1000);

    fib[0] = 0;
    fib[1] = 1;

    cout << "Enter the num: ";
    cin >> n;

    for (int i = 2; i <= n - 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n - 1];

    return 0;
}