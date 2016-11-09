public class Solution {
    public int minPatches(int[] nums, int n) {
        int result = 0;
        int index = 0;
        int curTest = 1;
        while(curTest <= n && curTest > 0) {
            if(index < nums.length && nums[index] <= curTest) {
                curTest += nums[index];
                ++index;
            } else {
                curTest <<= 1;
                ++result;
            }
        }
        return result;
    }
}
