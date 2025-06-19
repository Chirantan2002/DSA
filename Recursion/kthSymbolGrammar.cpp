#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kthGrammar(int n, int k)
{
    if (n == 1)
        return 0;
    if (k == 1)
        return 0;
    if (k % 2 == 0)
        return (kthGrammar(n - 1, k / 2)) == 0 ? 1 : 0;
    else
        return (kthGrammar(n - 1, (k + 1) / 2)) == 0 ? 0 : 1;
}

int main()
{
    int n, k;
    n = 2, k = 2;
    cout << kthGrammar(n, k);
    return 0;
}