/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "";
        }
        ArrayList<TreeNode> list = new ArrayList<>();
        int start = 0;
        list.add(root);
        while(start < list.size()) {
            int n = list.size();
            for(int i=start; i<n; ++i) {
                TreeNode p = list.get(i);
                if(p != null) {
                    list.add(p.left);
                    list.add(p.right);
                }
            }
            start = n;
        }
        return listToString(list);
    }

    private String listToString(ArrayList<TreeNode> list) {
        StringBuilder builder = new StringBuilder();
        int last = list.size()-1;
        for(; last >= 0 && list.get(last) == null; --last);
        builder.append(list.get(0).val);
        for(int i=1; i<=last; ++i) {
            builder.append(",");
            if(list.get(i) == null) {
                builder.append("null");
            } else {
                builder.append(list.get(i).val);
            }
        }
        return builder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        int n = data.length();
        if(n == 0) {
            return null;
        }
        String[] strs = data.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(strs[0]));
        ArrayList<TreeNode> list = new ArrayList<>();
        list.add(root);
        int index = 1;
        n = strs.length;
        while(!list.isEmpty()) {
            ArrayList<TreeNode> next = new ArrayList<>();
            for(TreeNode p : list) {
                if(index == n) {
                    return root;
                }
                if(!strs[index].equals("null")) {
                    p.left = new TreeNode(Integer.parseInt(strs[index]));
                    next.add(p.left);
                }
                ++index;
                if(index == n) {
                    return root;
                }
                if(!strs[index].equals("null")) {
                    p.right = new TreeNode(Integer.parseInt(strs[index]));
                    next.add(p.right);
                }
                ++index;
            }
            list = next;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
