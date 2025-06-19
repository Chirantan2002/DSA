#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m = 5, n = 2, k = 3;

    vector<vector<int>> v(m, vector<int>(n, k));

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}