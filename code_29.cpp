//Palindrome partitioning
#include <bits/stdc++.h>
using namespace std;
int firstLevelApproach(string str)
{
    int len = str.size();
    int dp[len][len];
    bool isPalindrome[len][len];
    memset(isPalindrome, false, sizeof(isPalindrome));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 0;
        isPalindrome[i][i] = true;
    }
    for (int k = 2; k <= len; k++)
    {
        for (int i = 0; i + k - 1 < len; i++)
        {
            int start = i;
            int end = i + k - 1;
            if (start + 1 == end)
            {
                isPalindrome[start][end] = str[start] == str[end];
            }
            else
            {
                isPalindrome[start][end] = (str[start] == str[end]) && (isPalindrome[start + 1][end - 1]);
            }
            dp[start][end] = INT_MAX;
            if (isPalindrome[start][end])
            {
                dp[start][end] = 0;
            }
            else
            {
                for (int j = start + 1; j <= end; j++)
                {
                    dp[start][end] = min(dp[start][end], dp[start][j - 1] + dp[j][end] + 1);
                }
            }
        }
    }
    return dp[0][len - 1];
}

int optimizedApproach(string str)
{
    int len = str.size();
    bool isPalindrome[len][len];
    memset(isPalindrome, false, sizeof(isPalindrome));
    for (int i = 0; i < len; i++)
    {
        isPalindrome[i][i] = true;
    }
    for (int i = 2; i <= len; i++)
    {
        for (int j = 0; j + i - 1 < len; j++)
        {
            int start = j;
            int end = j + i - 1;
            if (start + 1 == end)
            {
                isPalindrome[start][end] = str[start] == str[end];
            }
            else
            {
                isPalindrome[start][end] = isPalindrome[start + 1][end - 1] && str[start] == str[end];
            }
        }
    }
    int dp[len];
    dp[0] = 0;
    for (int i = 1; i < len; i++)
    {
        if (isPalindrome[0][i])
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++)
            {
                if (isPalindrome[j + 1][i])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[len - 1];
}
int main()
{
    //input = ababbbabbababa
    //output = 3
    string str = "ababbbabbababa";
    cout << "1st answer " << firstLevelApproach(str) << "\n";
    cout << "2nd answer " << optimizedApproach(str) << "\n";
}