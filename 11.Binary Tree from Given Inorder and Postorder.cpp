class Solution {
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
    
    Node* Tree(int in[],int post[],int Instart,int InEnd,int index)
    {
        if(Instart>InEnd)
         return NULL;
         
         Node *root=new Node(post[index]);
         int pos=find(in,post[index],Instart,InEnd);
         
         root->right=Tree(in,post,pos+1,InEnd,index-1);
         root->left=Tree(in,post,Instart,pos-1,index-(InEnd-pos)-1);
         return root;
         
         
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        Tree(in,post,0,n-1,n-1);
    }
