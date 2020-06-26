#include <bits/stdc++.h>
using namespace std;

#define BIT_LENGTH 32
typedef long long int ll;
int matrix[1001][1001];
bool canReach[1001][1001];
string arr[1001];
int n, m;
bool dfs(int r, int c)
{
    if (arr[r][c] != '.')
    {
        return false;
    }
    if (r == n - 1 && c == m - 1)
    {
        return canReach[r][c] = true;
    }
    bool reached = false;
    if (c + 1 < m)
    {
        reached = reached || dfs(r, c + 1);
    }
    if (r + 1 < n)
    {
        reached = reached || dfs(r + 1, c);
    }
    return canReach[r][c] = reached;
}
void calculateMatrix(int r, int c)
{
    
}
int main()
{
    cin >> n >> m;
    memset(matrix, 0, sizeof(matrix));
    memset(canReach, false, sizeof(canReach));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}