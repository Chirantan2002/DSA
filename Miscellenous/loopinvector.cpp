#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    // for loop to take the input
    for (int i = 0; i < 5; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    // for loop to print elements
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // for each loop
    for (int ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;

    // v.insert(v.begin()+2,6);

    v.erase(v.end() - 2);
    v.erase(v.end() - 3);

    // while loop
    int idx = 0;
    while (idx < v.size())
    {
        cout << v[idx] << " ";
        idx++;
    }
    cout << endl;

    return 0;
}