/*
no link
Google-hard
problem statement : An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

XOR of two node address can be done by using "uintptr_t"
uintptr_t is an unsigned integer type capable of holding a pointer.
=> Reason:
        A common reason to want an integer type that can hold an architecture's pointer type
        is to perform integer-specific operations on a pointer,or to obscure the type of a
        pointer by providing it as an integer "handle".

*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct node{
  ll val;
  node* both;
}Node;
Node *cur=NULL,*root=NULL;
void add(int ele){
  Node* nn=new Node;
  nn->val=ele;
  nn->both=NULL;
  if(root==NULL){
    root=nn;
    cur=root;
  }
  else{
    cur->both=(Node*)((uintptr_t)cur->both ^(uintptr_t)nn);
    nn->both=cur;
    cur=nn;
  }
}
Node* get(int idx){
  Node* temp=root,*prev=NULL;
  int i=1;
  while(temp!=NULL && i<idx){
    prev=(Node*)((uintptr_t)temp->both ^ (uintptr_t)prev);
    Node* x=temp;
    temp=prev;
    prev=x;
    i++;
  }
  return temp;
}
void traversal(Node* t){
  Node* temp=t,*prev=NULL;
  while(temp!=NULL){
    prev = (Node*)((uintptr_t)temp->both ^ (uintptr_t)prev);
    cout<<temp->val<<":";
    Node* x=temp;
    temp=prev;
    prev=x;
  }cout<<"\n";
}
int main(){
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    add(x);
  }
  traversal(root);
  Node* res=get(3);
  cout<<res->val<<"\n";
  return 0;
}