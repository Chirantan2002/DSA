#include <iostream>

using namespace std;

int count = 0;

void towerOfHanoi(int n, char source, char helper, char des)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, source, des, helper);
    cout << source << " -> " << des << endl;
    count++;
    towerOfHanoi(n - 1, helper, source, des);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    cout << endl;
    cout << "No. of min moves: " << count;
}