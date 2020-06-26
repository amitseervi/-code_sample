// Assembly Line scheduling | dp - 34
#include <bits/stdc++.h>
using namespace std;

#define NUM_STATION 4
#define NUM_LINE 2
#define INF 10000

int main()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e[] = {10, 12};
    int x[] = {18, 7};
    int dp[NUM_LINE];
    memset(dp, 0, sizeof(dp)); // 0 -> came from first line to first line,1 -> came from second line to first line , 2-> came from second to second,3->came from first to second line
    dp[0] = a[0][0] + e[0];
    dp[1] = a[1][0] + e[1];
    for (int i = 1; i < NUM_STATION; i++)
    {
        int tempFirstLine = min(dp[0], dp[1] + t[1][i]) + a[0][i];
        int tempSecondLine = min(dp[1], dp[0] + t[0][i]) + a[1][i];
        dp[0] = tempFirstLine;
        dp[1] = tempSecondLine;
    }
    cout << min(dp[0] + x[0], dp[1] + x[1]) << "\n";
}