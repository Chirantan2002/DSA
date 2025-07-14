#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (root->data > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node *helper(Node *root, int val)
{
    if (!root)
        return new Node(val);

    // left subtree
    if (root->data > val)
    {
        if (!root->left)
            root->left = new Node(val);
        else
            helper(root->left, val);
    }
    // right subtree
    else
    {
        if (!root->right)
            root->right = new Node(val);
        else
            helper(root->right, val);
    }

    return root;
}

Node *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    Node *root = new Node(preorder[0]);
    for (int i = 1; i < n; ++i)
    {
        root = helper(root, preorder[i]);
    }
    return root;
}

int levels(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void printNthLevel(Node *root, int lvl, int req)
{
    if (!root)
        return;
    if (lvl == req)
    {
        cout << root->data << " ";
        return;
    }
    printNthLevel(root->left, lvl + 1, req);
    printNthLevel(root->right, lvl + 1, req);
}

void levelOrderTraversal(Node *root)
{
    int n = levels(root);
    for (int i = 0; i < n; i++)
    {
        cout << "level - " << i + 1 << ":" << " ";
        printNthLevel(root, 0, i);
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node *res = bstFromPreorder(preorder);
    levelOrderTraversal(res);

    cout << endl;
}