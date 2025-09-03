/*
class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

import java.util.*;

class Solution {
    boolean isLeaf(Node root) {
        return root.left == null && root.right == null;
    }
    
    // Add left boundary nodes (excluding leaf)
    void addLeftBoundary(Node root, ArrayList<Integer> res) {
        Node curr = root.left;
        while (curr != null) {
            if (!isLeaf(curr)) {
                res.add(curr.data);
            }
            if (curr.left != null) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
    }
    
    // Add right boundary nodes (excluding leaf)
    void addRightBoundary(Node root, ArrayList<Integer> res) {
        Node curr = root.right;
        ArrayList<Integer> temp = new ArrayList<>();
        while (curr != null) {
            if (!isLeaf(curr)) {
                temp.add(curr.data);
            }
            if (curr.right != null) {
                curr = curr.right;
            } else {
                curr = curr.left;
            }
        }
        // reverse before adding
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.add(temp.get(i));
        }
    }

    // Add all leaf nodes
    void addLeaves(Node root, ArrayList<Integer> res) {
        if (isLeaf(root)) {
            res.add(root.data);
            return;
        }
        if (root.left != null) {
            addLeaves(root.left, res);
        }
        if (root.right != null) {
            addLeaves(root.right, res);
        }
    }
    
    ArrayList<Integer> boundaryTraversal(Node node) {
        ArrayList<Integer> res = new ArrayList<>();
        
        if (node == null) return res;
        
        if (!isLeaf(node)) {
            res.add(node.data);
        }
        
        addLeftBoundary(node, res);
        addLeaves(node, res);
        addRightBoundary(node, res);

        return res;
    }
}
