public class NumArray {

    public NumArray(int[] nums) {
        data = Arrays.copyOf(nums, nums.length);
        binaryIndexTree = new int[nums.length+1];
        for(int i=1; i<=nums.length; ++i) {
            binaryIndexTree[i] = nums[i-1];
            int lower = i - lowbit(i);
            for(int k=i-1; k > lower; --k) {
                binaryIndexTree[i] += nums[k-1];
            }
        }
    }

    public void update(int i, int val) {
        int delta = val - data[i];
        data[i] = val;
        for(int k=i+1; k<=data.length; k+=lowbit(k)) {
            binaryIndexTree[k] += delta;
        }
    }

    public int sumRange(int i, int j) {
        return prefixSum(j+1) - prefixSum(i);
    }

    public int prefixSum(int k) {
        int sum = 0;
        for(; k>0; k -= lowbit(k)) {
            sum += binaryIndexTree[k];
        }
        return sum;
    }

    private int[] data;
    private int[] binaryIndexTree;
    private int lowbit(int x) {
        return x & (-x);
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
