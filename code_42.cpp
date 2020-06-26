#include<iostream>
using namespace std;
#define C 4
#define R 4

int findAns(int mat[][C],int k,int r,int c){
    if(r<=0 || c<=0){
        return -1;
    }

    if(k<=c){
        return mat[0][k-1];
    }else if(k<= c+r-1){
        return mat[k-c][c-1];
    }else if(k<= c+r-1+c-1){
        return mat[r-1][c-1-(k-(c+r-1))];
    }else if(k<=c+r-1+c-1+r-2){
        return mat[r-1-(k-(c+r-1+c-1))][0];
    }else{
        return findAns((int (*)[C])(&mat[1][1]),k-2*r-2*c+4,r-2,c-2);
    }
}

int main(){
    int mat[][C] = {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    
    for(int i=0;i<R*C;i++){
        int ans=findAns(mat,i+1,R,C);
        cout<<ans<<" ";
    }
    cout<<"\n";
}