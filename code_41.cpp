#include<iostream>
#include<stack>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int d):data(d){
        left=NULL;
        right=NULL;
    }
};

void print_common_nodes(Node* b1,Node* b2){
    //Iterative level order traversal

    stack<Node*> s1,s2;
    while(true){
        if(b1!=NULL){
            s1.push(b1);
            b1=b1->left;
        }else if(b2!=NULL){
            s2.push(b2);
            b2=b2->left;
        }else if(!s1.empty() && !s2.empty()){
            b1=s1.top();
            b2=s2.top();
            if(b1->data == b2->data){
                cout<<b1->data<<" ";
                s1.pop();
                s2.pop();
                b1=b1->right;
                b2=b2->right;
            }else if(b1->data<b2->data){
                s1.pop();
                b1=b1->right;
                b2=NULL;
            }else{
                s2.pop();
                b2=b2->right;
                b1=NULL;
            }
        }else{
            break;
        }
    }
    cout<<"\n";
}

int main(){
    /*
    This problem can be done with storing inorder traversal of both bst tree.
    */
    Node* bst1=new Node(5);
    bst1->left=new Node(1);
    bst1->left->left=new Node(0);
    bst1->left->right=new Node(4);
    bst1->right=new Node(10);
    bst1->right->left=new Node(7);
    bst1->right->left->right=new Node(9);

    Node* bst2=new Node(10);
    bst2->left=new Node(7);
    bst2->left->left=new Node(4);
    bst2->left->right=new Node(9);
    bst2->right=new Node(20);

    print_common_nodes(bst1,bst2);
}