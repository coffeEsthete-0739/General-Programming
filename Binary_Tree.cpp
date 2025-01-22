// BINARY TREE
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

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);

    cout << "Root Node: " << root->data << endl;
    cout << "Left Node: " << root->left->data << endl;
    cout << "Right Node: " << root->right->data << endl;
    cout << "Left Node of Left Node: " << root->left->left->data << endl;
    cout << "Right Node of Left Node: " << root->left->right->data << endl;
    cout << "Left Node of Right Node: " << root->right->left->data << endl;

    return 0;
}