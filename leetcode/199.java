public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        if(root == null) {
            return result;
        }
        ArrayList<TreeNode> cur = new ArrayList<>();
        ArrayList<TreeNode> next = new ArrayList<>();
        cur.add(root);
        while(cur.size() > 0) {
            result.add(cur.get(cur.size()-1).val);
            for(TreeNode node : cur) {
                if(node.left != null) {
                    next.add(node.left);
                }
                if(node.right != null) {
                    next.add(node.right);
                }
            }
            ArrayList<TreeNode> temp = cur;
            cur = next;
            next = temp;
            next.clear();
        }
        return result;
    }
}
