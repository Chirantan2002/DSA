#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> ans(rowIndex + 1, 1);

    for (int i = 0; i < rowIndex; i++)
    {
        for (int j = i; j > 0; j--)
        {
            ans[j] += ans[j - 1];
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << endl;
    cout << "Enter the number of rowIndex: ";
    cin >> n;
    vector<int> v = getRow(n);
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}