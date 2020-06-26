#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct MyPair
{
    int value, cnt;
};

bool compPair(const MyPair a, const MyPair b)
{
    return a.value > b.value;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt[n];
    int cnt2[n];

    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                cnt[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        cnt[s.top()] = n - s.top();
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                cnt2[s.top()] = s.top() - i;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        cnt2[s.top()] = s.top() + 1;
        s.pop();
    }
    MyPair ansArr[n];
    for (int i = 0; i < n; i++)
    {
        ansArr[i].value = arr[i];
        ansArr[i].cnt = cnt[i] + cnt2[i] - 1;
    }
    sort(ansArr, ansArr + n, compPair);
    int index = 0;
    int current = 0;
    while (current < n)
    {
        if (ansArr[current].cnt - index > 0)
        {
            cout << ansArr[current].value << " ";
            index++;
        }
        else
        {
            current++;
        }
    }
    cout << "\n";
    return 0;
}
