#include <bits/stdc++.h>

using namespace std;

void intToString(int x)
{
    if (x == 0)
    {
        cout << "0";
        return;
    }
    stringstream ss;
    ss << x;
    string s = ss.str();
    cout << s;
}
int main()
{
    int val = 12345;
    intToString(val);
    cout << endl;
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();