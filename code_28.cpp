//LONGEST PALINDROME SUB SEQUENCE
#include <bits/stdc++.h>
using namespace std;
/*
answer(i,j) = if(str[i]==str[j]) 1+answer(i+1,j-1) else max(answer(i+1,j),answer(i,j-1));
*/
int answer(string str, int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }
    if (str[i] == str[j])
    {
        return 2 + answer(str, i + 1, j - 1);
    }
    else
    {
        return max(answer(str, i + 1, j), answer(str, i, j - 1));
    }
}

int answerDp(string str, int len)
{
    int dp[len][len];
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 2; i <= len; i++)
    {
        for (int j = 0; j + i - 1 < len; j++)
        {
            int start = j;
            int end = j + i - 1;
            if (start + 1 == end)
            {
                dp[start][end] = (str[start] == str[end]) ? 2 : 1;
            }
            else
            {
                if (str[start] == str[end])
                {
                    dp[start][end] = dp[start + 1][end - 1] + 2;
                }
                else
                {
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }
    }
    return dp[0][len - 1];
}
int main()
{
    string str = "GEEKSFORGEEKS";
    int len = str.size();
    //cout << "LONGEST PALINDROMIC SUBSEQUENCE LENGTH : " << answer(str, 0, len - 1) << "\n";
    cout << "LONGEST PALINDROMIC SUBSEQUENCE LENGTH : " << answerDp(str, len) << "\n";
}