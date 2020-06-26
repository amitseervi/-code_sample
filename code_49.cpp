#include <iostream>
#include <stack>
using namespace std;


void optimized_solution(int arr[],int n){
    int left_max=0,right_max=0;
    int left=0,right=n-1;
    int ans=0;
    while(left<right){
        if(arr[left]<arr[right]){
            if(arr[left]>left_max){
                left_max=arr[left];
            }else{
                ans+=left_max-arr[left];  
            }
            left++;
        }else{
            if(arr[right]>right_max){
                right_max=arr[right];
            }else{
                ans+=right_max-arr[right];
            }
            right--;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int left[n],right[n];
    left[0]=0;
    int mx=0;
    for(int i=1;i<n;i++){
        if(mx<arr[i]){
            left[i]=0;
            mx=arr[i];
        }else{
            left[i]=mx;
        }
    }
    right[n-1]=0;
    mx=0;
    for(int i=n-1;i>=0;i--){
        if(mx<arr[i]){
            right[i]=0;
            mx=arr[i];
        }else{
            right[i]=mx;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int water_height=max(min(left[i],right[i]),arr[i])-arr[i];
        ans+=water_height;
    }
    cout<<ans<<"\n";
    cout<<"OPTIMIZED SOLUTION\n";
    optimized_solution(arr,n);
}