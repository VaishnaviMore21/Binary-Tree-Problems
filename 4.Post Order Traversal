class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        postorder(root);
        return ans;
    }
    List<Integer> ans= new ArrayList<>();
    public void postorder(TreeNode node){
        if(node==null){
            return;
        }
        postorder(node.left);
        postorder(node.right);
        ans.add(node.val);
    }
}
