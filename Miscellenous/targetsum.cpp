#include <iostream>
#include <stdlib.h>

using namespace std;

int largestElementIndex(int array[], int size)
{
    int max = array[0];
    int secondmax = array[0];
    int maxIndex = -1;
    int secondmaxIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            secondmax = array[i];
            secondmaxIndex = i;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] > secondmax && array[i]!=max)
        {
            max = array[i];
            maxIndex = i;
        }
    }
    return maxIndex && secondmaxIndex;
}

int main()
{

    int array[] = {2, 3, 5, 7, 6, 1, 7};
    int n = 7;
    int indexOflargest = largestElementIndex(array, 7);
    cout << array[indexOflargest] << endl;
    // array[indexOflargest] = -1;
    int largestelement = array[indexOflargest];
    for (int i = 0; i < n; i++)
    {
        if (array[i] == largestelement)
        {
            array[i] = -1;
        }
    }
    int indexOfsecondlargest = largestElementIndex(array, 7);
    cout << array[indexOfsecondlargest] << endl;

    return 0;
}