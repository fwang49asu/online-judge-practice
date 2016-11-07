public class Solution {
    public int maxProduct(String[] words) {
        if(words == null || words.length == 0) {
            return 0;
        }
        int hash[] = new int[words.length];
        for(int i=0; i<words.length; ++i) {
            hash[i] = encode(words[i]);
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

    int encode(String word) {
        int hash = 0;
        for(int i=0; i<word.length(); ++i) {
            hash |= 1 << (word.charAt(i) - 'a');
        }
        return hash;
    }

    boolean accept(int a, int b) {
        return (a & b) == 0;
    }
}
