#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d)
    {
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node *root)
{
    return root->left == NULL && root->right == NULL;
}

bool isSumTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isLeaf(root))
    {
        return true;
    }

    int expectedSum = 0;
    if (root->left != NULL)
    {
        if (isLeaf(root->left))
        {
            expectedSum += (root->left->data);
        }
        else
        {
            expectedSum += 2 * (root->left->data);
        }
    }
    if (root->right != NULL)
    {
        if (isLeaf(root->right))
        {
            expectedSum += (root->right->data);
        }
        else
        {
            expectedSum += 2 * (root->right->data);
        }
    }
    return expectedSum == root->data && isSumTree(root->left) && isSumTree(root->right);
}

int main()
{
    Node *root = new Node(26);
    root->left = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(3);
    cout << (isSumTree(root) ? "Tree is sum tree"
                             : "Tree is not sum tree")
         << "\n";
}