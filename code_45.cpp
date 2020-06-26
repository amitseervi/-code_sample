#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int data;

    Node(int d):data(d){
        next=NULL;
    }
};

void printLL(Node* root){
    Node* current=root;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

int main(){
    Node* root=new Node(1);
    root->next=new Node(2);
    root->next->next=new Node(3);
    root->next->next->next=new Node(4);
    root->next->next->next->next=new Node(5);
    root->next->next->next->next->next=new Node(6);
    root->next->next->next->next->next->next=new Node(7);
    
    Node* odd=root;
    Node* even=root->next;
    Node* current=(root->next==NULL)?NULL:(root->next->next);
    Node* startOfEven=even;
    while(current!=NULL){
        Node* nextOdd=current;
        Node* nextEven=current->next;
        Node* nextCurrent =(current->next==NULL)?NULL:(current->next->next);
        odd->next=nextOdd;
        nextOdd->next=startOfEven;
        odd=odd->next;

        even->next=nextEven;
        if(nextEven!=NULL){
            nextEven->next=NULL;
        }
        even=even->next;
        current=nextCurrent;
    }

    printLL(root);
}