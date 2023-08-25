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

void inorderprint(Node*root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->d<<" ";
    inorderprint(root->right);
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
    
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node*root = buildTree(preorder,inorder,0,4);
    inorderprint(root);
    return 0;
    
}
