#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    int n = strs.size();

    for (string x : strs)
    {
        cout << x << endl;
    }

    cout << "----------------------" << endl;

    std::sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[n - 1];
    string res = "";

    for (int i = 0; i < std::min(first.size(), last.size()); i++)
    {
        if (first[i] == last[i])
        {
            res += first[i];
        }
    }

    cout << res;
}