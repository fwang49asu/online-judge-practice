public class Solution {
    public Solution() {
        super();
        primeCacheList = new ArrayList<>();
    }

    public int countPrimes(int n) {
        if(n <= 2) {
            return 0;
        }
        if(n == 3) {
            return 1;
        }
        int result = 1;
        for(int i=3; i<n; i+=2) {
            if(isPrime(i)) {
                ++result;
            }
        }
        return result;
    }
    private ArrayList<Integer> primeCacheList;
    private boolean isPrime(int n) {
        int half = (int)Math.sqrt(n);
        for(int i=0; i<primeCacheList.size() && primeCacheList.get(i) <= half; ++i) {
            if(n % primeCacheList.get(i) == 0) {
                return false;
            }
        }
        primeCacheList.add(n);
        return true;
    }
}
