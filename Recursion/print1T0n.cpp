#include <iostream>

using namespace std;

void print(int i, int x)
{
    if (i > x)
        return;
    cout << i << endl;
    print(i + 1, x);
}

int main()
{
    print(1, 10);
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();