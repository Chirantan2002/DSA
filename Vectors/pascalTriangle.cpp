#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal;

    for (int i = 1; i <= numRows; i++)
    {
        vector<int> a(i);
        pascal.push_back(a);
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    return pascal;
}

int main()
{
    int n;
    cout << endl;
    cout << "Enter the number of rows: ";
    cin >> n;
    vector<vector<int>> v = generate(n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}