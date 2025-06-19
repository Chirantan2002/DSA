#include <iostream>

using namespace std;

void temp(int p)
{
    int q = p;
    q = q - 100;
    // here it is formal parameter
}

int main()
{
    int p = 890;
    temp(p);
    cout << endl
         << (p);

    // p is actual parameters
    return 0;
}