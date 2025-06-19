#include <bits/stdc++.h>

using namespace std;

int findFirstOccurence(const vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1;
    int left = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        else if (arr[mid] == target)
        {
            left = mid;
            end = mid - 1;
        }
    }

    return left;
}

int findLastOccurence(const vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1;
    int right = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        else if (arr[mid] == target)
        {
            right = mid;
            start = mid + 1;
        }
    }

    return right;
}

int main()
{
    vector<int> arr = {1, 1, 1, 5, 5, 5};
    int firstIndex, lastIndex;
    int target = 5;

    firstIndex = findFirstOccurence(arr, target);
    lastIndex = findLastOccurence(arr, target);

    cout << "Fisrt Occurence of the Target is: " << firstIndex << "\n";
    cout << "Last Occurence of the Target is: " << lastIndex;

    return 0;
}