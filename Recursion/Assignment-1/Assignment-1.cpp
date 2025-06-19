//* Print increasing decreasing usign Recursive...
//* 1 2 3 4 3 2 1

#include <iostream>

using namespace std;

void print(int x, int i)
{
    if (i > x)
        return;
    cout << i << " ";
    print(x, i + 1);
    if (i > 1)
        cout << i - 1 << " ";
}

int main()
{
    // int i = 1, n;
    // cin >> n;
    // cout << endl;
    // cout << endl;

    print(4, 1);
}