#include <iostream>
using namespace std;
// Definition for singly-linked list.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int n = 0;
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        ListNode *tail = nullptr;
        while (temp)
        {
            if (temp->next == nullptr)
                tail = temp;
            temp = temp->next;
            n++;
        }
        k = k % n;
        if (k == 0)
            return head;
        temp = head;
        for (int i = 1; i < n - k; i++)
        {
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode *ans = s.rotateRight(c, 4);
    while (ans)
    {
        cout << ans->val;
        if (ans->next)
            cout << " -> ";
        ans = ans->next;
    }

    return 0;
}