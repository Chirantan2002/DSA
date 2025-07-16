
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *creatBST(const vector<int> &levelOrder)
{
    if (levelOrder.empty() || !levelOrder[0] == INT_MIN)
    {
        return NULL;
    }

    Node *root = new Node(levelOrder[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        Node *curr = q.front();
        q.pop();

        // Left child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->left = new Node(levelOrder[i]);
            q.push(curr->left);
        }
        i++;

        // Right  child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->right = new Node(levelOrder[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return NULL;
    if (root->data < p->data && root->data < q->data)
        return lowestCommonAncestor(root->right, p, q);
    if (root->data > p->data && root->data > q->data)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    Node *root = NULL;
    vector<int> levelOrder = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    root = creatBST(levelOrder);
    Node *p = new Node(2);
    Node *q = new Node(4);

    Node *res = lowestCommonAncestor(root, p, q);
    cout << res->data;
    cout << endl;
}