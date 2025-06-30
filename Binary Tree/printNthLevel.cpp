#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printNthLevel(TreeNode *root, int lvl, int req)
{
    if (!root)
        return;
    if (lvl == req)
        cout << root->data << " ";
    printNthLevel(root->left, lvl + 1, req);
    printNthLevel(root->right, lvl + 1, req);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    printNthLevel(root, 0, 2);
}