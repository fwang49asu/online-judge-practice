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
        int a = robLinear(nums, 0, nums.length-2);
        int b = robLinear(nums, 1, nums.length-1);
        return Math.max(a, b);
    }

    private int robLinear(int[] nums, int low, int high) {
        int f1 = nums[low];
        int f2 = Math.max(nums[low], nums[low+1]);
        for(int i=low+2; i<=high; ++i) {
            int next = Math.max(f2, f1 + nums[i]);
            f1 = f2;
            f2 = next;
        }
        return f2;
    }
}
