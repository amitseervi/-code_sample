#include <iostream>
#include <queue>
using namespace std;

#define N 3

int getMin(int arr[]){
    int ans=0;
    for(int i=1;i<N;i++){
        if(arr[i]<arr[ans]){
            ans=i;
        }
    }
    return ans;
}

int getMax(int arr[]){
    int ans=0;
    for(int i=1;i<N;i++){
        if(arr[i]>arr[ans]){
            ans=i;
        }
    }
    return ans;
}

void minCashFlow(int arr[]){
    int mxCredit=getMax(arr);
    int mxDebit=getMin(arr);
    if(arr[mxCredit]==0 && arr[mxDebit]==0){
        return;
    }
    int mn=min(arr[mxCredit],-arr[mxDebit]);
    cout << "Person "<<mxDebit<<" pay "<<mn << " to person "<<mxCredit<<"\n";
    arr[mxCredit]-=mn;
    arr[mxDebit]+=mn;
    minCashFlow(arr);
}

int main()
{
    
}