// Morris Traversal = Inorder traversal without recursion and without stack
// O(1) Space complexity and O(n) time complexity

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode *creatBST(const vector<int> &levelOrder)
{
    if (levelOrder.empty() || !levelOrder[0] == INT_MIN)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(levelOrder[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->left = new TreeNode(levelOrder[i]);
            q.push(curr->left);
        }
        i++;

        // Right  child
        if (i < levelOrder.size() && levelOrder[i] != INT_MIN)
        {
            curr->right = new TreeNode(levelOrder[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

void morrisInorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " "; // Visit Current Node
            curr = curr->right;
        }
        else
        {
            TreeNode *pre = NULL;
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data << " "; // Visit Current Node
                curr = curr->right;
            }
        }
    }
}

int main()
{
    TreeNode *root = NULL;
    vector<int> levelOrder = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    root = creatBST(levelOrder);
    printLevelOrder(root);
    cout << endl;
    morrisInorderTraversal(root);
    cout << endl;
}