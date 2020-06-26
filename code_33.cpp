#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str = "abbccc";
    int n = str.size();
    int k = 2;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - 'a']++;
    }

    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
    {
        pq.push(cnt[i]);
    }

    while (k--)
    {
        int fq = pq.top();
        fq--;
        pq.pop();
        pq.push(fq);
    }
    int ans = 0;
    while (pq.size())
    {
        int x = pq.top();
        ans += x * x;
        pq.pop();
    }
    cout << "Answer " << ans << "\n";
}