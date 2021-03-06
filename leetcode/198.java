public class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        if(nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int f1 = nums[0];
        int f2 = Math.max(nums[0], nums[1]);
        for(int i=2; i<nums.length; ++i) {
            int next = Math.max(f2, f1 + nums[i]);
            f1 = f2;
            f2 = next;
        }
        return f2;
    }
}
