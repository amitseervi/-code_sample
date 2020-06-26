#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int candidateLeft=0;
    int candidateRight=n-1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            candidateLeft=i;
            break;
        }
    }

    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            candidateRight=i;
            break;
        }
    }

    int mn=candidateLeft;
    int mx=candidateRight;
    for(int i=candidateLeft;i<=candidateRight;i++){
        if(arr[i]<arr[mn]){
            mn=i;
        }
        if(arr[i]>arr[mx]){
            mx=i;
        }
    }

    int ansLeft=candidateLeft;
    while(ansLeft>0 && arr[ansLeft-1]>arr[mn]){
        ansLeft--;
    }
    
    int ansRight=candidateRight;
    while(ansRight<n-1 && arr[ansRight+1]<arr[mx]){
        ansRight++;
    }
    cout<<ansLeft<<" : "<<ansRight<<"\n";
    

}