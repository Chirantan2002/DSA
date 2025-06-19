#include <iostream>
#include <string>
#include<climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 1000;
    string str = to_string(n);
    cout << "Digits in the number: " << str.length();
}