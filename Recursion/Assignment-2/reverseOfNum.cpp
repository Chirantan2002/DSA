#include <iostream>

using namespace std;

int reverseDigit(int n, int &ans)
{
    if (n <= 0)
        return ans;
    int digit = n % 10;
    ans = ans * 10 + digit;
    return reverseDigit(n / 10, ans);
}

int main()
{
    int n;
    cout << "Enter the num: ";
    cin >> n;
    cout << endl;
    int ans = 0;
    cout << reverseDigit(n, ans);
    cout << endl;
}