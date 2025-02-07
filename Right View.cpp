
class Solution {
public:


void rightViewHelper(TreeNode* node, int level, vector<int>& res)
{
    if(!node)
    {
        return;
    }
    if(level==res.size())
    {
        res.push_back(node->val);
    }
    rightViewHelper(node->right,level+1,res);
    rightViewHelper(node->left,level+1,res);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
     rightViewHelper(root,0,res);
     return res;
    }
};
