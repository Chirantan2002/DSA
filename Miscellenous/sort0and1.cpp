#include <bits/stdc++.h>

using namespace std;

void sortZeroesAndOne(vector<int> &v)
{
    int zeroesCount = 0;
    for (int ele : v)
    {
        if (ele == 0){
            
        }
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (i < zeroesCount)
    //     {
    //         v[i] = 0;
    //     }
    //     else
    //     {
    //         v[i] = 1;
    //     }
    // }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    sortZeroesAndOne(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}