#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *c = new ListNode(100);
        ListNode *temp = c;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if (!list1)
            temp->next = list2;
        else
            temp->next = list1;

        return c->next;
    }
};

int main()
{
    Solution s;

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    a->next = b;
    b->next = c;
    ListNode *x = new ListNode(1);
    ListNode *y = new ListNode(2);
    ListNode *z = new ListNode(5);
    x->next = y;
    y->next = z;
    ListNode *ans = s.mergeTwoLists(a, x);
    while (ans)
    {
        cout << ans->val;
        if (ans->next)
            cout << " -> ";
        ans = ans->next;
    }
    return 0;
}
