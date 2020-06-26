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

void printLL(Node* root){
    Node* current=root;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

Node* trimZerosFromFront(Node* list){
    while(list->next!=NULL&&list->data==0){
        list=list->next;
    }
    return list;
}

Node* reverseLL(Node* root){
    if(root->next==NULL){
        root->next=NULL;
        return root;
    }
    Node* parent=root->next;
    Node* newRoot=reverseLL(root->next);
    parent->next=root;
    root->next=NULL;
    return newRoot;
}

Node* multiplyLL(Node* l1,Node* l2){
    Node *newL1=reverseLL(l1);
    Node *newL2=reverseLL(l2);
    Node *result=new Node(0);
    //newL1 x newL2
    Node *c1=newL1;
    Node *c2=newL2;
    Node *c3=result;
    while(c2!=NULL){
        Node *resultCursor=c3;
        int carry=0;
        c1=newL1;
        while(c1!=NULL){
            int mm=(c1->data * c2->data)+carry + resultCursor->data;
            carry=mm/10;
            resultCursor->data = mm%10;
            if(resultCursor->next==NULL){
                resultCursor->next=new Node(0);
            }
            resultCursor=resultCursor->next;
            c1=c1->next;
        }
        while(carry>0){
            int mm=carry + resultCursor->data;
            carry=mm/10;
            resultCursor->data = mm%10;
            if(resultCursor->next==NULL){
                resultCursor->next=new Node(0);
            }
            resultCursor=resultCursor->next;
        }
        if(c3->next==NULL){
            c3->next=new Node(0);
        }
        c3=c3->next;
        c2=c2->next;
    }
    return trimZerosFromFront(reverseLL(result));
}

int main(){
    int arr1[]={3,2,1};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    Node* l1=createLLfromArr(arr1,n1);

    int arr2[]={1,2};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    Node* l2=createLLfromArr(arr2,n2);

    Node* result=multiplyLL(l1,l2);
    printLL(result);
    
}