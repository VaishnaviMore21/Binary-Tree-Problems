/*complete the given function*/

/* class Node{
    int data;
    Node left,right;
    Node(int d)
    {
        data=d;
        left=null;
        right=null;
    }
}*/

class Solution {
    public static boolean areIdentical(Node root1,Node root2)
    {
    if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
         return (root1.data == root2.data)
            && areIdentical(root1.left, root2.left)
            && areIdentical(root1.right, root2.right);
        
    }
    public static boolean isSubtree(Node T, Node S) {
        // add code here.
        if(S==null)return true;
        if(T==null)return false;
        if(areIdentical(T,S))return true;
        return isSubtree(T.left, S) || isSubtree(T.right, S);
    }
}
