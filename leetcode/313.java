public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int result[] = new int[n];
        int index[] = new int[primes.length];
        result[0] = 1;
        for(int i=1; i<n; ++i) {
            result[i] = Integer.MAX_VALUE;
            for(int k=0; k<primes.length; ++k) {
                result[i] = Math.min(result[i], result[index[k]] * primes[k]);
            }
            for(int k=0; k<primes.length; ++k) {
                while(result[index[k]] * primes[k] <= result[i]) {
                    ++index[k];
                }
            }
        }
        return result[n-1];
    }
}
