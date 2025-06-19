#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string str;
    cout << endl;
    cout << "Enter the string: ";
    cin >> str;
    int n = str.length(), count = 0;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (n == 1)
        {
            break;
        }
        if (n == 2 && str[0] != str[1])
        {
            count = 1;
            break;
        }
        if (i == 0)
        {
            if (str[i] != str[i + 1])
                count++;
        }
        else if (i == n - 1)
        {
            if (str[i] != str[i - 1])
                count++;
        }
        else if (str[i] != str[i + 1] && str[i] != str[i - 1])
        {
            count++;
        }
    }

    cout << endl;
    cout << "No of different chars: " << count;
}

//* abbcdeffghh