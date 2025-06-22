#include <iostream>
#include <vector>
using namespace std;

class CircularQueue
{
    int f;
    int b;
    int s;
    int c;
    vector<int> arr;

public:
    CircularQueue(int k)
    {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }

    void pushElement(int val)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[b] = val;
        b = (b + 1) % c;
        s++;
    }

    void popElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        f = (f + 1) % c;
        s--;
    }

    void frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element is: " << arr[f] << endl;
    }

    void rearElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Rear element is: " << arr[(b - 1 + c) % c] << endl;
    }

    bool isEmpty()
    {
        return s == 0;
    }

    bool isFull()
    {
        return s == c;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int i = f;
        for (int count = 0; count < s; count++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % c; // Correctly traverse the circular queue
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(5);
    cq.pushElement(1);
    cq.pushElement(2);
    cq.pushElement(3);
    cq.pushElement(4);
    cq.pushElement(5);
    cq.display();
    cq.frontElement();
    cq.rearElement();
    cq.popElement();
    cq.display();
}