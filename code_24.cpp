//Longest common substring | dp - 29
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x = "zxabcdezy";
    string y = "yzabcdezx";

    int n = x.size();
    int m = y.size();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}