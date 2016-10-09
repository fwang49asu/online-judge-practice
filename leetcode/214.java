public class Solution {
    public String shortestPalindrome(String s) {
        if(s.length() <= 1) {
            return s;
        }
        // find the longest palindrome prefix
        int high = s.length() - 1;
        for(; high > 0 && !isPalindrome(s, 0, high); --high);
        String result = new StringBuilder(s.substring(high+1, s.length())).reverse().toString();
        return result + s;
    }

    boolean isPalindrome(String s, int low, int high) {
        for(; low < high; ++low, --high) {
            if(s.charAt(low) != s.charAt(high)) {
                return false;
            }
        }
        return true;
    }
}
