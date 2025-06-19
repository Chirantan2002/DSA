#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void leftMiddleNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Left Middle is: " << slow->val << endl;
}

void display(Node *head)
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

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(90);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    display(a);
    leftMiddleNode(a);
    display(a);
}