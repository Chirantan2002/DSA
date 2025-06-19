#include <bits/stdc++.h>

using namespace std;

void printFreq(string s)
{
    unordered_map<string, int> freq;

    stringstream ss(s);

    string word;

    while (ss >> word)
        freq[word]++;

    for (auto x : freq)
        cout << x.first << "->" << x.second << endl;
}
int main()
{
    string s = "geeks prints freq of geeks";
    printFreq(s);
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();