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

void listSize(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    cout << endl
         << "Size of the linked_list is: " << size;
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
}

void displayRecursively(Node *head)
{
    if (head == NULL)
        return;
    displayRecursively(head->next);
    cout << head->val << " ";
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    display(a);
    // displayRecursively(a);
    // listSize(a);
}