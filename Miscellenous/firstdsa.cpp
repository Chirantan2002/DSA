#include <iostream>

using namespace std;

int main()
{
    int r = 0, remainder, n;
    int temp;

    cout << "Enter the value of n = ";
    cin >> n;

    temp = n;

    while (n != 0)
    {
        remainder = n % 10;
        r = (r * 10) + remainder;
        n /= 10;
    }
    printf("Reverse = %d", r);

    if (temp == r)
        printf("\nIt's palindrome");
    else if (temp != r)
        printf("\nIt's not a palindrome");

    return 0;
}