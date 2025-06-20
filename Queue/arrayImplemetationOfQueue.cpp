#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int size_of_queue;
    int front_index;
    int rear_index;

public:
    Queue(int sz)
    {
        this->size_of_queue = sz;
        arr = new int[sz];
        front_index = 0;
        rear_index = 0;
    }

    void pushElement(int val)
    {
        if (rear_index == size_of_queue)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else
        {
            arr[rear_index] = val;
            rear_index++;
        }
    }

    void popElement()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        else
            front_index++;
    }

    void display()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front_index; i < rear_index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void isEmpty()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        else
            cout << "Queue isn't empty!" << endl;
    }

    void frontElement()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element is: " << arr[front_index] << endl;
    }

    void backElement()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Rear element is: " << arr[rear_index - 1] << endl;
    }

    void sizeOfQueue()
    {
        if (front_index == rear_index)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Size of queue is: " << rear_index - front_index << endl;
    }
};

int main()
{
    Queue q(5);
    q.pushElement(1);
    q.pushElement(2);
    q.pushElement(3);
    q.pushElement(4);
    q.pushElement(5);
    q.display();
    q.frontElement();
    q.backElement();
    q.isEmpty();
    q.sizeOfQueue();
    q.popElement();
    q.display();
}