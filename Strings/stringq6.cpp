#include <bits/stdc++.h>

using namespace std;

int main()
{
    string arr[] = {"0123", "0023", "456", "1234", "940", "2901"};
    int max_ele = stoi(arr[0]);
    int idx = 0;

    for (int i = 1; i <= 5; i++)
    {
        int temp = stoi(arr[i]);
        if (temp > max_ele)
        {
            max_ele = temp;
            idx = i;
        }
    }

    cout << "Max int: " << max_ele << endl
         << "Which has index: " << idx << endl;
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();