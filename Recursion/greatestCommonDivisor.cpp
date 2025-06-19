#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hcf(int a, int b)
{
    for (int i = min(a, b); i >= 2; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int gcd(int a, int b){
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main()
{
    int firstNum = 24, secondNum = 60;
    // cout << hcf(firstNum, secondNum);
    cout << gcd(27, 45);
}