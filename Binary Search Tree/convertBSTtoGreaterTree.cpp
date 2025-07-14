
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

Node *helper(Node *root, int &sum)
{
    if (!root)
        return NULL;
    helper(root->right, sum);
    sum += root->data;
    root->data = sum;
    helper(root->left, sum);
    return root;
}

Node *convertBST(Node *root)
{
    int sum = 0;
    return helper(root, sum);
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

    Node *res = convertBST(root);
    levelOrderTraversal(res);

    cout << endl;
}