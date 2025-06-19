#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &num1, int m, vector<int> &num2, int n)
{
    int count1 = 0, count2 = 0;
    vector<int> v;

    for (int i = 0; i < num1.size(); i++)
    {
        v.push_back(num1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(num2[i]);
    }
    sort(v.begin(), v.end());
    num1.clear;
    num1 = v;
}

int main()
{
}