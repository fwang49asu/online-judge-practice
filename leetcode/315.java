public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>(nums.length);
        if(nums == null || nums.length == 0) {
            return result;
        }
        for(int i=0; i<nums.length; ++i) {
            result.add(0);
        }
        BSTNode root = new BSTNode(nums[nums.length - 1]);
        for(int i=nums.length - 2; i>=0; --i) {
            result.set(i, countLess(root, nums[i]));
            addValue(root, nums[i]);
        }
        return result;
    }

    private int countLess(BSTNode root, int x) {
        if(root == null) {
            return 0;
        }
        if(root.val == x) {
            return root.left == null ? 0 : root.left.count;
        }
        if(x < root.val) {
            return countLess(root.left, x);
        }
        if(root.right == null) {
            return root.count;
        }
        int max = root.val;
        BSTNode cur = root;
        while(cur != null) {
            max = cur.val;
            cur = cur.right;
        }
        if(x > max) {
            return root.count;
        }
        cur = root.right;
        int min = root.right.val;
        while(cur != null) {
            min = cur.val;
            cur = cur.left;
        }
        int result = root.left == null ? 0 : root.left.count;
        result += root.countOnNode;
        if(min > x) {
            return result;
        }
        return result + countLess(root.right, x);
    }

    private void addValue(BSTNode root, int x) {
        ++root.count;
        if(root.val == x) {
            ++root.countOnNode;
            return;
        }
        if(x < root.val) {
            if(root.left == null) {
                root.left = new BSTNode(x);
                return;
            }
            addValue(root.left, x);
            return;
        }
        if(root.right == null) {
            root.right = new BSTNode(x);
            return;
        }
        addValue(root.right, x);
    }

    private class BSTNode {
        public int count;
        public int countOnNode;
        public int val;
        public BSTNode left;
        public BSTNode right;

        public BSTNode(int x) {
            count = 1;
            countOnNode = 1;
            val = x;
            left = null;
            right = null;
        }
    }
}
