#include <iostream>
#include <string>
#include <vector>

using namespace std;

// void printSubset(string original, string ans)
// {
//     if (original == "")
//     {
//         cout << ans << endl;
//         return;
//     }
//     char ch = original[0];
//     printSubset(original.substr(1), ans + ch);
//     printSubset(original.substr(1), ans);
// }

// void printSubset(string original, string ans, int idx)
// {
//     if (idx == original.length())
//     {
//         cout << ans << endl;
//         return;
//     }
//     char ch = original[idx];
//     printSubset(original, ans + ch, idx + 1);
//     printSubset(original, ans, idx + 1);
// }

void printSubset(string original, string ans, vector<string> &res)
{
    if (original == "")
    {
        res.push_back(ans);
        return;
    }
    char ch = original[0];
    printSubset(original.substr(1), ans + ch, res);
    printSubset(original.substr(1), ans, res);
}

int main()
{
    string str = "abcc";
    vector<string> res;
    printSubset(str, "", res);
    for(auto x: res)cout<<x<<endl;
}