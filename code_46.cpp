#include<iostream>
#include<stack>
using namespace std;

void insertInSortedStack(stack<int> &s,int x){
    if(s.empty() || s.top()<x){
        cout<<"PUSH "<<x<<"\n";
        s.push(x);
        return;
    }
    int current=s.top();
    s.pop();
    cout<<"POP "<<current<<"\n";
    insertInSortedStack(s,x);
    cout<<"PUSH "<<current<<"\n";
    s.push(current);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int current=s.top();
    s.pop();
    cout<<"POP "<<current<<"\n";
    sortStack(s);
    insertInSortedStack(s,current);
}

void popAndPrint(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
}

int main(){
    stack<int> s;
    int arr[]={-3,14,18,-5,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    sortStack(s);
    popAndPrint(s);
}