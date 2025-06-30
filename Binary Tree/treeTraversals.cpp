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

void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int levels(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void printNthLevel(TreeNode *root, int lvl, int req)
{
    if (!root)
        return;
    if (lvl == req)
    {
        cout << root->data << " ";
        return;
    }
    printNthLevel(root->right, lvl + 1, req);
    printNthLevel(root->left, lvl + 1, req);
}

void levelOrderTraversal(TreeNode *root)
{
    int n = levels(root);
    for (int i = 0; i < n; i++)
    {
        printNthLevel(root, 0, i);
        cout << endl;
    }
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
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    levelOrderTraversal(root);
}