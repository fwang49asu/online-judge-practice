public class Solution {
    public boolean canPartition(int[] nums) {
        if(nums.length < 2) {
            return false;
        }
        int sum = 0;
        for(int x: nums) {
            sum += x;
        }
        if((sum & 1) == 1) {
            return false;
        }
        Arrays.sort(nums);
        int half = nums.length >> 1;
        for(int i=0; i<half; ++i) {
            int temp = nums[i];
            nums[i] = nums[nums.length - i - 1];
            nums[nums.length - i - 1] = temp;
        }
        sum >>= 1;
        return canFill(0, sum, nums);
    }

    private boolean canFill(int index, int target, int[] nums) {
        if(index == nums.length) {
            return false;
        }
        if(target == 0) {
            return true;
        }
        for(int i=index; i<nums.length && target >= nums[i]; ++i) {
            if(canFill(i+1, target - nums[i], nums)) {
                return true;
            }
        }
        return false;
    }
}
