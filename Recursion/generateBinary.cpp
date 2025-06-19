#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n = 4;

void generate(string str)
{
    if (str.length() == n)
    {
        cout << str << endl;
        return;
    }

    generate(str + '0');

    if (str.empty() || str.back() != '1')
    {
        generate(str + '1');
    }
}

int main()
{
    generate("");
}