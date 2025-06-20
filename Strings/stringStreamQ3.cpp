#include <bits/stdc++.h>

using namespace std;

void word_With_Max_Count(string s)
{
    unordered_map<string, int> freq;

    stringstream ss(s);

    string word;

    while (ss >> word)
        freq[word]++;

    int maxCount = 0;

    for (auto x : freq)
    {
        if (x.second > maxCount)
            maxCount = x.second;
    }

    cout << "Word / words with max count : " << endl;

    for (auto x : freq)
    {
        if (x.second == maxCount)
        {
            cout << x.first << " -> " << x.second << endl;
        }
    }
}
int main()
{
    string s = "It's not only writers who can benefit from this free online tool. If you're a programmer who's working on a project where blocks of text are needed, this tool can be a great way to get that. It's a good way to test your programming and that the tool being created is working well. Above are a few examples of how the random paragraph generator can be beneficial. The best way to see if this random paragraph picker will be useful for your intended purposes is to give it a try. Generate a number of paragraphs to see if they are beneficial to your current project.If you do find this paragraph tool useful, please do us a favor and let us know how you're using it. It's greatly beneficial for us to know the different ways this tool is being used so we can improve it with updates. This is especially true since there are times when the generators we create get used in completely unanticipated ways from when we initially created them. If you have the time, please send us a quick note on what you'd like to see changed or added to";
    word_With_Max_Count(s);
}

auto init = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();