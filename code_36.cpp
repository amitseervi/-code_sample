#include<queue>
#include<stack>
#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int data):data(data){
        next=NULL;
    }
};

Node* createLLfromArr(int arr[],int n){
    Node* root=new Node(arr[0]);
    Node* current=root;
    for(int i=1;i<n;i++){
        current->next=new Node(arr[i]);
        current=current->next;
    }
    return root;
}

void modifyContent(Node* root){
    stack<Node*> s;
    Node* current=root;
    Node* current2=root->next;
    bool oddLength=false;
    while(current!=NULL && current2!=NULL){
        if(current2->next!=NULL && current2->next->next==NULL){
            oddLength=true;
        }
        s.push(current);
        current=current->next;
        current2 = (current2->next==NULL)?NULL:(current2->next->next);
    }
    Node* current3=s.top()->next;
    if(oddLength){
        current3=current3->next;
    }
    while(!s.empty()){
        Node* c=s.top();
        s.pop();
        c->data = (c->data)-(current3->data);
        current3=current3->next;
    }
}

void printLL(Node* root){
    Node* current=root;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

int main(){
    int llarr[]={2,9,8,12,7,10};
    int n=sizeof(llarr)/sizeof(llarr[0]);
    Node* root=createLLfromArr(llarr,n);
    modifyContent(root);
    printLL(root);
}