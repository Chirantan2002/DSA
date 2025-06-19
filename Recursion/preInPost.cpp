//* Concept of Pre-In-Post in recursion (VVVIMP)....

#include <iostream>

using namespace std;

// void preInPost(int n)
// {
//     if (n == 0)
//         return;
//     cout << "Pre " << n << endl;
//     preInPost(n - 1);
//     cout << "In " << n << endl;
//     preInPost(n - 1);
//     cout << "Post " << n << endl;
// }

void printZigZag(int n)
{
    if (n == 0)
        return;
    cout << n;
    printZigZag(n - 1);
    cout << n;
    printZigZag(n - 1);
    cout << n;
}
//* input: 1 -> Output: 111
//* input: 2 -> Output: 211121112
//* input: 3 -> Output: 321112111232111211123

int main()
{
    cout << endl;
    printZigZag(3);
}