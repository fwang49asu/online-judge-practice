public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        ArrayList<Integer> buffer = new ArrayList<>();
        combinationSum3Helper(k, 1, 9, n, buffer, result);
        return result;
    }

    private void combinationSum3Helper(int k, int low, int high, int target, ArrayList<Integer> buffer, List<List<Integer>> result) {
        if(target < 0) {
            return;
        }
        if(k == 0) {
            if(target == 0) {
                ArrayList<Integer> list = new ArrayList<>();
                list.addAll(buffer);
                result.add(list);
            }
            return;
        }
        for(int i=low; i<=high; ++i) {
            buffer.add(i);
            combinationSum3Helper(k-1, i+1, high, target - i, buffer, result);
            buffer.remove(buffer.size() - 1);
        }
    }
}
