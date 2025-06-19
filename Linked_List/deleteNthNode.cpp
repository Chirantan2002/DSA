#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) //* Tc -> O(n)
{
    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == NULL)
    {
        // If n is equal to the length of the linked list, return the second node
        return head->next;
    }

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}

void printList(ListNode *head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    ListNode *temp = head;
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
    ListNode *a = new ListNode(10);
    ListNode *b = new ListNode(20);
    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(40);
    ListNode *e = new ListNode(50);
    ListNode *f = new ListNode(60);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    cout << "LL before deleting:" << endl;
    printList(a);
    removeNthFromEnd(a, 2);
    cout << endl
         << "LL after deleting:" << endl;
    printList(a);
}