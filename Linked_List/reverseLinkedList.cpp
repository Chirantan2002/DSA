#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *Next = nullptr;

        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode *reverseListRecursively(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *newHead = reverseListRecursively(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    ListNode *a = new ListNode(10);
    ListNode *b = new ListNode(20);
    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(40);
    a->next = b;
    b->next = c;
    c->next = d;

    cout << "List before reversing:" << endl;
    ListNode *temp = a; // keep track of the head of the original list
    printList(a);

    ListNode *res = s.reverseListRecursively(temp); // pass the head of the original list to reverseList

    cout << "List after reversing:" << endl;
    printList(res);
    return 0;
}