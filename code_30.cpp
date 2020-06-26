#include <bits/stdc++.h>
using namespace std;
/*
ans(int n,int total_half) = if(total_half==0) true else if(total_half<0) false else ans(n-1,total_half) || ans(n-1,total_half-arr[n]);
*/
int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int total_sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    if (total_sum % 2)
    {
        cout << "Not possible\n";
    }
    else
    {
        int total_half = total_sum / 2;
        bool dp[total_half + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < n && !dp[total_half]; i++)
        {
            for (int j = total_half - 1; j >= 0 && !dp[total_half]; j--)
            {
                if (j + arr[i] <= total_half && dp[j])
                {
                    cout << j << " + " << arr[i] << "\n";
                    dp[j + arr[i]] = true;
                }
            }
        }
        cout << (dp[total_half] ? "Possible" : "Impossible") << "\n";
    }
}