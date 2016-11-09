public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int result[] = new int[n];
        if(a == 0) {
            if(b >= 0) {
                for(int i=0; i<n; ++i) {
                    result[i] = b * nums[i] + c;
                }
            } else {
                for(int i=0; i<n; ++i) {
                    result[n - 1 - i] = b * nums[i] + c;
                }
            }
            return result;
        }
        double center = -b / (double)(2*a);
        ArrayList<Integer> resultList = new ArrayList<>();

        int right = 0;
        for(; right < n && nums[right] < center; ++right);
        int left = right - 1;
        while(left >= 0 && right < n) {
            double leftDiff = Math.abs(nums[left] - center);
            double rightDiff = Math.abs(nums[right] - center);
            if(leftDiff <= rightDiff) {
                int x = nums[left];
                resultList.add(a * x * x + b * x + c);
                --left;
            } else {
                int x = nums[right];
                resultList.add(a * x * x + b * x + c);
                ++right;
            }
        }
        for(; left >= 0; --left) {
            int x = nums[left];
            resultList.add(a*x*x + b*x + c);
        }
        for(; right < n; ++right) {
            int x = nums[right];
            resultList.add(a*x*x + b*x + c);
        }
        if(a > 0) {
            for(int i=0; i<n; ++i) {
                result[i] = resultList.get(i);
            }
        } else {
            for(int i=0; i<n; ++i) {
                result[i] = resultList.get(n - i - 1);
            }
        }
        return result;
    }
}
