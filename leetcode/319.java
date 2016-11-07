public class Solution {
    public int bulbSwitch(int n) {
        if(n <= 1) {
            return n;
        }
        int result = 1;
        for(; result*result <=n; ++result);
        return result - 1;
    }
}
