/
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
 void lview(Node *root,int level,vector<int>&ans)
 {
     if(!root)
   {
       return ;
   }
   if(level==ans.size())
   {
       ans.push_back(root->data);
   }
   lview(root->left,level+1,ans);
   lview(root->right,level+1,ans);
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>ans;
   // Your code here
   if(!root)
   {
       return ans;
   }
  lview(root,0,ans);
  return ans;
}
