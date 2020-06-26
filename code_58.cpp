#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < arr[i])
        {
            cout << s.top() << " - " << arr[i] << "\n";
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << " - " << -1 << "\n";
        s.pop();
    }
}