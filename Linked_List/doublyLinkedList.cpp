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
    displayRec(a);
    cout << endl;
    displayRevRec(a);
    cout << endl;
    displayRecByTail(d);
    cout << endl;

    return 0;
}