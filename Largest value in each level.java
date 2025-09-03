// User function Template for Java

class Solution {
    public ArrayList<Integer> largestValues(Node root) {
        // code here
        ArrayList<Integer>result=new ArrayList<>();
        if(root==null ) return result;
        
        Queue<Node>q=new LinkedList<>();
        q.add(root);
        
        
        while(!q.isEmpty())
        {
            int size=q.size();
            int maxVal=Integer.MIN_VALUE;
            for(int i=0;i<size;i++)
            {
                Node curr=q.poll();
                maxVal=Math.max(maxVal,curr.data);
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
            result.add(maxVal);
        }
        return result;
    }
}
