public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int result = m;
        int diff = n - m;
        if(m == 0 || diff == 0) {
            return m;
        }
        int mask = 1;
        for(; result >= mask && diff > 0; result &= (~mask), mask <<= 1, diff >>=1);
        result &= n;
        return result;
    }
}
