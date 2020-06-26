// sort altered decreasing and increasing order linkedlist

#include <bits/stdc++.h>
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
//Input -> 10->40->53->30->67->12->89->NULL
//Output -> 10->12->30->43->53->67->89->NULL

void printLL(Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

Node *reverseList(Node *x, Node **root)
{
    if (x->next == NULL)
    {
        *root = x;
        x->next = NULL;
        return x;
    }
    Node *parent = reverseList(x->next, root);
    parent->next = x;
    x->next = NULL;
    return x;
}

int main()
{
    Node *root = NULL;
    int arr[] = {10, 40, 53, 30, 67, 12, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = new Node(arr[0]);
    Node *current = root;
    for (int i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    Node *x = NULL;
    Node *y = NULL;
    current = root;
    Node *xLast = NULL;
    Node *yLast = NULL;
    while (current != NULL)
    {
        if (x == NULL)
        {
            x = current;
            xLast = x;
        }
        else
        {
            xLast->next = current;
            xLast = xLast->next;
        }
        if (y == NULL)
        {
            y = current->next;
            yLast = y;
        }
        else
        {
            yLast->next = current->next;
            yLast = yLast->next;
        }

        if (current->next != NULL)
        {
            current = current->next->next;
        }
        else
        {
            current = NULL;
        }
    }
    Node *ry = NULL;
    reverseList(y, &ry);

    Node *newList = NULL;
    xLast = x;
    yLast = ry;
    Node *resultLast = NULL;
    while (xLast != NULL && yLast != NULL)
    {
        if (xLast->data < yLast->data)
        {
            if (newList == NULL)
            {
                newList = xLast;
                resultLast = newList;
            }
            else
            {
                resultLast->next = xLast;
                resultLast = resultLast->next;
            }
            xLast = xLast->next;
        }
        else
        {
            if (newList == NULL)
            {
                newList = yLast;
                resultLast = newList;
            }
            else
            {
                resultLast->next = yLast;
                resultLast = resultLast->next;
            }
            yLast = yLast->next;
        }
    }
    while (yLast != NULL)
    {
        if (newList == NULL)
        {
            newList = yLast;
            resultLast = newList;
        }
        else
        {
            resultLast->next = yLast;
            resultLast = resultLast->next;
        }
        yLast = yLast->next;
    }

    while (xLast != NULL)
    {
        if (newList == NULL)
        {
            newList = xLast;
            resultLast = newList;
        }
        else
        {
            resultLast->next = xLast;
            resultLast = resultLast->next;
        }
        xLast = xLast->next;
    }
    printLL(newList);
}