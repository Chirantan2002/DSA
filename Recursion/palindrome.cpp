#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string str, int i, int j)
{
    // int i = 0;
    // int j = str.length() - 1;
    // while (i < j)
    // {
    //     if (str[i] != str[j])
    //         return false;
    //     i++;
    //     j--;
    // }
    // return true;
    if (i > j)
        return true;
    if (str[i] != str[j])
        return false;
    else
        return isPalindrome(str, i + 1, j - 1);
}

int main()
{
    string s = "racecar";

    cout << isPalindrome(s, 0, s.length() - 1);
}