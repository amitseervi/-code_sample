#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int w=100;
    int val[]={10, 30, 20};
    int wt[]={5, 10, 15};
    int n=sizeof(val)/sizeof(val[0]);

    int dp[w+1];
    memset(dp,0,sizeof(dp));
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(tmp+wt[i]<=w && dp[tmp+wt[i]]<dp[tmp]+val[i]){
                dp[tmp+wt[i]]=dp[tmp]+val[i];
                q.push(tmp+wt[i]);
            }
        }
    }
    cout<<dp[w]<<"\n";
}