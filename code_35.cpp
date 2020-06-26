#include <iostream>
#include <queue>
using namespace std;
#define C 5
#define D 4
#define INF 10000
struct Node
{
    int x, y, time;
    Node(int x, int y, int time) : x(x), y(y), time(time)
    {
    }
};

bool isValid(int i,int j,int n,int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};

    int row = sizeof(arr) / sizeof(arr[0]);

    int dp[row][C];
    memset(dp, 0, sizeof(dp));
    queue<Node> pq;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 2)
            {
                dp[i][j] = 0;
                pq.push(Node(i, j, 0));
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }

    while (pq.size() > 0)
    {
        Node n = pq.front();
        pq.pop();
        for(int i=0;i<D;i++){
            int x=n.x+dir[i][0];
            int y=n.y+dir[i][1];
            /*
                1. check whether next point is valid
                2. calculated time is greater than new caluclated time
                3. and cell contain non-rotten orange
            */
            if(isValid(x,y,row,C) && dp[x][y]>n.time+1 && arr[x][y]==1){
                dp[x][y]=n.time+1;
                pq.push(Node(x,y,dp[x][y]));
            }
        }
    }
    int ans=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]==1){
                ans=max(ans,dp[i][j]);
            }
        }
    }
    if(ans==INF){
        cout<<"All orange can not be rotten\n";
    }else{
        cout<<"Answer "<<ans<<"\n";    
    }
    return 0;
}