#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int d):left(NULL),right(NULL),data(d){

    }
};

struct Node2{
    Node* root;
    int distance;

    Node2(Node* root,int d):root(root),distance(d){

    }
};

int min_horizontal_distance(Node* root,int d){
    if(root==NULL){
        return d;
    }
    int left=min_horizontal_distance(root->left,d-1);
    int right=min_horizontal_distance(root->right,d+1);
    return min(left,right);
}

int max_horizontal_distance(Node* root,int d){
    if(root==NULL){
        return d;
    }
    int left=max_horizontal_distance(root->left,d-1);
    int right=max_horizontal_distance(root->right,d+1);
    return max(left,right);
}

void print_vertically(Node* root){
    int mn=min_horizontal_distance(root,0);
    int mx=max_horizontal_distance(root,0);
    vector<int> arr[mx-mn];

    queue<Node2> q;
    q.push(Node2(root,0));
    while(!q.empty()){
        Node2 temp=q.front();
        q.pop();
        arr[temp.distance-mn].push_back(temp.root->data);
        if(temp.root->left!=NULL){
            q.push(Node2(temp.root->left,temp.distance-1));
        }
        if(temp.root->right!=NULL){
            q.push(Node2(temp.root->right,temp.distance+1));
        }
    }
    for(int i=0;i<mx-mn;i++){
        if(arr[i].size()>0){
            cout<<"DISTANCE "<<i+mn<<"\n";
            for(vector<int>::iterator it=arr[i].begin();it!=arr[i].end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
        }
    }   
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->left->right=new Node(8);
    root->right->right=new Node(7);
    root->right->right->right=new Node(9);
    print_vertically(root);
}