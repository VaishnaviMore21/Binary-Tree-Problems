// Should return  right view of tree
class Solution
{
     void rview(Node *root,int level,vector<int>&ans)
 {
     if(!root)
   {
       return ;
   }
   if(level==ans.size())
   {
       ans.push_back(root->data);
   }
   rview(root->right,level+1,ans);
   rview(root->left,level+1,ans);
 }

    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
          vector<int>ans;
   // Your code here
   if(!root)
   {
       return ans;
   }
  rview(root,0,ans);
  return ans;
    }
};
