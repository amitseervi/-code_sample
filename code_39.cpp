#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n=105;
    queue<int> q;
    if(n>0){
        cout<<"0 ";
    }
    for(int i=1;i<n && i<10;i++){
        cout<<i<<" ";
        q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        if(x%10==0){
            int num = (x*10)+1;
            if(num<n){
                q.push(num);
            }
        }else if(x%10==9){
            int num = (x*10)+8;
            if(num<n){
                q.push(num);
            }
        }else{
            int num1 = (x*10)+((x%10)-1);
            if(num1<n){
                q.push(num1);
            }

            int num2 = (x*10)+((x%10)+1);
            if(num2<n){
                q.push(num2);
            }
        }
    }
    cout<<"\n";

}