#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string s;
    // int count = 0;
    // cout << "Enter the string: ";
    // getline(cin, s);

    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
    //     {
    //         count++;
    //     }
    // }

    int n;
    cout<<"Enter the size: ";
    cin>>n;
    char str[n];
    int count = 0;
    cout<<endl;
    cout<<"Enter the char arr elements: ";
    for(int i = 0;i < n;i++){
        cin>>str[i];
    }

    for(int i = 0;i < n;i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            count++;
        }
    }
    cout<<endl;

    cout << "Number of vowels: " << count;
}