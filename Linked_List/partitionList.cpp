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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        ListNode *low = new ListNode(100);
        ListNode *high = new ListNode(100);
        ListNode *tl = low;
        ListNode *th = high;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val < x)
            {
                tl->next = temp;
                temp = temp->next;
                tl = tl->next;
            }
            else if (temp->val >= x)
            {
                th->next = temp;
                temp = temp->next;
                th = th->next;
            }
        }
        tl->next = high->next;
        return low->next;
    }
};

int main()
{
    Solution s;
    ListNode *a = new ListNode(10);
    ListNode *b = new ListNode(80);
    ListNode *c = new ListNode(40);
    ListNode *d = new ListNode(30);
    ListNode *e = new ListNode(60);
    ListNode *f = new ListNode(70);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    ListNode *res = s.partition(a, 41);

    while (res)
    {
        cout << res->val;
        if (res->next)
            cout << " -> ";
        res = res->next;
    }
    return 0;
}