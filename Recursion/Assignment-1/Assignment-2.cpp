//* Print the sum of the odd numbers in the given range
//* if a = 1, b = 10
//* 1 + 3 + 5 + 7 + 9 = 25

#include <iostream>

using namespace std;

int func(int a, int b, int &sum)
{
    if (a > b)
    {
        return sum;
    }
    // if (a == b)
    // {
    //     if (a % 2 != 0)
    //     {
    //         sum += a;
    //     }
    // }

    if (a % 2 != 0)
    {
        sum += a;
        func(a + 2, b, sum);
    }
    else
    {
        func(a + 1, b, sum);
    }

    return sum;
}

int main()
{
    int sum = 0;
    cout << func(1, 10, sum);
}