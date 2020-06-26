#include<stack>
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[]={11, 13, 21, 3};
    stack<int> s;
    int n=sizeof(arr)/sizeof(arr[0]);
    int nxt[n];
    for(int i=n-1;i>=0;i--){
        int current=arr[i];
        while(!s.empty()&&current>s.top()){
            s.pop();
        }
        if(s.empty()){
            nxt[i]=-1;
        }else{
            nxt[i]=s.top();
        }
        s.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<nxt[i]<<" ";
    }
    cout<<"\n";
}