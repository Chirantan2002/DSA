#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void generate(int open, int close, string str, int n, vector<string> &ans)
{
    if (close == n)
    {
        ans.push_back(str);
        return;
    }
    if (open < n)
        generate(open + 1, close, str + '(', n, ans);
    if (close < open)
        generate(open, close + 1, str + ')', n, ans);
}

int main()
{
    // string s = "";
    vector<string> ans;
    generate(0, 0, "", 3, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}