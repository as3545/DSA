//Code

#include<iostream>
using namespace std;
struct Node{
    struct Node*left;
    struct Node*right;
    int d;
    Node(int val){
        left=NULL;
        right=NULL;
        d=val;
    }
};

int search(int inorder[],int start,int end,int curr){
 
    for(int i=start;i<=end;i++){
    if(inorder[i]==curr){
        return i;
        }
    }
    return -1;
}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->d<<" ";
    inorder(root->right);
}

void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->d<<" ";
    inorder(root->left);
    inorder(root->right);
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node*  node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);
    return node;
}
int main(){
    
    int p[]={1,2,4,3,5};
    int io[]={4,2,1,5,3};
    Node*root = buildTree(p,io,0,4);
    inorder(root);
    cout<<endl;
    preorder(root);
    return 0;
    
}
