#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int d) : data(d)
    {
        next = NULL;
    }
};
Node *linkedListFromArr(int arr[], int n)
{
    Node *root = new Node(arr[0]);
    Node *cur = root;
    for (int i = 1; i < n; i++)
    {
        cur->next = new Node(arr[i]);
        cur = cur->next;
    }
    return root;
}

Node *mergeLinkedList(Node *l1, Node *l2)
{
    Node *c1 = l1;
    Node *c2 = l2;
    Node *result = NULL;
    Node *resultCursor = NULL;
    while (c1 != NULL && c2 != NULL)
    {
        Node *selected = NULL;
        if (c1->data < c2->data)
        {
            selected = c1;
            c1 = c1->next;
        }
        else
        {
            selected = c2;
            c2 = c2->next;
        }
        if (result == NULL)
        {
            result = selected;
            resultCursor = result;
        }
        else
        {
            resultCursor->next = selected;
            resultCursor = resultCursor->next;
        }
    }
    resultCursor->next = NULL;
    return result;
}

void printLL(Node *root)
{
    Node *cur = root;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

int main()
{
    int L1[] = {5, 10, 15};
    int L2[] = {2, 3, 20};
    Node *l1Root = linkedListFromArr(L1, sizeof(L1) / sizeof(L1[0]));
    Node *l2Root = linkedListFromArr(L2, sizeof(L2) / sizeof(L2[0]));
    Node *ans = mergeLinkedList(l1Root, l2Root);
    printLL(ans);
}