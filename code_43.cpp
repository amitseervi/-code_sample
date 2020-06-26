#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d):data(d){
        left=NULL;
        right=NULL;
    }
};

void left_view_util(Node* root,int level,int* max_level){
    if(root==NULL){
        return;
    }
    if(level>*max_level){
        *max_level=level;
        cout<<root->data<<"\n";
    }
    left_view_util(root->left,level+1,max_level);
    left_view_util(root->right,level+1,max_level);
}

int main(){
    Node* root = new Node(12); 
    root->left = new Node(10); 
    root->right = new Node(30); 
    root->right->left = new Node(25); 
    root->right->right = new Node(40); 
    int mxlevel=0;
    left_view_util(root,1,&mxlevel);
}