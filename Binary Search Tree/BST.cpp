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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}