#include <iostream>

using namespace std;

void print(int x)
{
    if (x == 0)
        return;
    cout << x << endl;
    print(x-1);
}

int main()
{
    print(10);
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();