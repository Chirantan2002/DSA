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
    bool isPalindrome(ListNode *head)
    {
        // If the first half & second half is reverse of each other then it is a
        // Palindrome
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now at the left middle / middle
        ListNode *newHead = reverseList(slow->next);
        ListNode *a = head;
        ListNode *b = newHead;
        while (b)
        {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
}

int main()
{
    Solution s;
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(2);
    ListNode *f = new ListNode(1);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    bool flag = s.isPalindrome(a);
    cout << flag << endl;
    bool temp = s.isPalindrome(node1);
    cout << temp << endl;
}