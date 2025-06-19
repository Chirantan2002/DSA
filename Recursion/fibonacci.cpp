#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    //* Iterative approach
    // vector<int> fib;
    // fib.push_back(0);
    // fib.push_back(1);
    // for (int i = 2; i <= x; i++)
    // {
    //     fib.push_back(fib[i - 1] + fib[i - 2]);
    // }
    // return fib[x];

    //* Recursive approach (But slows down the program for large values)
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    cout << fibonacci(7);
}