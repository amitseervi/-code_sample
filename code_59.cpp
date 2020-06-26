#include <iostream>
#include <vector>
#include <stack>
#define INF 100000
using namespace std;
struct Node
{
    int x;
    int y;
};

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}

void solveWordWrap(int w[], int n, int M)
{
    int extras[n + 1][n + 1];
    int wordInSingleLine[n + 1][n + 1];
    int cost[n + 1];
    int p[n + 1];
    int i, j;

    memset(extras, 0, sizeof(extras));

    for (int i = 1; i <= n; i++)
    {
        extras[i][i] = M - w[i - 1];
        for (int j = i + 1; j <= n; j++)
        {
            extras[i][j] = extras[i][j - 1] - w[j - 1] - 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
            {
                //CAN NOT FIT IN ONE LINE
                wordInSingleLine[i][j] = INF;
            }
            else if (j == n && extras[i][j] > 0)
            {
                wordInSingleLine[i][j] = 0;
            }
            else
            {
                wordInSingleLine[i][j] = extras[i][j] * extras[i][j];
            }
        }
    }

    cost[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        cost[j] = INF;
        for (int i = 1; i <= j; i++)
        {
            if (cost[i - 1] != INF && wordInSingleLine[i][j] != INF && (cost[i - 1] + wordInSingleLine[i][j]) < cost[j])
            {
                cost[j] = cost[i - 1] + wordInSingleLine[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p, n);
}

int main()
{
    int w[] = {3, 2, 2, 5};
    int n = sizeof(w) / sizeof(w[0]);
    int M = 6;
    solveWordWrap(w, n, M);
}