#include <iostream>   // cout
#include <vector>     // vector
#include <queue>      // priority_queue
#include <functional> // greater / less
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {40, 10, 20, 50, 30};
    make_heap(arr.begin(), arr.end()); // Max heap using STL function make_heap
    cout << arr[0] << endl;

    vector<int> brr = {40, 10, 20, 50, 30};
    make_heap(brr.begin(), brr.end(), greater<int>()); // Min heap using STL function make_heap
    cout << brr[0] << endl;

    arr.push_back(60);
    push_heap(arr.begin(), arr.end()); // Add new element using STL function push_heap
    pop_heap(arr.begin(), arr.end());  // Remove top element using STL function pop_heap
    arr.pop_back();
    sort_heap(arr.begin(), arr.end()); // Sort the elements using STL function sort_heap

    // Print is_heap result
    cout << "is_heap: " << boolalpha << is_heap(arr.begin(), arr.end()) << endl;

    // Print is_heap_until result (index and value)
    auto it = is_heap_until(arr.begin(), arr.end());
    cout << "is_heap_until index: " << distance(arr.begin(), it);
    if (it != arr.end())
        cout << ", value: " << *it << endl;
    else
        cout << " (entire range is a heap)" << endl;

    for (int a : arr)
        cout << a << " ";
    return 0;
}

// push_heap(): After adding a new element at the end, restores the heap property.

// pop_heap(): Moves the largest element to the end of the range, restoring the heap property so the remaining elements are still a heap. You usually use pop_back() to actually remove the element.

// sort_heap(): Sorts the elements in ascending order using HeapSort, works only on a heap.

// is_heap(): Checks if the range satisfies the heap property.

// is_heap_until(): Returns the iterator to the first element where the heap property is violated.