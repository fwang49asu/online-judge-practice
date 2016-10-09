public class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        for(int i=0; i<k; ++i) {
            minHeap.offer(nums[i]);
        }
        for(int i=k; i<nums.length; ++i) {
            minHeap.offer(nums[i]);
            minHeap.poll();
        }
        return minHeap.peek();
    }
}
