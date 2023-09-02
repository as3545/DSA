//Code

#include<iostream>
#include<queue>
using namespace std;
struct node{
struct node* left;
struct node* right;
int data;

node(int val){
left=NULL;
right=NULL;
data=val;
}

};

int count(node* root){
    if(root==NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}


int main(){
node* root = new node(1);
root-> left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);
cout<<count(root);
return 0;
}
