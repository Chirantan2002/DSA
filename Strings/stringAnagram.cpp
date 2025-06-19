#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_anagram_by_hashmap(string a, string b) //* T.c = O(n) and S.c = O(n)
{
    if (a.length() != b.length())
        return 0;

    unordered_map<char, int> map;

    for (char c : a)
        map[c]++;

    for (char c : b)
    {
        if (map[c] == 0)
            return 0;
        map[c]--;
    }
    return 1;
}

bool is_anagram_by_sorting(string a, string b) //* T.c = O(nlogn) and S.c = O(1)
{
    if (a.length() != b.length())
        return 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "physicswallah";
    string t = "wallahphysics";

    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());

    int res = is_anagram_by_sorting(s, t);

    if (res)
        cout << "They are anagram";
    else
        cout << "They aren't anagram";
}