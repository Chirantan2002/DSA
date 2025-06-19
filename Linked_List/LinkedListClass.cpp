#include <iostream>
using namespace std;

class Node //* Linked List Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList //* User defined data structure
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size;

    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void inserAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void inserAtStart(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index!" << endl;
        }
        else if (idx == 0)
        {
            inserAtStart(val);
        }
        else if (idx == size)
        {
            inserAtEnd(val);
        }
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int getAtIdx(int idx)
    {
        if (idx == size - 1)
            return tail->val;
        else if (idx == 0)
            return head->val;
        else if (idx < 0 || idx > size)
            return -1;
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
        cout << endl;
    }

    void deleteAtStart()
    {
        if (size == 0)
            cout << "Can't delete";
        else if (size == 1)
            head = tail = nullptr;
        else
        {
            head = head->next;
            size--;
        }
    }

    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "Can't delete";
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
    }

    void deleteAtIdx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index!";
            return;
        }
        else if (idx == 0)
            deleteAtStart();
        else if (idx == size - 1)
            deleteAtEnd();
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.inserAtEnd(10);
    ll.display();
    ll.inserAtEnd(20);
    ll.display();
    ll.inserAtEnd(30);
    ll.inserAtEnd(40);
    ll.display();
    ll.inserAtStart(100);
    ll.display();
    ll.insertAtIdx(2, 70);
    ll.display();
    // cout << ll.getAtIdx(20);
    // ll.deleteAtStart();
    // ll.display();
    // ll.deleteAtEnd();
    // ll.display();
    ll.deleteAtIdx(2);
    ll.display();
    ll.insertAtIdx(ll.size, 300);
    ll.display();
}