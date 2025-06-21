#include <iostream>
using namespace std;

class ListNode // Linked List Implementation
{
public:
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class Queue // Queue using Linked List
{
    int size;
    ListNode *head;
    ListNode *tail;

public:
    Queue() : size(0), head(nullptr), tail(nullptr) {}

    void pushElement(int val)
    {
        ListNode *temp = new ListNode(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void popElement()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void display()
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void isEmpty()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue isn't empty!" << endl;
    }

    void frontElement()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element is: " << head->data << endl;
    }

    void backElement()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Rear element is: " << tail->data << endl;
    }

    void sizeOfQueue()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        cout << "Size of queue is: " << count << endl;
    }
};

int main()
{
    Queue q;
    q.popElement();
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