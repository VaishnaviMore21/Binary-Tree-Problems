/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int find(int in[],int target,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==target)
            {
                return i;
            }
            
        }
        return -1;
    }
    
    Node* Tree(int in[],int pre[],int Instart,int InEnd,int index)
    {
        if(Instart>InEnd)
         return NULL;
         
         Node *root=new Node(pre[index]);
         int pos=find(in,pre[index],Instart,InEnd);
         root->left=Tree(in,pre,Instart,pos-1,index+1);
         root->right=Tree(in,pre,pos+1,InEnd,index+(pos-Instart)+1);
         return root;
         
         
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return Tree(in,pre,0,n-1,0);
    }
};
