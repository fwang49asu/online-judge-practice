public class Solution {
    public int numSquares(int n) {
        // backpack problem. use dp
        int upper = (int)Math.sqrt(n);
        ArrayList<Integer> packs = new ArrayList<>();
        for(int i=1; i<= upper; ++i) {
            packs.add(i*i);
        }
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; ++i) {
            int result = n;
            for(int k=0; k<packs.size() && packs.get(k) <= i; ++k) {
                int t = dp[i - packs.get(k)] + 1;
                result = Math.min(result, t);
            }
            dp[i] = result;
        }
        return dp[n];
    }
}
