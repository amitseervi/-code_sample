#include <iostream>
#include <stack>
#include <vector>
#define N 6
using namespace std;

struct Node
{
    int data;
    int cnt;
    Node(int d, int c) : data(d), cnt(c)
    {
    }
};

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left_greater[n];
    int right_greater[n];
    left_greater[0] = 1;
    right_greater[n - 1] = 1;
    stack<Node> s;
    for (int i = 0; i < n; i++)
    {
        Node n(arr[i], 1);
        while (!s.empty() && s.top().data > arr[i])
        {
            n.cnt += s.top().cnt;
            s.pop();
        }
        left_greater[i] = n.cnt;
        s.push(n);
    }
    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Node n(arr[i], 1);
        while (!s.empty() && s.top().data > arr[i])
        {
            n.cnt += s.top().cnt;
            s.pop();
        }
        right_greater[i] = n.cnt;
        s.push(n);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "left greater " << left_greater[i] << " right greater " << right_greater[i] << "\n";
        ans += (left_greater[i] * right_greater[i] * arr[i]);
    }
    cout << "answer " << ans << "\n";
}