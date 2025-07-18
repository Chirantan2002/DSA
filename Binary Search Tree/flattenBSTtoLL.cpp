#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBST(const vector<int> &levelOrder)
{
    if (levelOrder.empty() || !levelOrder[0] == INT_MIN)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(levelOrder[0]);
    queue<TreeNode *> q;
    q.push(root);

    int index = 1;
    while (!q.empty() && index < levelOrder.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (index < levelOrder.size() && levelOrder[index] != INT_MIN)
        {
            curr->left = new TreeNode(levelOrder[index]);
            q.push(curr->left);
        }
        index++;

        // Right  child
        if (index < levelOrder.size() && levelOrder[index] != INT_MIN)
        {
            curr->right = new TreeNode(levelOrder[index]);
            q.push(curr->right);
        }
        index++;
    }
    return root;
}

void preorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (!root)
        return NULL;
    TreeNode *temp1 = helper(root->left);
    TreeNode *temp2 = helper(root->right);
    root->right = temp1;
    temp1 = root;
    while (temp1->right)
    {
        temp1 = temp1->right;
    }
    temp1->right = temp2;
    root->left = NULL;
    return root;
}

void flattenWithRecursion(TreeNode *root)
{
    if (!root)
        return;
    helper(root);
}

void display(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

void flattenWithConstantSpace(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            // Save the right
            TreeNode *r = curr->right;
            curr->right = curr->left;
            // Find Predecessor
            TreeNode *pred = curr->left;
            while (pred->right)
                pred = pred->right;
            // Link
            pred->right = r;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    TreeNode *temp = root;
    // Point the lefts NULL
    while (temp->right)
    {
        temp->left = NULL;
        temp = temp->right;
    }
}

int main()
{
    TreeNode *root = NULL;
    vector<int> levelOrder = {1, 2, 5, 3, 4, INT_MIN, 6};
    root = createBST(levelOrder);

    preorder(root);
    cout << endl;
    flattenWithRecursion(root);
    display(root);
    cout << endl;
    flattenWithConstantSpace(root);
    display(root);
    return 0;
}