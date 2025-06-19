#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(NULL), prev(NULL) {}
    ListNode(int val) : val(val), next(NULL), prev(NULL) {}
};

class LinkedList
{
    ListNode *head;
    ListNode *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtTail(int value)
    {
        ListNode *temp = new ListNode(value);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail; // Extra line for doubly linked-list
            tail = temp;
        }
        size++;
    }

    void insertAtStart(int value)
    {
        ListNode *temp = new ListNode(value);
        if (size == 0)
            head = tail = NULL;
        else
        {
            temp->next = head;
            head->prev = temp; // Extra Line for doubly linked-list
            head = temp;
        }
    }

    void insertAtIdx(int idx, int value)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index!" << endl;
            return;
        }
        else if (idx == 0)
        {
            insertAtStart(value);
        }
        else if (idx == size - 1)
        {
            insertAtTail(value);
        }
        else
        {
            ListNode *t = new ListNode(value);
            ListNode *temp = head;
            for (int i = 0; i < idx; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;
            size++;
        }
    }

    void deleteAtStart()
    {
        if (size == 0)
        {
            cout << "Can't delete" << endl;
            return;
        }
        else if (size == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            ListNode *temp = head;
            head = temp->next;
            temp->next = nullptr;
            head->prev = nullptr; // Extra line here
            size--;
        }
        cout << endl;
    }

    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "Can't delete" << endl;
            return;
        }
        else if (size == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            ListNode *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            tail->prev = nullptr; // Extra line here
            tail = temp;
            size--;
        }
        cout << endl;
    }

    void deleteAtIdx(int idx)
    {
        if (size == 0)
        {
            cout << "The list is empty!";
            return;
        }
        else if (idx < 0 || idx > size)
        {
            cout << "Invalid Index!" << endl;
            return;
        }

        else if (idx == 0)
        {
            deleteAtStart();
        }
        else if (idx == size - 1)
        {
            deleteAtEnd();
        }
        else
        {
            ListNode *temp = head;
            for (int i = 0; temp != nullptr && i < idx - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
        }
        cout << endl;
    }

    int getAtIdx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index!" << endl;
            return -1;
        }
        else if (idx == size - 1)
        {
            return tail->val;
        }
        else if (idx == 0)
        {
            return head->val;
        }
        else
        {
            if (idx < size / 2)
            {
                ListNode *temp = head;
                for (int i = 0; i < idx; i++)
                {
                    temp = temp->next;
                }
                return temp->val;
            }
            else
            {
                ListNode *temp = tail;
                for (int i = size - 1; i > idx; i--)
                {
                    temp = temp->prev;
                }
                return temp->val;
            }
        }
    }

    void printList() // O(1) space complexity
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << temp->val;
            if (temp->next)
                cout << "->";
            temp = temp->next;
        }
    }
};

void printList(ListNode *head) // O(1) space complexity
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val;
        if (temp->next)
            cout << "->" << endl;
        temp = temp->next;
    }
}

void displayRec(ListNode *head) // O(n) space complexity
{
    if (!head)
        return;
    cout << head->val;
    if (head->next)
        cout << "->";
    displayRec(head->next);
}

void displayRevRec(ListNode *head) // O(n) space complexity
{
    if (!head)
        return;
    displayRevRec(head->next);
    cout << head->val << " ";
}

void displayRecByTail(ListNode *tail) // O(n) space complexity
{
    if (!tail)
        return;
    cout << tail->val << " ";
    displayRecByTail(tail->prev);
}

int main()
{
    ListNode *a = new ListNode(10);
    ListNode *b = new ListNode(20);
    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(40);
    a->next = b;
    a->prev = nullptr;
    b->next = c;
    b->prev = a;
    c->next = d;
    c->prev = b;
    d->next = nullptr;
    d->prev = c;
    // displayRec(a);
    // cout << endl;
    // displayRevRec(a);
    // cout << endl;
    // displayRecByTail(d);
    // cout << endl;
    // cout << endl;
    LinkedList l1;
    l1.insertAtTail(10);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.insertAtTail(60);
    l1.insertAtTail(70);
    l1.insertAtTail(80);
    l1.insertAtTail(90);
    l1.insertAtTail(100);
    l1.printList();
    // l1.deleteAtStart();
    // l1.printList();
    // l1.deleteAtEnd();
    // l1.printList();
    l1.deleteAtIdx(9);
    l1.printList();
    cout << endl << l1.getAtIdx(5) << endl;

    return 0;
}