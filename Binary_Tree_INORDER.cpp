// Binary Tree INORDER Traversal
#include <iostream>
using namespace std;

struct node
{
    int data;

    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);

    cout << root->data << " ";

    Inorder(root->right);
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    Inorder(root);

    return 0;
}