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

void right_view_util(Node* root,int level,int* max_level){
    if(root==NULL){
        return;
    }
    if(level>*max_level){
        *max_level=level;
        cout<<root->data<<"\n";
    }
    right_view_util(root->right,level+1,max_level);
    right_view_util(root->left,level+1,max_level);
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    int mxlevel=0;
    right_view_util(root,1,&mxlevel);
}