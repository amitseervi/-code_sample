#include <iostream>
#include <stack>
#include <queue>
#include <vector>

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
    if (root == NULL || root->left == NULL || root->left->right == NULL)
    {
        return false;
    }
    return root->left->right == root;
}

int findHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (isLeaf(root))
    {
        return 1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3); //LEAF

    root->left->left = new Node(4);
    root->left->right = new Node(5); //LEAF

    root->left->left->left = new Node(6); //LEAF

    Node *l1 = root->right;
    Node *l2 = root->left->right;
    Node *l3 = root->left->left->left;

    l1->left = l3;
    l1->right = l2;

    l2->left = l1;
    l2->right = l3;

    l3->left = l2;
    l3->right = l1;

    cout << "Tree height " << findHeight(root) << "\n";
}