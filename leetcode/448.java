public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> result = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            result.add(i+1);
        }
        for(int x: nums) {
            result.set(x-1, -x);
        }
        for(int i=n-1; i>=0; --i) {
            if(result.get(i) < 0) {
                // move to the last and remove
                int t = result.size() - 1;
                result.set(i, result.get(t));
                result.remove(t);
            }
        }
        return result;
    }
}
