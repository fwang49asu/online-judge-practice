public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        for(; high < nums.length && sum < s; ++high) {
            sum += nums[high];
        }
        if(sum < s) {
            return 0;
        }
        // shrink
        for(; sum >= s; ++low) {
            sum -= nums[low];
        }
        --low;
        sum += nums[low];
        for(; high < nums.length; ++high) {
            sum = sum - nums[low] + nums[high];
            ++low;
            if(sum >= s) {
                for(; sum >= s; ++low) {
                    sum -= nums[low];
                }
                --low;
                sum += nums[low];
            }
        }
        return high - low;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int array[] = {2,3,1,2,4,3};
        System.out.println(s.minSubArrayLen(7, array));
    }
}
