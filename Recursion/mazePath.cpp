#include <iostream>

using namespace std;

// int mazePath(int sr, int sc, int er, int ec)
// {
//     if (sc > er || sc > ec)
//         return 0;
//     if (sr == er && sc == ec) //* this condition is not working for some reason
//         return 1;
//     int rightWays = mazePath(sr, sc + 1, er, ec);
//     int downWays = mazePath(sr + 1, sc, er, ec);

//     int totalWays = rightWays + downWays;

//     return totalWays;
// }

// void printPath(int sr, int sc, int dr, int dc, string s)
// {
//     if (sc > dr || sc > dc)
//         return;
//     if (sr == dr && sc == dc) //* this condition is not working for reason
//     {
//         cout << s << endl;
//         return;
//     }
//     printPath(sr, sc + 1, dr, dc, s + 'R');
//     printPath(sr + 1, sc, dr, dc, s + 'D');
// }

void printPathWithTwoParam(int row, int col, string s) //* fine code, running smoothly
{
    if (row < 1 || col < 1)
        return;
    if (row == 1 && col == 1)
    {
        cout << s << endl;
        return;
    }
    printPathWithTwoParam(row, col - 1, s + 'R');
    printPathWithTwoParam(row - 1, col, s + 'D');
}

int maze2(int row, int col) //* completely fine code
{
    if (row < 1 || col < 1)
        return 0;
    if (row == 1 && col == 1)
        return 1;
    int rightWays = maze2(row, col - 1);
    int leftWays = maze2(row - 1, col);
    int totalWays = leftWays + rightWays;
    return totalWays;
}

int main()
{
    // int ans = mazePath(0, 0, 3, 4);
    // cout << ans;
    string s = "";
    cout << endl;
    // cout << mazePath(0, 0, 3, 4);
    cout << endl;
    // printPath(0, 0, 2, 2, s);
    cout << endl;
    cout << maze2(4, 4);
    cout << endl;
    printPathWithTwoParam(4, 4, s);
}