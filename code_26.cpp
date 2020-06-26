//Maximum sum increasing subsequence | dp-14
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = arr[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << "answer " << ans << "\n";
}