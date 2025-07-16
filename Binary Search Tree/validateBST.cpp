
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

void inorder(Node *root, Node *prev, bool &flag)
{
    if (!root)
        return;
    inorder(root->left, prev, flag);
    if (prev)
    {
        if (root->data <= prev->data)
        {
            flag = false;
            return;
        }
    }
    prev = root;
    inorder(root->right, prev, flag);
}

bool isValidBST(Node *root)
{
    Node *prev = NULL;
    bool flag = true;
    inorder(root, prev, flag);
    return flag;
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
    cout << isValidBST(root);
    cout << endl;
}