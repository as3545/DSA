//Code

void inorder(Node* node, vector<int>& ans){
    
     if(node==NULL)
   {
       return;
   }
     
      inorder(node->left,ans);
      ans.push_back(node->data);
      inorder(node->right,ans);
}

int getSize(Node* node)
{
   // Your code here
   vector<int> ans;
   inorder(node,ans);
   int res=ans.size();
   return res;
   
}
