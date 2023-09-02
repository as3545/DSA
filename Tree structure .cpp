#include<iostream>
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

int main(){
struct node* root = new node(1);
root-> left = new node(2);
root->left->left = new node(3);
root->left->right = new node(4);
root->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);

return 0;
}
