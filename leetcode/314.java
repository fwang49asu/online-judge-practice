/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;

public class Solution {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(root == null) {
            return result;
        }
        TreeMap<Integer, List<Integer>> resultMap = new TreeMap<Integer, List<Integer>>();
        ArrayList<SimpleEntry<Integer, TreeNode>> cur = new ArrayList<SimpleEntry<Integer, TreeNode>>();
        cur.add(new SimpleEntry<>(0, root));
        while(!cur.isEmpty()) {
            ArrayList<SimpleEntry<Integer, TreeNode>> next = new ArrayList<SimpleEntry<Integer, TreeNode>>();
            for(SimpleEntry<Integer, TreeNode> entry: cur) {
                int pos = entry.getKey();
                TreeNode node = entry.getValue();
                if(!resultMap.containsKey(pos)) {
                    List<Integer> list = new ArrayList<>();
                    resultMap.put(pos, list);
                }
                resultMap.get(pos).add(node.val);
                if(node.left != null) {
                    next.add(new SimpleEntry<>(pos-1, node.left));
                }
                if(node.right != null) {
                    next.add(new SimpleEntry<>(pos+1, node.right));
                }
            }
            cur = next;
        }
        for(HashMap.Entry<Integer, List<Integer>> entry: resultMap.entrySet()) {
            result.add(entry.getValue());
        }
        return result;
    }
}
