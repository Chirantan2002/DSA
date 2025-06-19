/* This C++ code is designed to find the maximum frequency of a lowercase letter in a given string.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lowercase_counting(string str) //* T.c = O(n) and S.c = O(n)
{
    vector<int> temp(26, 0);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            temp[str[i] - 'a']++;
        }
    }

    int maxCount = 0;
    vector<char> characters(26, '#');
    for (int i = 0; i < 26; i++)
    {
        if (temp[i] > maxCount)
            maxCount = temp[i];
    }

    for (int i = 0; i < 26; i++)
    {
        if (temp[i] == maxCount)
        {
            int ascii = i + 97;
            characters[i] = char(ascii);
        }
    }

    for(auto &it : characters) cout << it << " ";
    cout << endl;

    return maxCount;
}

int helper(string strs) //* TC = O(n), SC = O(n).
{
    unordered_map<char, int> freqMap;
    for (auto ch : strs)
        freqMap[ch]++;

    int max_count = 0;
    for (auto it : freqMap)
    {
        if (max_count < it.second)
            max_count = it.second;
    }
    return max_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str = "physicswallah";

    int res = helper(str);
    int ans = lowercase_counting(str);

    cout << "Max count is: " << res << endl;
    cout << "Max count is: " << ans;
}