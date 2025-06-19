#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cout << "Enter the even string: ";
    cin >> str;

    cout << str.substr(str.length() / 2, str.length() / 2);
}