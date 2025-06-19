#include <iostream>
#include <vector>

using namespace std;

// Function to generate all permutations of a given array
void permutation(std::vector<int> &arr, int start, int end)
{
    // Base case: if start is equal to end, print the current permutation
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        // Recursive case: iterate from start to end and swap elements
        for (int i = start; i <= end; i++)
        {
            // Swap elements at start and i indices
            swap(arr[start], arr[i]);
            // Recursively call permutation function with start + 1 as new starting index
            permutation(arr, start + 1, end);
            // Backtrack: swap elements back to their original positions
            swap(arr[start], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    permutation(arr, 0, 2);
}