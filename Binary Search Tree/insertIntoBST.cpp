
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

Node *insertintoBST(Node *root, int val)
{
    if(!root) return new Node(val);
    if(root->data > val){
        if(!root->left) root->left = new Node(val);
        else insertintoBST(root->left, val);
    }
    else{
        if(!root->right) root->right = new Node(val);
        else insertintoBST(root->right, val);
    }
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
    vector<int> levelOrder = {4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, 8};
    root = creatBST(levelOrder);

    Node *res = insertintoBST(root, 10);
    printLevelOrder(res);

    cout << endl;
}