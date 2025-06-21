#include <iostream>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque
{
    DLLNode *head;
    DLLNode *tail;
    int size;

public:
    Deque()
    {
        size = 0;
        head = tail = nullptr;
    }

    void pushAtBack(int val)
    {
        if (size == 0)
        {
            DLLNode *temp = new DLLNode(val);
            head = tail = temp;
        }
        else
        {
            DLLNode *temp = new DLLNode(val);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pushAtFront(int val)
    {
        if (size == 0)
        {
            DLLNode *temp = new DLLNode(val);
            head = tail = temp;
        }
        else
        {
            DLLNode *temp = new DLLNode(val);
            temp->next = head;
            temp->prev = nullptr;
            head = temp;
        }
        size++;
    }

    void popAtBack()
    {
        if (size == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        DLLNode *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
    }

    void popAtFront()
    {
        if (size == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        DLLNode *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        size--;
    }

    void frontElement()
    {
        if (size == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Front element is: " << head->data << endl;
    }

    void backElement()
    {
        if (size == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Back element is: " << tail->data << endl;
    }

    void isEmpty()
    {
        if (size == 0)
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque isn't empty!" << endl;
    }

    void sizeOfDeque()
    {
        cout << "Size of Deque is: " << size << endl;
    }

    void display()
    {
        DLLNode *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque dq;
    dq.popAtBack();
    dq.pushAtBack(1);
    dq.pushAtBack(2);
    dq.pushAtBack(3);
    dq.pushAtBack(4);
    dq.pushAtBack(5);
    dq.display();
    dq.sizeOfDeque();
    dq.frontElement();
    dq.backElement();
    dq.popAtBack();
    dq.popAtFront();
    dq.pushAtFront(20);
    dq.isEmpty();
    dq.sizeOfDeque();
    dq.display();
}