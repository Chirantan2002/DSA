#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s = "chirantan is a good boy";
    stringstream ss(s);

    string temp;
    while (ss >> temp)
    {
        cout << temp << endl;
    }
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();