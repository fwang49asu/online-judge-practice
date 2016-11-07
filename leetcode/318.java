public class Solution {
    public int maxProduct(String[] words) {
        if(words == null || words.length == 0) {
            return 0;
        }
        boolean hash[][] = new boolean[words.length][26];
        for(int i=0; i<words.length; ++i) {
            for(int k=0; k<words[i].length(); ++k) {
                hash[i][words[i].charAt(k) - 'a'] = true;
            }
        }
        int result = 0;
        for(int i=0; i<hash.length; ++i) {
            for(int k=i+1; k<hash.length; ++k) {
                if(accept(hash[i], hash[k])) {
                    result = Math.max(result, words[i].length() * words[k].length());
                }
            }
        }
        return result;
    }

    boolean accept(boolean[] a, boolean[] b) {
        int n = a.length;
        boolean result = true;
        for(int i=0; i<n && result; ++i) {
            result &= !(a[i] && b[i]);
        }
        return result;
    }
}
