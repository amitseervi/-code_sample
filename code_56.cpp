#include <iostream>
#include <stack>
#include <vector>
#define N 6
using namespace std;

int main()
{
    string stream = "geeksforgeeksandgeeksquizfor";
    int len=stream.size();
    deque<char> dq;
    stack<char> st;
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<len;i++){
        cout<<"Reading "<<stream[i]<<" from stream\n";
        int ix=stream[i]-'a';
        if(cnt[ix]==0){
            dq.push_back(stream[i]);
        }else if(cnt[ix]==1){
            while(!dq.empty() && dq.back()!=stream[i]){
                st.push(dq.back());
                dq.pop_back();
            }
            if(!dq.empty()){
                dq.pop_back();
            }
            while(!st.empty()){
                dq.push_back(st.top());
                st.pop();
            }
        }
        cnt[ix]++;
        if(dq.empty()){
            cout<<"None character remain unique\n";
        }else{
            cout<<"First non-repeating character so far is "<<dq.front()<<"\n";
        }
    }
}