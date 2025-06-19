#include <iostream>

using namespace std;

// int factorial(int x) //* iterative approach
// {
//     //base case
//     if (x == 0 && x == 1)
//         return 1;

//     int fact = 1;
//     for (int i = 1; i <= x; i++)
//     {
//         fact *= i;
//     }
//     return fact;
// }

int factorial(int x) //* recursive approach
{
    //! base case
    if (x == 0)
        return 1;

    //! recursive call
    return x * factorial(x - 1);
}

int main()
{
    int fact = factorial(1);
    cout << "Factorial is: " << fact << endl;
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();